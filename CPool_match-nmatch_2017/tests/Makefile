##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	match_test.c		\
		main_test.c		

OBJ	=	$(SRC:.c=.o)

NAME 	= 	match_test

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
