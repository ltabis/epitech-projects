##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for 42sh
##

SRC	=	menger.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	menger

CFLAGS	=	-g -W -std=gnu11 -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
		cd tests/ && $(MAKE)

clean:
		@rm -f $(OBJ)
		@find -type f -name '*~' -delete
		@find -type f -name '#*#' -delete
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
