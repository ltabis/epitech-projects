##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main_calls.c			\
		concat_params.c			\
		game_loop.c			\
		score.c				\
		compute_gameplay.c		\
		key_handling.c			\
		key_handling_gameplay.c		\
		memory_handling.c		\
		key_handling_gameplay_bis.c	\
		key_handling_gameplay_pass.c	\
		src/my_strlen.c			\
		src/my_strcpy.c			\
		src/my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	my_sokoban

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -l ncurses

tests_run:
		cd tests/ && $(MAKE)

clean:	
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
