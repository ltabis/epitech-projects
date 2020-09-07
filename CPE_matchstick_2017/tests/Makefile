##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_DIR=        $(realpath ../src/)

SRC=           	$(SRC_DIR)/display.c                                   \
                $(SRC_DIR)/create_board.c                              \
                $(SRC_DIR)/main_loop.c                                 \
                $(SRC_DIR)/ia_turn.c                                   \
                $(SRC_DIR)/err_handling/basic_error_handling.c         \
                $(SRC_DIR)/base/my_getnbr.c                            \
                $(SRC_DIR)/base/my_put_nbr.c                           \
                $(SRC_DIR)/base/my_putchar.c                           \
                $(SRC_DIR)/base/my_strlen.c                            \
		$(SRC_DIR)/base/my_strcpy.c                            \
                $(SRC_DIR)/base/get_next_line.c

SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_matchstick_1.c			\
		$(SRC_UT_DIR)/unit_test_matchstick_2.c			\
		$(SRC_UT_DIR)/unit_test_matchstick_3.c

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_tests

all:            $(NAME) run

$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

run:		$(NAME)
		./unit_tests

clean:
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno
		rm -f ../*.gcda
		rm -f ../*.gcno
		rm -f ../src/*.gcda
		rm -f ../src/*.gcno
		rm -f ../src/base/*.gcda
		rm -f ../src/base/*.gcno
		rm -f ../src/err_handling/*.gcda
		rm -f ../src/err_handling/*.gcno

fclean:         clean
		rm -f $(NAME)

re:             fclean all
