##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	match.c		\
		main.c		

OBJ	=	$(SRC:.c=.o)

NAME 	= 	match

all:	subsystem all

subsystem:
		cd lib/my && $(MAKE)
		cd .

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -Iinclude -Llib/my -lmy

clean:	
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
