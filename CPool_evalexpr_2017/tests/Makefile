##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	shunting_yard.c		\
		main.c	

OBJ	=	$(SRC:.c=.o)

NAME 	= 	yard

all:	subsystem all

subsystem:
		cd ../lib/my && $(MAKE)

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -I../include -L../lib/my -lmy

clean:	
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:
		fclean all	
