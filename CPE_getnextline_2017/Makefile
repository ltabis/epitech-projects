##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_DIR=        $(realpath .)

SRC=           	$(SRC_DIR)/get_next_line.c    \

SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_gnl.c \
		$(SRC_UT_DIR)/unit_test_gnl_2.c \

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_test

tests_run:      $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)
		./unit_test

clean:
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno
		rm -f ../*.gcda
		rm -f ../*.gcno

fclean:         clean
		rm -f $(NAME)

re:             fclean all
