##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile for deBruijn
##

NAME=	deBruijn
NAME_BIN=	deBruijn-exe

PA := $(shell stack path --local-install-root)/bin/$(NAME_BIN)

all: $(NAME)

$(NAME):
		stack build
		cp $(PA) .
		mv $(NAME_BIN) $(NAME)

clean:
	@find -type f -name '*~' -delete
	@find -type f -name '#*#' -delete
	@find -type f -name '*.gcda' -delete
	@find -type f -name '*.gcno' -delete

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all $(NAME) clean fclean re
