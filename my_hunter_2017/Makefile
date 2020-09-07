##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	game_loop.c			\
		src/initiate_ressources.c	\
		src/utils.c			\
		src/gameplay.c			\
		src/my_putstr.c			\
		src/my_putchar.c		\
		src/my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	my_hunter

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -l c_graph_prog

clean:	
		rm -f $(NAME)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
