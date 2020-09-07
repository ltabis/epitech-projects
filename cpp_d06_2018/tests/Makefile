##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_EX2_DIR=        $(realpath ../ex02)
SRC_EX3_DIR=        $(realpath ../ex03)
SRC_UT_DIR=     $(realpath .)

SRC=           $(SRC_EX2_DIR)/SickKoala.cpp	\
		$(SRC_EX3_DIR)/KoalaNurse.cpp

SRC_UT=	$(SRC_UT_DIR)/unit_test_function_ex02.cpp \
		$(SRC_UT_DIR)/unit_test_function_ex03.cpp

OBJ=            $(SRC:.cpp=.o) $(SRC_UT:.cpp=.o)

CFLAGS=         -Wall -Wextra --coverage -I.

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_tests

all:            $(NAME) run

$(NAME):        $(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS)

run:		$(NAME)
		./unit_tests

clean:
		@rm -f $(OBJ)
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete

fclean:         clean
		rm -f $(NAME)

re:             fclean all
