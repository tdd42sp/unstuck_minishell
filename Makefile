all:
	cc src/main.c src/ft_split.c src/execute.c src/echo.c -lreadline && ./a.out

test:
	cc tests/test_echo.c src/echo.c -I tests && ./a.out
	cc tests/test_exec_commands.c src/execute.c src/ft_strjoin.c -I tests && ./a.out