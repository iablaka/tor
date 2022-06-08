use std::path::Path;
use std::fs;

pub fn create_tor_folder(root_dir: &str) -> std::io::Result<()> {
    let mut path = String::from(root_dir);
    path.push_str("/.tor");
    if Path::new(&path).is_dir() {
        fs::remove_dir_all(&path).unwrap();
    }
    // let mut providers_dir: String = path;
    // providers_dir.push_str("/providers");
    fs::create_dir(path)?;
    // fs::create_dir(providers_dir);
    Ok(())
}