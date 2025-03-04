mod clog;
mod parse;

fn main() {
    // TODO this might be cool as a C program
    // to make a calculator for my operating system...
    let stdin = std::io::stdin();
    let mut buf = String::new();
    // we're just not gonna deal with io errors
    // they'll get sent to stderr, whatever
    while stdin.read_line(&mut buf).unwrap() > 0 {
        // write!(stdout, "{}", buf).unwrap();
        println!("{:?}", parse::roll_stack_expression(&buf));
        buf.clear();
    }
}
