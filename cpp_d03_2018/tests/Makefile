##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_UT_DIR=     $(realpath .)
SRC_SRC_DIR=     $(realpath ..)

SRC=        $(wildcard $(SRC_SRC_DIR)/*.c)

SRC_UT=         $(SRC_UT_DIR)/unit_test_function_1.c	\
		$(SRC_UT_DIR)/unit_test_function_2.c	\
		$(SRC_UT_DIR)/unit_test_function_3.c	\
		$(SRC_UT_DIR)/unit_test_function_4.c	\
		$(SRC_UT_DIR)/unit_test_function_5.c	\
		$(SRC_UT_DIR)/unit_test_function_6.c	\
		$(SRC_UT_DIR)/unit_test_function_7.c	\
		$(SRC_UT_DIR)/unit_test_function_8.c	\
		$(SRC_UT_DIR)/unit_test_function_9.c	\
		$(SRC_UT_DIR)/unit_test_function_10.c	\
		$(SRC_UT_DIR)/unit_test_function_11.c	\
		$(SRC_UT_DIR)/unit_test_function_12.c	\
		$(SRC_UT_DIR)/unit_test_function_13.c	\
		$(SRC_UT_DIR)/unit_test_function_14.c

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage -I../

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_tests

all:            $(NAME) run

$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

run:		$(NAME)
		./unit_tests

clean:
		@rm -f $(OBJ)
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete

fclean:         clean
		rm -f $(NAME)

re:             fclean all
