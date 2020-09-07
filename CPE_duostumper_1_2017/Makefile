##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile for stumper
##

SRC= 	main.c			\
	algorithm.c		\
	src/my_isnum.c		\
	src/my_strdup.c		\
	src/my_strlen.c		\
	src/my_getnbr.c

OBJ=	$(SRC:.=o)

NAME= 	fractals

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -g -Wall -Werror

clean:
	rm -f lol

fclean:	clean
	rm -f $(NAME)
