##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main.c			\
		options_file_01.c	\
		options_file_02.c	\
		parser.c		\
		concat_params.c		\
		parser_bis.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	my_ls

all:		subsystem all

subsystem:
		cd lib/my && $(MAKE)

all:		$(SRC)
		gcc -o $(NAME) $(SRC) -g -Iinclude -Llib/my -lmy

clean:	
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all	
