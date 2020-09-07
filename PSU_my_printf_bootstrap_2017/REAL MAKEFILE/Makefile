##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME 	= 	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		cd lib/my
		gcc -c $(NAME) $(OBJ)

$(NAME):	
		ar rc $(NAME) $(OBJ)
		cp libmy.a ../../

clean:	
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
