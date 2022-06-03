use std::env;
mod init;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args[1] == "init" {
        init::create_tor_folder();
    }
    //println!("{:?}", args);
}