# Minishell

A mini version of a bash application.

![Quick Demo][demo]

## About

Minishell is a project as part of the 42 school.

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
* Read from arg
	* `./minishell -c "echo Hello!"`
* Read from File
	* `./minishell ./file.sh`
	* `./minishell < file.sh`

## Main Project Instructions

### Mandatory

- Can only use C
- Must respect the school imposed coding style ([The Norme][norm-repo])
- No memory leaks
- Implement a series of builtins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Manage errors by printing a message to the standard error
- Can only use specific functions like (full list in the subject pdf below):
	- readline, add_history
	- printf, write
	- malloc, free
	- access, open, read, close
	- fork, wait
	- signal, sigaction, kill
	- exit
	- getcwd, chdir
	- stat
	- execve
	- dup, dup2, pipe
	- opendir, readdir, closedir
	- strerror, perror
- Must have a Makefile to build the program
- Handle program interruption (Ctrl + D) and signals (SIGINT, SIGQUIT)
- Use PATH var to look for binaries
- Have a working history
- Handle single and double quotes
- Expand $
- Handle redirections:
	- in (<)
	- out (>)
	- append (>>)
	- heredoc (<<)
- Handle pips

[full project instructions][subject]

### Github Actions

Since this project took 3 months to develop, I created a CI that enforces a few checks before a PR could be done.
The CI is handled by github action ([ci.yml][actions]).
there are a few steps in the CI:
 - checking the norm
 - compiling with the Unit-Tests
 - running the tests
 - checking there were no leaks
 
Enjoy!

[subject]: https://github.com/arikhativa/minishell/blob/main/.github/en.subject.pdf
[demo]: https://github.com/arikhativa/minishell/blob/main/.github/Animation.gif
[actions]: https://github.com/arikhativa/minishell/blob/main/.github/workflows/ci.yml
[norm-repo]: https://github.com/42School/norminette
