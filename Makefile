all:
	cc src/main.c src/echo.c -lreadline && ./a.out

test:
	cc tests/test_echo.c src/echo.c -I tests && ./a.out