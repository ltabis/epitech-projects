##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_DIR=     $(realpath ../ex00)

SRC=        	$(SRC_DIR)/Droid.cpp

SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_tests_1.cpp

OBJ=            $(SRC:.cpp=.o) $(SRC_UT:.cpp=.o)

CXXFLAGS=         -Wall -Wextra -Werror --coverage -I.

LDFLAGS=        -lcriterion

NAME=           unit_tests

all:            $(NAME) run

$(NAME):        $(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

run:		$(NAME)
		./unit_tests

clean:
		@rm -f $(OBJ)
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete

fclean:         clean
		rm -f $(NAME)

re:             fclean all
