mod c32;

fn main() {
    println!(
        "{:?}",
        c32::c32(0b_01_11_0010_0000_0000_0000_0000_0000_0000)
    );
    // println!("{:?}", c32::from_rational(10, 1))
}
