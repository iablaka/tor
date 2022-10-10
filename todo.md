# Requirements
## User Stories
- *US000* - **tor Program Exists**
  
As a user, I can run a program called **tor** from the command line in order to start a new project of mine.

- *US001* - **Simple Usage Error Message**

As a user, if I enter a wrong command launching the tor program, then the program ends and I am given an explanation on how to use it.

- *US002* - **Allowed Commands**

As a user, I can enter the four following verbs as parameters: init, plan, apply, and destroy. These all four work and do something. Any other command fails nicely and returns a usage message.

- *US003* - **Hidden .tor Directory**

As a user, if I enter a valid dir with the init command, then a hidden .tor directory is created next to my config files in the targeted directory. If .tor already exists, it is removed and recreated.

- *US004* - **providers Directory in the .tor Directory**

As a user, when I use the init command, a providers directory is created in the .tor hidden directory to store future plugins.

- *US005* - **Parse tor Files to List Needed Providers**

As a user, when I use the init command, the system parses the config files in my project directory and identifies all the needed providers.



## Actions

- US 0 to 4 are completed. Moving to 5.
- Find out how to test all this before it becomes too big.
- Doc is to be improved.
- Create lib folder with fs_utils, str_utils in it
- Rewrite init.c to get rid of ftw calls and use fts instead
