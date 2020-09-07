##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	my_stdarg.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	std

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -Iinclude -Llib/my -lmy

clean:	
		rm -f $(NAME)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
