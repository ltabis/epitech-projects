##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of tetris
##

SRC_DIR=        $(realpath ..)

SRC=           	$(SRC_DIR)/main_files/debug_mode.c 		\
		$(SRC_DIR)/main_files/option_2.c 		\
		$(SRC_DIR)/main_files/check_sort.c 		\
		$(SRC_DIR)/base_files/my_strdup.c 		\
		$(SRC_DIR)/base_files/my_strcpy.c 		\
		$(SRC_DIR)/base_files/my_getnbr.c 		\
		$(SRC_DIR)/base_files/my_strlen.c

SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_tetris_1.c		\
		$(SRC_UT_DIR)/unit_test_tetris_2.c

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

INCLUDE=	-I../include/

NAME=           unit_test

all:            $(NAME)	run

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(INCLUDE) $(OBJ) $(CFLAGS) $(LDFLAGS)

run:		$(NAME)
		./unit_test

clean:
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno
		rm -f ../main_files/*.gcda
		rm -f ../main_files/*.gcno
		rm -f ../base_files/*.gcda
		rm -f ../base_files/*.gcno

fclean:         clean
		rm -f $(NAME)

re:             fclean all
