fn get_input() -> f64 {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed");
    buffer.trim().parse::<f64>().unwrap()
}

fn main() {
    let x = get_input();
    let y = get_input();
    let z = get_input();
    println!("MEDIA = {:.1}", (x*2.0+y*3.0+z*5.0)/10.0);
}