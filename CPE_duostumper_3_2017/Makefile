##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile for stumper
##

SRC	=	main.c			\
		src/parsing.c		\
		src/utils.c		\
		src/fields.c		\
		src/my_strdup.c		\
		src/my_getnbr.c		\
		src/my_strcat.c		\
		src/my_strlen.c

OBJ 	=	$(SRC:.c=.o)


all:		$(SRC)
		gcc -o minicut $(SRC) -g

clean:
		rm -f $(NAME)

fclean:		clean
		rm -f $(OBJ)

re:		fclean
		all
