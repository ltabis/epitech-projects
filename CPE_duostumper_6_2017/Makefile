##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC=	main.c	\
		src/error_handling.c	\
		src/iteration.c	\
		src/check_cells.c	\
		src/utils.c	\
		src/parser.c

OBJ=	$(SRC:.c=.o)

NAME=	gameoflife

all:	$(SRC)
	gcc -o $(NAME) $(SRC) -g -W -Wall -Wextra -Iinclude

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all
