fn get_input() -> f64 {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed");
    buffer.trim().parse::<f64>().unwrap()
}

fn main() {
    let r = get_input();
    println!("A={:.4}", 3.14159f64*r*r);
}