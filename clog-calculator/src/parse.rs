// NEVERMIND
// WE'RE USING A STACK MODEL
// 4 5 pi + - 74 /
//
// /*pi + 4
// a = 4.1294 / 2 - 5 * 4
// ((a^4 + 10)^(-1/2) + pi)
// .45 - (-10*pi/4-1)*/
//
// we unravel the input expression
// into a DAG
// which we convert easily into a clog DAG
// and evaluate out

// mode:
// - radix [base] [# of digits]
// - scientific notation [base] [# of digits]
// - continued fraction [# of input terms]
// - continued logarithms [speculative?]
// - rational intervals [base] [threshold] [max iters]

// [name] = [expression]
// eval [output mode [parameters]] [expression]

// yields [E (exact) or T (truncated)] [output]

use std::str::FromStr;

use num_bigint::BigUint;

#[derive(Debug)]
pub enum Node {
    OneChild(OneChild, Box<Node>),
    TwoChildren(TwoChildren, Box<Node>, Box<Node>),
    // zero children
    Decimal { word: BigUint, pow: u16 }, // val = word * 10^(-pow)
    Constant { kind: Constant },
    Variable { name: String },
}

#[derive(Clone, Copy, Debug)]
pub enum OneChild {
    Abs,
    Sqrt,
    Exp,
    Ln,
}

#[derive(Clone, Copy, Debug)]
pub enum TwoChildren {
    Add,
    Sub,
    Mul,
    Div,
    Floor,
    Ceil,
    Round,
    Mod,
    Pow, // (base, exp)
    Log, // (base, exp)
    Compare,
}

#[derive(Clone, Copy, Debug)]
pub enum Constant {
    Pi,
    Tau,
    E,
    Phi,
}

#[derive(Clone, Debug)]
pub enum RollExprError {
    #[allow(unused)]
    InvalidToken(String),
    InvalidDecimal,
    InvalidName,
    EmptyStack,
}

// as written, this is EXTREMELY BAREBONES
// it ONLY DOES BASIC ARITHMETIC
pub fn node_to_clog_stream(
    node: Box<Node>,
    speculative: bool,
) -> Result<Box<dyn crate::clog::Stream>, ()> {
    use crate::clog::*;
    Ok(match *node {
        Node::Constant { kind } => match kind {
            Constant::Tau => todo!(),
            Constant::E => Box::new(cfrac_to_clog(
                {
                    let mut i = -1;
                    std::iter::from_fn(move || {
                        i += 1;
                        if i == 0 {
                            Some(2)
                        } else if i % 3 == 2 {
                            Some(2 + 2 * (i / 3))
                        } else {
                            Some(1)
                        }
                    })
                },
                [1.into(), 0.into(), 0.into(), 1.into()],
            )),
            _ => Err(())?,
        },
        Node::Decimal { word, pow } => {
            Box::new(rational(word, BigUint::from(10u32).pow(pow as u32), 1))
        }
        Node::OneChild(kind, child) => match kind {
            // OneChild::Abs => Box::new(abs(node_to_clog_stream(child, speculative)?)),
            OneChild::Sqrt => Box::new(sqrt(node_to_clog_stream(child, speculative)?, speculative)),
            _ => Err(())?,
        },
        Node::TwoChildren(kind, c1, c2) => {
            let c1 = node_to_clog_stream(c1, speculative)?;
            let c2 = node_to_clog_stream(c2, speculative)?;
            Box::new(match kind {
                TwoChildren::Add => blfts(
                    c1,
                    c2,
                    [0, 1, 1, 0, 0, 0, 0, 1].map(|i| i.into()),
                    speculative,
                ),
                TwoChildren::Sub => blfts(
                    c1,
                    c2,
                    [0, 1, -1, 0, 0, 0, 0, 1].map(|i| i.into()),
                    speculative,
                ),
                TwoChildren::Mul => blfts(
                    c1,
                    c2,
                    [1, 0, 0, 0, 0, 0, 0, 1].map(|i| i.into()),
                    speculative,
                ),
                TwoChildren::Div => blfts(
                    c1,
                    c2,
                    [0, 1, 0, 0, 0, 0, 1, 0].map(|i| i.into()),
                    speculative,
                ),
                _ => Err(())?,
            })
        }
        Node::Variable { name: _ } => Err(())?,
    })
}

