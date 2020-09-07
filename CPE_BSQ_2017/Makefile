##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	concat_file.c		\
		concat_params.c		\
		compute_algorithm.c	\
		memory_handling.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	bsq

all:		subsystem all

subsystem:
		cd lib/my && $(MAKE)

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -Iinclude -Llib/my -lmy

tests_run:
		cd test/ && $(MAKE)

clean:	
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
