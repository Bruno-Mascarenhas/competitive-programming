fn get_input() -> f64 {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed");
    buffer.trim().parse::<f64>().unwrap()
}

fn main() {
    let x = get_input();
    let y = get_input();
    println!("MEDIA = {:.5}", (x*3.5)/11f64 + (y*7.5)/11f64);
}