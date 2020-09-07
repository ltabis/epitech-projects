##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## task01 Day10
##

SRC	=	main_files/main.c		\
		main_files/arguments_gestions.c	\
		main_files/arguments_error.c	\
		main_files/debug_mode.c		\
		main_files/my_swap_str.c	\
		main_files/check_sort.c		\
		main_files/sort_scoreboard.c	\
		main_files/check_event.c	\
		main_files/count_tetriminos.c	\
		main_files/erase_window.c	\
		main_files/rotate.c		\
		main_files/do_read_sort.c	\
		main_files/handle_highscore.c	\
		main_files/init_score.c		\
		main_files/my_swap_score.c	\
		main_files/do_count.c		\
		main_files/my_put_score.c	\
		main_files/handle_border.c	\
		main_files/load_tetriminos.c	\
		main_files/display_tetriminos.c	\
		main_files/option_1.c		\
		main_files/option_2.c		\
		main_files/free_memory.c	\
		main_files/start_tetris.c	\
		main_files/compute_gameplay.c	\
		main_files/compute_gameplay_2.c	\
		main_files/compute_gameplay_3.c	\
		main_files/score_display.c	\
		base_files/my_strcpy.c		\
		base_files/get_next_line.c	\
		base_files/my_getnbr.c		\
		base_files/my_put_nbr.c		\
		base_files/my_putchar.c		\
		base_files/my_putstr.c		\
		base_files/my_strcmp.c		\
		base_files/my_strdup.c		\
		base_files/my_strlen.c		\
		base_files/my_strncpy.c

OBJ	=	$(SRC:.c=.o)

NAME 	= 	tetris

INCLUDE	=	-Iinclude/

all:		$(SRC)
		gcc -o $(NAME) $(INCLUDE) $(SRC) -g -Wall -Wextra -Werror -lncurses

tests_run:
		cd tests/ && $(MAKE)

clean:
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno

fclean: 	clean
		rm -f $(NAME)

re:		fclean all
