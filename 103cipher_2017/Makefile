##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	deter.c		\
		decipherment.c	\
		encryption.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	103cipher

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -lm -Wall -Wextra --coverage

clean:	
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
