##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	boot.c	\

OBJ	=	$(SRC:.c=.o)

NAME 	= 	my_exec

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -Wall -Wextra --coverage

clean:	
		rm -f $(NAME)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
