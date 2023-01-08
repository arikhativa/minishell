# Minishell

A mini verstion of a bash application.

![Quick Demo][quick-demo]

## About

Minishell is a project as part of the 42 scholl.
It's a minimum viable version of a real shell.
The main goal is to have a good understanding of processess, file descriptors, signlas and generally start manageing a lage scale projects.
All in by using the C programmming language and comparing to bash.

## Installation & Usage

### Requirements
The only requirements are:
- GNU make (v3.81)
- GCC (v4.2.1)

Those versions are the ones used during development.

### Building the program

1. Download/Clone this repo

        git clone https://github.com/r4meau/minishell
2. `cd` into the root directory and run `make`

        cd minishell
        make

### Running the program

After building the source, run `./minishell` from the project root.

## Main Project Instructions

### Mandatory

- Can only use C
- Must respect the school imposed coding style ([The Norme][norme-pdf])
- No memory leaks
- Implement a series of builtins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Manage errors by displaying a message to the standard error.
- Can only use these standard library functions:
    - malloc, free
    - access
    - open, close, read, write
    - opendir, readdir, closedir
    - getcwd, chdir
    - stat, lstat, fstat
    - fork, execve
    - wait, waitpid, wait3, wait4
    - signal, kill
    - exit
- Must have a Makefile to build the program
- The binary file must be named `minishell`
- Handle program interruption (Ctrl + D)
- Signal management (SIGINT, SIGQUIT)
- PATH's right management (error handling)
- Handle redirection
  - in, out, appand and heredoc
- Multiple commands (with pipes only)


- [Click here][1] for the full project instructions.

Enjoy!

[1]: https://github.com/R4meau/minishell/blob/master/minishell.en.pdf
[quick-demo]: https://raw.githubusercontent.com/R4meau/minishell/master/minishell-quick-demo.gif?token=ADzLiR-sTesle5g6_4CQnHz4RFe69TgDks5ZK6oGwA%3D%3D
[libft-url]: https://github.com/R4meau/libft
[norme-pdf]: https://github.com/R4meau/minishell/blob/master/norme.en.pdf
