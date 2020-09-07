##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC=	src/main.c	\
		src/error_handling.c	\
		src/display_maze.c	\
		src/generate_perfect_maze.c	\
		src/generate_inperfect_maze.c	\
		src/walls_gestion.c	\
		src/walls_gestion_end.c	\
		src/memory_handling.c	\
		src/main_generation.c

OBJ=	$(SRC:.c=.o)

NAME= 	generator

CFLAGS=	-g -W -Wall -Wextra -I../include

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
