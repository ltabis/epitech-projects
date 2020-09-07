##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for 42sh
##

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME 	= 	my_cat

CFLAGS	=	-g -W -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		@find -type f -name '*~' -delete
		@find -type f -name '#*#' -delete
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
