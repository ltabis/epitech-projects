##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

NAME 	= 	boot

all:		subsystem all

subsystem:
		cd lib/my && $(MAKE)

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -Iinclude -Llib/my -lmy -Wall -Wextra --coverage

clean:	
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
