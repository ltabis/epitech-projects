##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for 42sh
##

SRC_DIR = $(realpath src)

SRC = $(SRC_DIR)/display_symbols.c \
 $(SRC_DIR)/display_sections.c

SRC_SHARED = $(SRC_DIR)/shared_func_1.c \
 $(SRC_DIR)/shared_func_2.c

SRC_OBJ2 = $(SRC_DIR)/objdump.c
SRC_NM2 = $(SRC_DIR)/nm.c

OBJ_OBJ32 = $(SRC:.c=_32.o)
OBJ_OBJ64 = $(SRC:.c=_64.o)

OBJ_OBJ2 = $(SRC_OBJ2:.c=.o)
OBJ_NM2 = $(SRC_NM2:.c=.o)

OBJ_SHARED = $(SRC_SHARED:.c=.o)

NAME_NM = my_nm

NAME_OBJ = my_objdump

CFLAGS = -g -W -Wall -Wextra -Iinclude

all: nm objdump

%_32.o: %.c
	gcc -c -DARCH=32 -o $@ $< $(CFLAGS)

%_64.o: %.c
	gcc -c -DARCH=64 -o $@ $< $(CFLAGS)

nm: $(OBJ_OBJ32) $(OBJ_OBJ64) $(OBJ_NM2) $(OBJ_SHARED)
	gcc -o $(NAME_NM) $(OBJ_OBJ32) $(OBJ_OBJ64) $(OBJ_NM2) $(OBJ_SHARED) $(CFLAGS)

objdump: $(OBJ_OBJ32) $(OBJ_OBJ64) $(OBJ_OBJ2) $(OBJ_SHARED)
	gcc -o $(NAME_OBJ) $(OBJ_OBJ32) $(OBJ_OBJ64) $(OBJ_OBJ2) $(OBJ_SHARED) $(CFLAGS)

tests_run:
	cd tests/ && $(MAKE)

clean:
	@rm -f $(OBJ_OBJ32)
	@rm -f $(OBJ_OBJ64)
	@rm -f $(OBJ_NM2)
	@rm -f $(OBJ_OBJ2)
	@rm -f $(OBJ_SHARED)
	@find -type f -name '*~' -delete
	@find -type f -name '#*#' -delete
	@find -type f -name '*.gcda' -delete
	@find -type f -name '*.gcno' -delete
	@cd tests/ && $(MAKE) fclean

fclean: clean
	rm -f $(NAME_NM)
	rm -f $(NAME_OBJ)

re: fclean all
