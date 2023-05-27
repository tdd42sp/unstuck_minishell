#------------------------------------------------------------------------------#
#	Project: minishell (Coning dojo)                                           #
#	File Created: 2020-07-20 15:00:00                                          #
#------------------------------------------------------------------------------#

NAME	= minishell
HEADER	= $(NAME).h
SRC		= src/main.c		\
		  src/ft_split.c	\
		  src/execute.c		\
		  src/echo.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3
LDFLAGS	= -lreadline

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME) && ./$(NAME)

valgrind: $(NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME) -q --leak-check=full && valgrind ./$(NAME)

.PHONY: all clean fclean re test
