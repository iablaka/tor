use std::env;
use std::process;

mod init;

fn print_usage() {
    let usage = concat!(
        "USAGE: tor command [options]\n",
        "command is mandatory and can be one of the following values:\n",
        " - init, to set your environment up\n",
        " - plan to prepare all the changes on resources that will be deployed\n",
        " - apply to actually create/update the resources according to plan\n",
        " - destroy to delete all created resources\n\n",
        "options are ...optional. They can be:\n",
        "-d or --dir <dir> to specify a root dir where all tor files are located. Default is .\n\n",
        "EXAMPLE: tor init -d ~/projects/simple\n"
    );
    println!("{}", usage);
}


fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        print_usage();
        process::exit(0x0000);
    }
    if args[1] == "init" {
        let mut root_dir = String::from(".");
        if args[2] == "-d" || args[2] == "--dir" {
            root_dir = args[3].to_owned();
        }
        init::create_tor_folder(&root_dir).expect("Could not create tor folder");
    }
    else if args[1] == "plan" {
        println!("Not implemented yet");
    }
    else if args[1] == "apply" {
        println!("Not implemented yet");
    }
    else if args[1] == "destroy" {
        println!("Not implemented yet");
    }
    else {
        print_usage();
    }
}
