##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for FTP server
##

SRC_DIR = $(realpath src)

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:.c=.o)

NAME = myARPspoof

CFLAGS = -g -W -Wall -Wextra -iquote include/

LIBRARIES = -lcrypto

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIBRARIES)

tests_run:
	cd tests/ && $(MAKE)

clean:
	@rm -f $(OBJ)
	@find -type f -name '*~' -delete
	@find -type f -name '#*#' -delete
	@find -type f -name '*.gcda' -delete
	@find -type f -name '*.gcno' -delete
	@find -type f -name '*.o' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all
