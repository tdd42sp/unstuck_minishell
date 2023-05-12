# Unstuck Minishell

In this project 42 São Paulo community is live coding together to check how it is to start a complex project where people usually get stuck from the beginning.

## First meetup - 2023.may.05

In this meetup, at 42 São Paulo, we started by making a simple `main.c` file to start reading the user input.

After that we decided to implement the `exit` built-in function. So we decided to make the simplest `Makefile` to not have to type the command line all the time.

The `echo` built-in function was chosen as the first "complex" function to be implemented using tests. So we created a "test suite", but we were not able to end the implementation because it was not so easy to handle the exit string from the echo command (we had to use file descriptors).

## Second meetup - 2023.may.12

We resumed the simplest `echo` implementation with 2 tests, we improved Makefile to runtests and updated our `main.c` to call the `echo` function.

## Next steps

- study [bash manual](https://www.gnu.org/software/bash/manual/bash.html#Shell-Operation)
- study [explainshell.com](https://explainshell.com/)
- decide what to do next

See ya next friday! Let's unstuck!