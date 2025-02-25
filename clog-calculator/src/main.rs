use std::io::Write;

mod clog;
mod parse;

fn main() {
    // TODO this might be cool as a C program
    // to make a calculator for my operating system...
    let mut stdout = std::io::stdout();
    let stdin = std::io::stdin();
    let mut buf = String::new();
    // we're just not gonna deal with io errors
    // they'll get sent to stderr, whatever
    while stdin.read_line(&mut buf).unwrap() > 0 {
        // write!(stdout, "{}", buf).unwrap();
        println!("{:?}", parse::tokenize_expression(&buf));
    }
}
