##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	cat.c		\
		main.c		

OBJ	=	$(SRC:.c=.o)

NAME 	= 	cat

all:	subsystem all

subsystem:
		cd ../lib/my && $(MAKE)
		cd .

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -I../include -L../lib/my -lmy

clean:	
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
