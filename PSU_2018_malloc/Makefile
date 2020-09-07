##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for 42sh
##

SRC_DIR	= $(realpath src)

SRC	=	$(wildcard $(SRC_DIR)/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

CFLAGS	=	-g -W -std=gnu11 -Wall -Wextra -fpic -Iinclude

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -shared -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		@rm -f $(OBJ)
		@find -type f -name '*~' -delete
		@find -type f -name '#*#' -delete
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
