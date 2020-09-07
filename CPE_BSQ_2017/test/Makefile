##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_DIR=        $(realpath ..)

SRC=           	$(SRC_DIR)/compute_algorithm.c		\
		$(SRC_DIR)/concat_params.c		\
		$(SRC_DIR)/memory_handling.c		\
		concat_file.c				\

SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_BSQ.c \
		$(SRC_UT_DIR)/unit_test_BSQ_2.c \

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_test

all:            $(NAME) run

$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS) -I../include -L../lib/my -lmy

run:		$(NAME)
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
