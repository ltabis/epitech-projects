##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for compiling map loader
##

SRC	=	src/main.c\
		src/get_next_line.c\
		src/get_next_line_2.c\
		src/utils.c\
		fct_option/example.c\
		fct_option/tab_ptr_fct.c\
		src/init_1.c\
		src/init_2.c\
		src/init_3.c\
		src/init_4.c\
		src/load_disp.c\
		src/move_r_l.c\
		src/move_up_down.c\
		src/utils2.c\
		src/init_menu.c \
		src/main_theo.c \
		src/menu_event.c \
		src/setup_menu.c \
		src/sprite_creation.c \
		src/utils_theo.c \
		src/fct_array_pointer.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-g -W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(SRC)
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) -l c_graph_prog

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
