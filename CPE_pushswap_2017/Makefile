##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main.c			\
		push_swap.c		\
		operations_files_01.c	\
		operations_files_02.c	\
		utils.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	push_swap

all:		subsystem all

subsystem:
		cd lib/my && $(MAKE)

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -lm -Iinclude -Llib/my -lmy -Wall -Wextra --coverage

clean:	
		rm -f $(NAME)
		rm -f *.gcno
		rm -f *.gcda

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
