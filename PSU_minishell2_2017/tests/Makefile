##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_DIR=        $(realpath ../main_files)
SRC_SRC=        $(realpath ../)

SRC=          	$(SRC_DIR)/main_loop.c                     \
                $(SRC_DIR)/copy_variables.c                \
                $(SRC_DIR)/display.c                       \
                $(SRC_DIR)/memory_handling.c               \
                $(SRC_DIR)/research.c                      \
                $(SRC_DIR)/forking.c                       \
                $(SRC_DIR)/modify_env_variable.c           \
                $(SRC_DIR)/modify_env_variable_name.c      \
                $(SRC_DIR)/delete_env_variable.c           \
                $(SRC_DIR)/error_handling.c                \
                $(SRC_DIR)/move_in_files.c                 \
		$(SRC_DIR)/check_redirections.c            \
		$(SRC_DIR)/parsing_chained_lists.c         \
		$(SRC_DIR)/pipe_and_redirect.c         	   \
		$(SRC_DIR)/add_elements.c         	   \
		$(SRC_DIR)/special_forking.c         	   \
                $(SRC_SRC)/src/get_next_line.c             \
                $(SRC_SRC)/src/my_printf.c                 \
                $(SRC_SRC)/src/my_printf_flags.c           \
                $(SRC_SRC)/src/my_printf_flags_bis.c       \
                $(SRC_SRC)/src/my_printf_flags_bonus.c     \
                $(SRC_SRC)/src/my_revstr.c                 \
                $(SRC_SRC)/src/my_putstr.c                 \
                $(SRC_SRC)/src/my_strlen.c                 \
                $(SRC_SRC)/src/my_put_nbr.c                \
                $(SRC_SRC)/src/my_putchar.c                \
                $(SRC_SRC)/src/my_strcmp.c                 \
                $(SRC_SRC)/src/my_strcat.c                 \
		$(SRC_SRC)/src/my_puterr.c                 \
		$(SRC_SRC)/src/my_strndup.c                \
                $(SRC_SRC)/src/my_strcpy.c


SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_mysh.c 		\
		$(SRC_UT_DIR)/unit_test_mysh_2.c	\
		$(SRC_UT_DIR)/unit_test_mysh_3.c	\
		$(SRC_UT_DIR)/unit_test_mysh_4.c	\
		$(SRC_UT_DIR)/unit_test_mysh_5.c

OBJ=            $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_test

all:            $(NAME) run

$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(NCFLAGS) $(CFLAGS)

run:		$(NAME)
		./unit_test
clean:
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno
		rm -f ../src/*.gcda
		rm -f ../src/*.gcno
		rm -f ../main_files/*.gcda
		rm -f ../main_files/*.gcno

fclean:         clean
		rm -f $(NAME)

re:             fclean all
