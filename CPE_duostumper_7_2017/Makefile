##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## NO RELINCKS HAHA
##

SRC=	src/main.c	\
	src/error_handling.c	\
	src/writing_ciphered_input.c	\
	src/decrypt.c	\
	src/parser.c

OBJ=	$(SRC:.c=.o)

NAME=	cesar

CFLAGS=	-g -W -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)$  $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
