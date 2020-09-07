##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for 42sh
##

SRC_DIR = $(realpath ../src)

SRC = $(SRC_DIR)/display_symbols.c \
 $(SRC_DIR)/display_sections.c

SRC_SHARED = $(SRC_DIR)/shared_func_1.c \
 $(SRC_DIR)/shared_func_2.c

SRC_UT_DIR = $(realpath .)

SRC_UT = $(SRC_UT_DIR)/unit_test_nm.c

OBJUT = $(SRC_UT:.c=.o)
OBJ32 = $(SRC:.c=_32.o)
OBJ64 = $(SRC:.c=_64.o)

OBJ_SHARED = $(SRC_SHARED:.c=.o)

NAME = unit_tests

CFLAGS = -g -W -Wall -Wextra --coverage -I../include
LDFLAGS = -lcriterion -lgcov

all: $(NAME) run

%_32.o: %.c
	gcc -c -DARCH=32 -o $@ $< $(CFLAGS)

%_64.o: %.c
	gcc -c -DARCH=64 -o $@ $< $(CFLAGS)


$(NAME): $(OBJ32) $(OBJ64) $(OBJUT) $(OBJ_SHARED)
	gcc -o $(NAME) $(OBJ32) $(OBJ64) $(OBJUT) $(OBJ_SHARED) $(CFLAGS) $(LDFLAGS)

run:	$(NAME)
		./unit_tests

clean:
	@rm -f $(OBJ32)
	@rm -f $(OBJ64)
	@rm -f $(OBJUT)
	@rm -f $(OBJ_SHARED)
	@find -type f -name '*~' -delete
	@find -type f -name '#*#' -delete
	@find -type f -name '*.gcda' -delete
	@find -type f -name '*.gcno' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all
