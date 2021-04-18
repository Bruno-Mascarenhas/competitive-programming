fn main() {
    let mut buffer1 = String::new();
    std::io::stdin().read_line(&mut buffer1).expect("Error");
    let arr1: Vec<&str> = buffer1.trim().split(" ").collect();

    let mut buffer2 = String::new();
    std::io::stdin().read_line(&mut buffer2).expect("Error");
    let arr2: Vec<&str> = buffer2.trim().split(" ").collect();

    println!("VALOR A PAGAR: R$ {:.2}", arr1[1].parse::<f64>().unwrap() * arr1[2].parse::<f64>().unwrap() + arr2[1].parse::<f64>().unwrap() * arr2[2].parse::<f64>().unwrap());
}