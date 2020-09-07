##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main_test.c		\
		particle_system.c	\
		particle_system_2.c	\
		particle_system_3.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	a.out

COV	=	-Wall -Wextra

GRAPH	=	-l c_graph_prog

all:		$(SRC)
		gcc -o $(NAME) $(SRC) $(COV) $(GRAPH) -g -lm

tests_run:
		cd tests/ && $(MAKE)

clean:
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
