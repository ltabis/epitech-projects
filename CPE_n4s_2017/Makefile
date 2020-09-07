##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

NAME	=	ai

SRC_DIR=        $(realpath src)

SRC	=	$(SRC_DIR)/main.c			\
		$(SRC_DIR)/compute_algorithm.c		\
		$(SRC_DIR)/backup.c		\
		$(SRC_DIR)/error_handling.c		\
		$(SRC_DIR)/parser.c			\
		$(SRC_DIR)/my_str_to_word_array.c	\
		$(SRC_DIR)/my_put_err.c			\
		$(SRC_DIR)/my_strncpy.c			\
		$(SRC_DIR)/my_strlen.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -I include

all:		$(NAME)

lib:
		@make -C lib/my

tests_run:
		@make -C tests/

lib-clean:
		@make -C lib/my clean

lib-fclean:
		make -C lib/my fclean

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		@$(RM) -f $(OBJ)
		@find ../ -type f -name '*~' -delete
		@find ../ -type f -name '#*#' -delete
		@$(RM) -r -f *~ \#*\#

fclean:		clean
		@make fclean -C tests/
		@$(RM) -f $(NAME)

re:		fclean all

.PHONY:		all lib lib-clean lib-fclean clean fclean re
