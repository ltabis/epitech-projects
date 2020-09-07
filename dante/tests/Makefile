##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC=           	../generator/src/display_maze.c			\
		../generator/src/error_handling.c		\
		../generator/src/generate_inperfect_maze.c	\
		../generator/src/generate_perfect_maze.c	\
		../generator/src/main_generation.c		\
		../generator/src/memory_handling.c		\
		../generator/src/walls_gestion.c		\
		../generator/src/walls_gestion_end.c		\
		../solver/src/compute_algorithm.c		\
		../solver/src/my_strcat.c

SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_ia_1.c	\
	         $(SRC_UT_DIR)/unit_test_ia_2.c

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage -I../include

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_test

all:            $(NAME) run

$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

run:		$(NAME)
		./unit_test

clean:
		rm -f $(OBJ)
		@find ../ -type f -name '*.gcda' -delete
		@find ../ -type f -name '*.gcno' -delete

fclean:         clean
		rm -f $(NAME)

re:             fclean all
