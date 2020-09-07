##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME 	= 	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(NAME) $(OBJ)

$(NAME):	
		ar rc $(NAME) $(OBJ)

clean:	
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
