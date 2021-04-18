fn get_input() -> i64 {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed");
    buffer.trim().parse::<i64>().unwrap()
}

fn main() {
    let x = get_input();
    let y = get_input();
    println!("PROD = {}", x*y);
}