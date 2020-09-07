##
## EPITECH PROJECT, 2017
## makefile
## File description:
## Makefile for compiling editor
##

SRC	=	src/main.c \
		src/map_editor.c \
		src/str_to_word_tab.c \
		src/editor.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	editor

LDFLAGS	=	-L ../../lib/ -l my

CFLAGS	=	-g -W -Wall -Wextra -I ../../include

all:		$(NAME)

copy:
		cp include/editor.h ../../include/

$(NAME):	copy $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
		@echo -e "\x1B[01;92m Editor compilation Complete \x1B[0m"

clean:
		@rm -f $(OBJ)
		@rm -f ../../include/editor.h
		@echo -e "\x1B[01;94mClean editor \x1B[0m"

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
