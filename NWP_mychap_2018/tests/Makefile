##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## tests makefile
##

## Sources à tester
SRC_DIR=        $(realpath ../src)
SRC=           $(SRC_DIR)/socket.c \
	       $(SRC_DIR)/utils.c \
	       $(SRC_DIR)/fill_parameters.c

## Tests unitaires
SRC_UT_DIR=     $(realpath .)
SRC_UT=         $(SRC_UT_DIR)/unit_test_function_basic.c \
		$(SRC_UT_DIR)/unit_test_utils.c \
		$(SRC_UT_DIR)/unit_test_parameters.c

## Les OBJ de toutes les sources
OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

## Flags de compilation
CFLAGS=         -Wall -Wextra --coverage -I../include
LDFLAGS=        -lcriterion -lgcov

NAME=           unit_tests

all:            $(NAME) run

## Rule de compilation
$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

## Rule de test
run:		$(NAME)
		./unit_tests


## Rule pour clean le repo
clean:
		@rm -f $(OBJ)
		@find -type f -name '*.gcda' -delete
		@find -type f -name '*.gcno' -delete
fclean:         clean
		rm -f $(NAME)

re:             fclean all
