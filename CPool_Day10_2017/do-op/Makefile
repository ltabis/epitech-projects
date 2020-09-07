##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	do-op.c		\
		main.c		

OBJ	=	$(SRC:.c=.o)

NAME 	= 	do-op

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -I../include -L../lib/my -lmy

clean:	
		rm -f $(NAME)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
