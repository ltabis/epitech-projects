##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for the 101pong
##

SRC	=	101pong.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	101pong

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -lm

clean:	
		rm -f $(NAME)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
