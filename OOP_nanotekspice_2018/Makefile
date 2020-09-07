##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for 42sh
##

SRC_DIR	= $(realpath src)

SRC	=	$(wildcard $(SRC_DIR)/*.cpp)	\
	main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

CXXFLAGS=	-g -W -std=c++14 -Wall -Wextra -Werror -I./src

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

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
