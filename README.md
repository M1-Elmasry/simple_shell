# Simple Linux Shell

## Overview

The Simple Linux Shell is a fundamental project developed for learning purposes as part of the ALX Software Engineering track. This Linux shell implementation encompasses basic features found in other shells, allowing users to execute system commands, open files, and interact with the system efficiently. The primary motivation behind this project is to deepen understanding and practical knowledge of shell operations, linux system management, and overall software development.

## Key Features

- **Command Execution:** The shell provides the ability to execute system commands, extending its functionality beyond a mere interface to actively interact with the underlying operating system.

- **Built-in Commands:** Essential built-in commands such as `cd`, `exit`, `env`, and others have been implemented, offering users a comprehensive set of functionalities within the shell itself.

- **Memory Leak Handling:** The Simple Linux Shell pays close attention to managing memory effectively. We've thoroughly tested and reviewed the project to find and fix any memory leaks, making sure the system is dependable and uses memory efficiently. try to run after installing `echo -e "ls" | valgrind ./hsh`, you can replace `ls` with any command you want to test with


**It's important** to note that the Simple Linux Shell intentionally does not implemented with advanced behaviors like pipelines, logical operators, and redirections. The focus is on providing a foundational understanding of shell operations without delving into complex features.

## Educational Focus

Developed as part of the ALX Software Engineering track, this project serves as a practical learning tool. By actively engaging in the implementation of a Linux shell, participants gain hands-on experience with system-level programming, command execution, and the intricacies of shell design. The project encourages exploration and experimentation, this project makes me have a deeper understanding of somethings like process management, low-level programming and memory management

## How to Use

To use the this shell, follow the following installation instructions.  

1 - clone this repo
```
git clone https://github.com/M1-Elmasry/simple_shell.git
```
2 - run the shell
```
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o hsh && ./hsh
```


## Output Samples
```
➜  simple_shell git:(master) gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o hsh
➜  simple_shell git:(master) ./hsh
$ pwd
/home/linux/simple_shell
$ ls
AUTHORS  builtins.c  exec.c  hsh  main.c  main.h  parse.c  README.md  search.c	utils.c
$ cat AUTHORS
mostafa elmasry <mostafamfelmasry@outlook.com>
mahmoud samy <mahmoud.samy.elshora@gmail.com>
$ ls -la
total 68
drwxr-xr-x  3 linux linux  4096 Jan 13 07:55 .
drwxr-xr-x 38 linux linux  4096 Jan 13 07:52 ..
-rw-r--r--  1 linux linux    93 Jan 13 07:52 AUTHORS
-rw-r--r--  1 linux linux  3512 Jan 13 07:52 builtins.c
-rw-r--r--  1 linux linux   884 Jan 13 07:52 exec.c
drwxr-xr-x  8 linux linux  4096 Jan 13 07:52 .git
-rwxr-xr-x  1 linux linux 17192 Jan 13 07:55 hsh
-rw-r--r--  1 linux linux  1164 Jan 13 07:52 main.c
-rw-r--r--  1 linux linux  2073 Jan 13 07:52 main.h
-rw-r--r--  1 linux linux  1168 Jan 13 07:52 parse.c
-rw-r--r--  1 linux linux    27 Jan 13 07:52 README.md
-rw-r--r--  1 linux linux   766 Jan 13 07:52 search.c
-rw-r--r--  1 linux linux  1893 Jan 13 07:52 utils.c
$ blabla
./hsh: line 1: blabla: No such file or directory
$ exit
➜  simple_shell git:(master) echo $status
0
➜  simple_shell git:(master)

```