// rolls a stack expression into a DAG
// items leftover at the bottom of the stack are ignored
pub fn roll_stack_expression(expr: &str) -> Result<Box<Node>, RollExprError> {
    let mut stack = vec![];
    for token in expr.trim().split(" ") {
        let token = token.trim();
        if token.is_empty() {
            continue;
        }
        match token {
            // binary ops
            "+" | "-" | "*" | "/" | "%" | "^" | "log" | "floor" | "ceil" | "round" | "cmp" => {
                let t1 = stack.pop().ok_or(RollExprError::EmptyStack)?;
                let t2 = stack.pop().ok_or(RollExprError::EmptyStack)?;
                stack.push(Box::new(Node::TwoChildren(
                    match token {
                        "+" => TwoChildren::Add,
                        "-" => TwoChildren::Sub,
                        "*" => TwoChildren::Mul,
                        "/" => TwoChildren::Div,
                        "%" => TwoChildren::Mod,
                        "^" => TwoChildren::Pow,
                        "log" => TwoChildren::Log,
                        "floor" => TwoChildren::Floor,
                        "ceil" => TwoChildren::Ceil,
                        "round" => TwoChildren::Round,
                        "cmp" => TwoChildren::Compare,
                        _ => unreachable!(),
                    },
                    t1,
                    t2,
                )));
            }
            // unary ops
            "abs" | "sqrt" | "exp" | "ln" => {
                let top = stack.pop().ok_or(RollExprError::EmptyStack)?;
                stack.push(Box::new(Node::OneChild(
                    match token {
                        "abs" => OneChild::Abs,
                        "sqrt" => OneChild::Sqrt,
                        "exp" => OneChild::Exp,
                        "ln" => OneChild::Ln,
                        _ => unreachable!(),
                    },
                    top,
                )));
            }
            // constants
            "pi" | "tau" | "e" | "phi" => stack.push(Box::new(Node::Constant {
                kind: match token {
                    "pi" => Constant::Pi,
                    "tau" => Constant::Tau,
                    "e" => Constant::E,
                    "phi" => Constant::Phi,
                    _ => unreachable!(),
                },
            })),
            other => {
                if other.chars().all(|c| !c.is_alphanumeric() && c != '.') {
                    return Err(RollExprError::InvalidToken(token.to_owned()));
                }
                if other.chars().all(|c| c.is_numeric() || c == '.') {
                    // decimal
                    let points = other.chars().filter(|c| *c == '.').count();
                    if points > 1 || other.chars().count() == points {
                        return Err(RollExprError::InvalidDecimal);
                    }
                    let zero = !other.contains(|c| match c {
                        '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' => true,
                        _ => false,
                    });
                    if !zero {
                        let pow = other.len()
                            - other.find('.').unwrap_or(other.len())
                            - other.contains(".") as usize;
                        let pow = pow.try_into().expect("if your pow can't fit into a u16 then you need to reevaluate your life");
                        let word = other.chars().filter(|c| *c != '.').collect::<String>();
                        stack.push(Box::new(Node::Decimal {
                            word: BigUint::from_str(&word).unwrap(),
                            pow,
                        }));
                    } else {
                        stack.push(Box::new(Node::Decimal {
                            word: BigUint::ZERO,
                            pow: 0,
                        }))
                    }
                } else {
                    // name
                    if !other.contains(".") {
                        stack.push(Box::new(Node::Variable {
                            name: other.to_owned(),
                        }));
                    } else {
                        return Err(RollExprError::InvalidName);
                    }
                }
            }
        }
    }
    stack.pop().ok_or(RollExprError::EmptyStack)
}
