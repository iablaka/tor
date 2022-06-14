use std::path::Path;
use std::fs;
use std::env;


const TOR_DIR: &str = "/.tor";
const PROVIDERS_DIR: &str = "/providers";

pub fn create_tor_folder(root_dir: &str) -> std::io::Result<()> {
    let mut path = String::from(root_dir);
    path.push_str(TOR_DIR);
    if Path::new(&path).is_dir() {
        fs::remove_dir_all(&path).unwrap();
    }
    fs::create_dir(&path)?;
    create_tor_contents(&path).expect("Could not create tor folder contents");
    Ok(())
}

fn create_tor_contents(tor_dir: &str) -> std::io::Result<()> {
    let mut path = String::from(tor_dir);
    path.push_str(PROVIDERS_DIR);
    if Path::new(&path).is_dir() {
        fs::remove_dir_all(&path).unwrap();
    }
    fs::create_dir(&path)?;
    path.push_str("/");
    path.push_str(env::consts::OS);
    path.push_str("_");
    path.push_str(env::consts::ARCH);    
    fs::create_dir(&path)?;
    Ok(())
}
