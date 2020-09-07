##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main.c				\
		map_in_memory.c			\
		error_handling_01.c		\
		utils.c				\
		infinity_mod.c			\
		normal_mod.c			\
		game_loop_infinity_mod.c	\
		game_loop_finite_mod.c		\
		menu.c				\
		pause.c				\
		end_events.c			\
		instatiation.c			\
		my_revstr.c			\
		my_strcmp.c			\
		texture_selection.c		\
		texture_selection_2.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	my_runner

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -l c_graph_prog -lm

clean:	
		rm -f $(NAME)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
