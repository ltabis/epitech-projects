##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for FTP server
##

SRC_DIR = $(realpath src)

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:.c=.o)

NAME = myftp

CFLAGS = -g -W -Wall -Wextra -iquote include/

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

tests_run:
	cd tests/ && $(MAKE)

clean:
	@rm -f $(OBJ)
	@find -type f -name '*~' -delete
	@find -type f -name '#*#' -delete
	@find -type f -name '*.gcda' -delete
	@find -type f -name '*.gcno' -delete
	@cd tests/ && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
