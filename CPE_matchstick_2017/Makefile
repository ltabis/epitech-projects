##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main.c						\
		src/display.c					\
		src/create_board.c				\
		src/main_loop.c					\
		src/ia_turn.c					\
		src/err_handling/basic_error_handling.c		\
		src/base/my_getnbr.c				\
		src/base/my_put_nbr.c				\
		src/base/my_putchar.c				\
		src/base/my_strlen.c				\
		src/base/my_revstr.c				\
		src/base/my_strcpy.c				\
		src/base/get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	matchstick

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g

tests_run:
		cd tests/ && $(MAKE)

clean:	
		rm -f $(NAME)
		rm -f *.o
		rm -f *.o

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
