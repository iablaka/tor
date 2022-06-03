use std::path::Path;
use std::fs;

pub fn create_tor_folder() -> std::io::Result<()> {
    let path = "./.tor";
    if Path::new(path).is_dir() {
        fs::remove_dir_all(path).unwrap();
    }
    fs::create_dir("./.tor")?;
    Ok(())
}