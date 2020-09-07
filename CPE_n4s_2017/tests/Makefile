##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_DIR=        $(realpath ../src)

SRC=		$(SRC_DIR)/parser.c \
		$(SRC_DIR)/my_strlen.c \
		$(SRC_DIR)/my_strncpy.c \
		$(SRC_DIR)/my_str_to_word_array.c \
		$(SRC_DIR)/my_put_err.c

SRC_UT_DIR=     $(realpath .)

SRC_UT=		$(SRC_UT_DIR)/unit_test_get_nbr_value.c \
		$(SRC_UT_DIR)/unit_test_is_closer.c \
		$(SRC_UT_DIR)/unit_test_basics.c \
		$(SRC_UT_DIR)/redirect_all_std.c

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage -I ../include

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_test

all:            $(NAME) run

$(NAME):        $(OBJ)
		@cc -o $(NAME) $(OBJ) $(LDFLAGS)

run:		$(NAME)
		./unit_test

clean:
		@rm -f $(OBJ)
		@rm -f *~
		@find ../ -type f -name '*.gcda' -delete
		@find ../ -type f -name '*.gcno' -delete

fclean:         clean
		@rm -f $(NAME)

re:             fclean all
