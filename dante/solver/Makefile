##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC=	src/main.c	\
		src/compute_algorithm.c	\
		src/my_strcat.c	\
		src/error_handling.c

OBJ=	$(SRC:.c=.o)

NAME= 	solver

CFLAGS=	-g -Wall -Wextra -I ../include

all:	$(NAME)

$(NAME):		$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(OBJ)

re:	fclean all
