##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_DIR=        $(realpath ..)

SRC=          	$(SRC_DIR)/compute_gameplay.c			\
		$(SRC_DIR)/concat_params.c			\
		$(SRC_DIR)/game_loop.c				\
		$(SRC_DIR)/key_handling.c			\
		$(SRC_DIR)/key_handling_gameplay.c		\
		$(SRC_DIR)/key_handling_gameplay_bis.c		\
		$(SRC_DIR)/key_handling_gameplay_pass.c		\
		$(SRC_DIR)/memory_handling.c			\
		$(SRC_DIR)/score.c				\
		$(SRC_DIR)/src/my_strlen.c			\
		$(SRC_DIR)/src/my_putstr.c			\
		$(SRC_DIR)/src/my_strcpy.c			\
		main_calls.c

SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_my_sokoban.c 	\
		$(SRC_UT_DIR)/unit_test_my_sokoban_2.c 	\
		$(SRC_UT_DIR)/unit_test_my_sokoban_3.c 	\

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

NCFLAGS=	-l ncurses

NAME=           unit_test

all:            $(NAME) run

$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(NCFLAGS) $(CFLAGS)

run:		$(NAME)
		./unit_test
clean:
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno
		rm -f ../../*.gcda
		rm -f ../../*.gcno

fclean:         clean
		rm -f $(NAME)

re:             fclean all
