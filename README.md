# Minishell

A mini verstion of a bash application.

![Quick Demo][quick-demo]

## About

Minishell is a project as part of the 42 scholl.
It's a mini version of a real shell.
The main goal is to have a good understanding of processes, file descriptors, signals and generally start managing a large scale projects.
All by using the C programming language and comparing to bash.

This project was done by a team of 2.

## Installation & Usage

### Requirements
- make
- gcc

### Building the program

1. Clone repo

        git clone https://github.com/arikhativa/minishell.git
2. `cd` into the root directory and run `make`

        cd minishell
        make

### Running the program

The program can be used with these modes:
* Interactive
	* `./minishell`
* Read From arg
	* `./minishell -c "echo Hello!"`
* Read File
	* `./minishell ./file.sh`
	* `./minishell < file.sh`

## Main Project Instructions

### Mandatory

- Can only use C
- Must respect the school imposed coding style ([The Norme][norm-repo])
- No memory leaks
- Implement a series of builtins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Manage errors by printing a message to the standard error.
- Can only use these standard library functions:
	- readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
	- printf, write
	- malloc, free
	- access, open, read, close
	- fork, wait, waitpid, wait3, wait4
	- signal, sigaction, sigemptyset, sigaddset, kill
	- exit
	- getcwd, chdir
	- stat, lstat, fstat
	- unlink
	- execve
	- dup, dup2, pipe
	- opendir, readdir, closedir
	- strerror, perror
	- isatty, ttyname, ttyslot
	- ioctl
	- getenv
	- tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
- Must have a Makefile to build the program
- The binary file must be named `minishell`
- Handle program interruption (Ctrl + D) and signals (SIGINT, SIGQUIT)
- Use PATH var to look for binaries
- Have a working history
- Handle single and double quotes
- Expand $
- Handle redirection
  - in, out, append and heredoc -> (<, >, >>, <<)
- Handle pips

- [Click here][1] for the full project instructions.

### Github Actions

Since this project took 3 mouths to develop, I created a CI that enforces a few checks before a PR could be done.
The CI is handled by github action (LIKE TO FILE).
there are a few steps in the CI:
 - checking the norm
 - compiling with the Unit-Tests main
 - running the tests
 - checking there were no leaks
 
Enjoy!

[1]: https://github.com/arikhativa/minishell/blob/main/en.subject.pdf
[norm-repo]: https://github.com/42School/norminette

[quick-demo]: https://raw.githubusercontent.com/R4meau/minishell/master/minishell-quick-demo.gif?token=ADzLiR-sTesle5g6_4CQnHz4RFe69TgDks5ZK6oGwA%3D%3D
