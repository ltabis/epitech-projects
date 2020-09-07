##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main_files/main.c				\
		main_files/main_loop.c				\
		main_files/copy_variables.c			\
		main_files/display.c				\
		main_files/memory_handling.c			\
		main_files/research.c				\
		main_files/check_redirections.c			\
		main_files/forking.c				\
		main_files/modify_env_variable.c		\
		main_files/modify_env_variable_name.c		\
		main_files/delete_env_variable.c		\
		main_files/error_handling.c			\
		main_files/move_in_files.c			\
		main_files/add_elements.c			\
		main_files/parsing_chained_lists.c		\
		main_files/pipe_and_redirect.c			\
		main_files/special_forking.c			\
		src/get_next_line.c				\
		src/my_printf.c					\
		src/my_printf_flags.c				\
		src/my_printf_flags_bis.c			\
		src/my_printf_flags_bonus.c			\
		src/my_revstr.c					\
		src/my_putstr.c					\
		src/my_strlen.c					\
		src/my_put_nbr.c				\
		src/my_putchar.c				\
		src/my_strcmp.c					\
		src/my_strcat.c					\
		src/my_strcpy.c					\
		src/my_puterr.c					\
		src/my_strndup.c


OBJ	=	$(SRC:.c=.o)

NAME 	= 	mysh

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -Wall -Wextra

tests_run:
		cd tests/ && $(MAKE)

clean:	
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno
		rm -f src/*.gcda
		rm -f src/*.gcno

re:		fclean all	
