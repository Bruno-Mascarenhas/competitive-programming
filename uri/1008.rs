fn get_input() -> f64 {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed");
    buffer.trim().parse::<f64>().unwrap()
}

fn main() {
    let a = get_input();
    let b = get_input();
    let c = get_input();

    println!("NUMBER = {}\nSALARY = U$ {:.2}", a as i64, b*c);
}