# 0x16. C - Simple Shell

This is a team project work from ALX as part of the requirements for the
Software Development Programme 2022 to create a SIMPLE SHELL

## Acknowledgements

Some Resources were utilized during the course of getting this projec done which includes but not limited to:

- [Let’s Build a Linux Shell — Part I by Mohammed Isam](https://blog.devgenius.io/lets-build-a-linux-shell-part-i-954c95911501)
- [Tutorial to code a simple shell in C by Ricardo Hincape](https://medium.com/swlh/tutorial-to-code-a-simple-shell-in-c-9405b2d3533e)
- [Tutorial - Write a Shell in C by Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [Writing a Simple Shell by Foo So](https://youtu.be/z4LEuxMGGs8)
- And a lot more resources and Peer Help

## Project Requirements

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
- Write a README with the description of your project
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

## Authorized Functions and System Calls

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- \_exit (man 2 \_exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (\_\_xstat) (man 2 stat)
- lstat (\_\_lxstat) (man 2 lstat)
- fstat (\_\_fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Compilation Method

The shell was compiled using:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Authors

- [Tijani Mukhtar Akande](https://www.github.com/tijanimukhtarakande)
- [Tobe](https://github.com/TOBECHI-GH)

## License

This is an open source test project in line with requirements and oversaw by [ALX_AFRICA](https://www.alxafrica.com/)
