##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME 	= 	libstring.a

all:	$(NAME) tests_run

$(NAME):	$(OBJ)
		ar rc $(NAME) $(CFLAGS) $(OBJ)

tests_run:
		cd tests/ && make re

clean:
		@rm -f $(OBJ)
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete
		@find -type f -name '*.o' -delete

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
