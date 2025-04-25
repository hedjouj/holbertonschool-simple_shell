# 🚀 Creation of Our `Simple Shell` 
![IMAGE](terminal.gif)

Welcome to our custom `Simple Shell` project! 🎉

This project is a simple version of the linux shell made for Holberton School taking part of the "Low-level programming & Algorithm - Linux and Unix system programming" projects.
It is created using the C programming Language and it can do many functionalities that a real shell does.

## 📋 Project Overview

This project consists of building a simple UNIX command-line interpreter, or shell, as part of the Holberton School curriculum. The shell is designed to replicate basic functionalities of standard shells, allowing users to execute commands, manage processes, and interact with the system via a custom prompt.


## 🛠 Features

	✅ Custom Shell Prompt — Displays a prompt and waits for user input.

	✅ Command Execution — Supports execution of basic UNIX commands (e.g., ls, pwd, echo, etc.).

	✅ Path Resolution — Handles commands using the PATH environment variable.

	✅ Built-in Commands — Implements built-in commands like:

	exit — to quit the shell

	env — to display the environment variables

	✅ Input Parsing — Tokenizes and handles multiple arguments.

	✅ Error Handling — Gracefully manages invalid commands or syntax errors.

	✅ Interactive & Non-Interactive Modes — Supports both interactive terminal use and running scripts via files.

	✅ Memory Management — Proper allocation and deallocation to prevent memory leaks.


## 🔧 Technologies Used

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-343741?style=for-the-badge&logo=gnu&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![Vim](https://img.shields.io/badge/Vim-019733?style=for-the-badge&logo=vim&logoColor=white)
![Linux Badge](https://img.shields.io/badge/Linux-333333?style=for-the-badge&logo=linux&logoColor=white)

## 📂 Project Structure

The project contains several files, which are the following:

| Files | Description  |
| :-------- | :------- |
| [`shell.h`](https://github.com/hedjouj/holbertonschool-simple_shell/blob/main/shell.h) | The header file containing functions prototypes. |
| [`shell.c`](https://github.com/hedjouj/holbertonschool-simple_shell/blob/main/shell.c) | The file containing our function to create our simple shell. |
| [`getenv.c`](https://github.com/hedjouj/holbertonschool-simple_shell/blob/main/getenv.c) | The file containing the function to get the environment.  |
| [`tools.c`](https://github.com/hedjouj/holbertonschool-simple_shell/blob/main/tools.c) | All our Function Tools to optimate our simple shell. |
| [`command.c`](https://github.com/hedjouj/holbertonschool-simple_shell/blob/main/command.c) | Function to find the path and execute the command. |
| [`man_1_simple_shell`](https://github.com/hedjouj/holbertonschool-simple_shell/blob/main/man_1_simple_shell) | Manual page of our Simple Shell. |


## ⚙️  Compilation and Restrictions

**The code should be compiled this way:**

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c`

💡 What does it do?

This command is used to strictly compile all C files in our project.
It helps ensure the code is:

✅ Clean and free from common bugs

✅ Following C89 coding standards

✅ Compiled with any warning treated as an error

## 📌 List of allowed functions and system calls+

All functions from `string.h`
`access` (man 2 access) `chdir` (man 2 chdir)
`close` (man 2 close) `closedir` (man 3 closedir)
`execve` (man 2 execve) `exit` (man 3 exit)
`_exit` (man 2 _exit) `fflush` (man 3 fflush) 
`fork` (man 2 fork) `free` (man 3 free)
`getcwd` (man 3 getcwd) `getline` (man 3 getline)
`getpid` (man 2 getpid) `isatty` (man 3 isatty)
`kill` (man 2 kill) `malloc` (man 3 malloc)
`open` (man 2 open) `opendir` (man 3 opendir)
`perror` (man 3 perror) `printf` (man 3 printf)
`fprintf` (man 3 fprintf) `vfprintf` (man 3 vfprintf)
`sprintf` (man 3 sprintf) `putchar` (man 3 putchar)
`read` (man 2 read) `readdir` (man 3 readdir)
`signal` (man 2 signal) `stat` (__xstat) (man 2 stat)
`lstat` (__lxstat) (man 2 lstat) `fstat` (__fxstat) (man 2 fstat)
`strtok` (man 3 strtok) `wait` (man 2 wait)
`waitpid` (man 2 waitpid) `wait3` (man 2 wait3)
`wait4` (man 2 wait4) `write` (man 2 write)


## 💾 Use of Memory

The code does contain dynamic allocation of the memory.
However, to ensure the code is free of any memory-related issue, a tool such as `Valgrind` can be used on the executable file, after compilation:

```
root@b6579b5f94d3:/home/ubuntu/holbertonschool-printf# valgrind ./a.out 
==27531== Memcheck, a memory error detector
==27531== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==27531== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==27531== Command: ./hsh
==27531== 
==27531== 
==27531== HEAP SUMMARY:
==27531==     in use at exit: 0 bytes in 0 blocks
==27531==   total heap usage: 14 allocs, 14 frees, 2600 bytes allocated
==27531== 
==27531== All heap blocks were freed -- no leaks are possible
==27531== 
==27531== For lists of detected and suppressed errors, rerun with: -s
==27531== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


