##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main.c				\
		main_loop.c			\
		copy_variables.c		\
		display.c			\
		memory_handling.c		\
		research.c			\
		forking.c			\
		modify_env_variable.c		\
		modify_env_variable_name.c	\
		delete_env_variable.c		\
		error_handling.c		\
		move_in_files.c			\
		src/get_next_line.c		\
		src/my_printf.c			\
		src/my_printf_flags.c		\
		src/my_printf_flags_bis.c	\
		src/my_printf_flags_bonus.c	\
		src/my_revstr.c			\
		src/my_putstr.c			\
		src/my_strlen.c			\
		src/my_put_nbr.c		\
		src/my_putchar.c		\
		src/my_strcmp.c			\
		src/my_strcat.c			\
		src/my_strcpy.c


OBJ	=	$(SRC:.c=.o)

NAME 	= 	mysh

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g

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
