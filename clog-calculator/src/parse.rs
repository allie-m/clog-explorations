// pi + 4
// a = 4.1294 / 2 - 5 * 4
// ((a^4 + 10)^(-1/2) + pi)
// .45 - (-10*pi/4-1)

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

pub enum Node {
    // one child
    Abs,
    Neg,
    Sqrt,

    Exp,
    Ln,
    // the rest of the trig stuff

    // two children
    Add,
    Sub,
    Mul,
    Div,
    Pow,
    Floor,
    Ceil,
    Round,
    Mod,
    Log, // (exp, base)

    // zero children
    Variable { name: String },
    Decimal { word: u32, offset: u8 },
    Constant { kind: Constant },
}

pub enum Constant {
    Pi,
    Tau,
    E,
    Phi,
}

#[derive(Debug)]
pub enum Token {
    LParen,
    RParen,
    Comma,
    Abs,
    Plus,
    Minus,
    Mul,
    Div,
    Mod,
    Pow,

    Name(String),
    Decimal { numbers: Vec<u32>, pt_index: u32 },
}

#[derive(Clone, Copy, Debug)]
pub enum TokenizeExprError {
    #[allow(unused)]
    UnknownChar(char),
    InvalidDecimal, // decimals can't have non-numeric/'.' characters in them
    InvalidName,    // names can't have numbers or '.' in them
    MultipleDecimalPoints,
    EmptyDecimal, // '.' is not a valid number
}

pub fn tokenize_expression(expr: &str) -> Result<Vec<Token>, TokenizeExprError> {
    let mut iter: Box<dyn Iterator<Item = char>> = Box::new(expr.trim().chars());
    let mut tokens = vec![];
    loop {
        let c = match iter.next() {
            Some(c) => c,
            None => break,
        };
        let token = match c {
            '(' => Token::LParen,
            ')' => Token::RParen,
            '|' => Token::Abs,
            '+' => Token::Plus,
            '-' => Token::Minus,
            '*' => Token::Mul,
            '/' => Token::Div,
            '%' => Token::Mod,
            '^' => Token::Pow,
            ',' => Token::Comma,
            ' ' | '\n' | '\t' => continue,
            c => {
                // must be a name or decimal
                enum Kind {
                    Name(String),
                    Decimal {
                        numbers: Vec<u32>,
                        pt_index: Option<u32>,
                    },
                }
                let mut kind = if c == '.' || c.is_numeric() {
                    Kind::Decimal {
                        numbers: vec![],
                        pt_index: None,
                    }
                } else {
                    Kind::Name(String::new())
                };
                let mut i = 0;
                iter = Box::new(Some(c).into_iter().chain(iter));
                while let Some(c) = iter.next() {
                    match c {
                        '(' | ')' | '|' | '+' | '-' | '*' | '/' | '%' | '^' | ',' | ' ' | '\n'
                        | '\t' => {
                            iter = Box::new(Some(c).into_iter().chain(iter));
                            break;
                        }
                        '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' | '.' => {
                            match &mut kind {
                                Kind::Decimal { numbers, pt_index } => {
                                    if c == '.' {
                                        match pt_index {
                                            Some(_) => {
                                                return Err(
                                                    TokenizeExprError::MultipleDecimalPoints,
                                                )
                                            }
                                            None => *pt_index = Some(i),
                                        }
                                    } else {
                                        numbers.push(c.to_digit(10).unwrap())
                                    }
                                }
                                _ => return Err(TokenizeExprError::InvalidName),
                            }
                        }
                        c => {
                            if c.is_alphabetic() {
                                match &mut kind {
                                    Kind::Name(n) => n.push(c),
                                    _ => return Err(TokenizeExprError::InvalidDecimal),
                                }
                            } else {
                                return Err(TokenizeExprError::UnknownChar(c));
                            }
                        }
                    }
                    i += 1;
                }
                match kind {
                    Kind::Name(name) => Token::Name(name),
                    Kind::Decimal { numbers, pt_index } => {
                        if numbers.len() == 0 {
                            return Err(TokenizeExprError::EmptyDecimal);
                        }
                        Token::Decimal {
                            numbers: numbers.clone(),
                            pt_index: pt_index.unwrap_or(numbers.len() as u32),
                        }
                    }
                }
            }
        };
        tokens.push(token);
    }
    Ok(tokens)
}
