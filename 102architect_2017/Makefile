##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main.c			\
		src/zoom.c		\
		src/rotation.c		\
		src/symmetry.c		\
		src/translation.c	\
		src/my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	102architect

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -lm

clean:	
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
