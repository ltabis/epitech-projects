##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile stumper
##

SRC	=	main.c			\
		src/input_parsing.c	\
		src/check_error.c	\
		src/generate_board.c	\
		src/display_board.c	\
		src/update_grid.c

OBJ	=	$(SRC:.c=.o)

NAME	=	connect4

all:	$(SRC)
	gcc -o $(NAME) $(SRC) -g -W -Wall -Wextra

clean:	$(SRC)
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean re
