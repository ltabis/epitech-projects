##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for the lib "libmy.a"
##

NAME	=	libmy.a

SRC	=	my_putchar.c \
		my_isdigit.c \
		my_ischar.c \
		my_putnbr.c \
		my_putstr.c \
		my_strlen.c \
		my_getnbr.c \
		my_strdup.c \
		my_put_err.c \
		my_strcpy.c \
		my_strncpy.c \
		my_strcmp.c \
		my_strncmp.c \
		my_memset.c \
		my_strcat.c \
		my_strncat.c \
		my_strdup.c \
		my_str_to_word_tab.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g -I include

all:		$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../
		@cp include/my.h ../../include
		@echo -e "\x1B[01;92mCompiling lib \x1B[0m"

clean:
		@echo -e "\x1B[01;94mClean lib \x1B[0m"
		@rm -f $(OBJ)
		@$(RM) -f $(NAME)
		@$(RM) -f ../$(NAME)
		@find ../ -type f -name '*~' -delete
		@find ../ -type f -name '#*#' -delete

fclean:		clean
		@rm -f $(NAME)
		@rm -f ../$(NAME)
		@rm -f ../../include/my.h

re:		clean all

.PHONY:		all clean fclean re
