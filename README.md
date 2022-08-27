# tor
Tor is to application what Terraform is to infrastructure. Well ... that is what we are aiming for and that is quite a challenge! If this sounds great to you, you are welcome to contribute. Any help will be highly appreciated.

## What Is tor?
tor is a software generator. You describe the components of your software in json-like configuration files, run the program and it generates the described components. Say, for instance, your software needs a SQL database. That is a pretty common use case. Rather than creating the tables and their fields by hand, you can describe the tables and fields in config files and then run the tor program and it generates the tables and their columns for you. Every time you need an edit in the schema, just edit the config files and re-run the program.

## Getting started

In order to use tor, you first need to download its source code that is available for free (under MIT license) on github and compile it with your local C compiler.
```
git clone https://github.com/iablaka/tor.git
cd tor
make build
```
If everything goes well, the tor program is now in the bin sub-directory and you can learn some more details running the following command:
```
./bin/tor help
```


