fn get_input() -> f64 {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed");
    buffer.trim().parse::<f64>().unwrap()
}

fn main() {
    let _name = std::io::stdin().read_line(&mut String::new());
    let b = get_input();
    let c = get_input();

    println!("TOTAL = R${:.2}", b+c*0.15);
}