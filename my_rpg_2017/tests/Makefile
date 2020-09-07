##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_DIR		=	$(realpath ../src)
SRC_COM		=	$(realpath ../combat_mode)
SRC_LOAD	=	$(realpath ../map_loader)
SRC_LIB		=	$(realpath ../lib/my)

SRC		=	$(SRC_DIR)/window.c				\
			$(SRC_DIR)/sounds.c				\
			$(SRC_DIR)/error_handling.c			\
			$(SRC_DIR)/lore.c				\
			$(SRC_DIR)/utils.c				\
			$(SRC_DIR)/inventory.c				\
			$(SRC_DIR)/stats.c				\
			$(SRC_DIR)/menu_interactions.c			\
			$(SRC_DIR)/start/choose_perso.c			\
			$(SRC_DIR)/start/init.c				\
			$(SRC_DIR)/start/move_rect.c			\
			$(SRC_DIR)/start/menu.c				\
			$(SRC_DIR)/dialogue/dialogue.c			\
			$(SRC_DIR)/dialogue/init_dialog.c		\
			$(SRC_DIR)/parsers/npc_parser.c			\
			$(SRC_DIR)/parsers/obj_parser.c			\
			$(SRC_DIR)/parsers/text_parser.c		\
			$(SRC_DIR)/option_video.c			\
			$(SRC_COM)/combat_system.c			\
			$(SRC_COM)/escape_menu.c			\
			$(SRC_COM)/map_display.c			\
			$(SRC_COM)/map_display_condition.c		\
			$(SRC_COM)/combat_controls.c			\
			$(SRC_COM)/create_map.c				\
			$(SRC_COM)/display_background.c			\
			$(SRC_COM)/monster_parser.c			\
			$(SRC_COM)/new_monster.c			\
			$(SRC_COM)/new_stat_1.c				\
			$(SRC_COM)/new_stat_2.c				\
			$(SRC_COM)/utils.c				\
			$(SRC_COM)/utils_2.c				\
			$(SRC_COM)/utils_3.c				\
			$(SRC_COM)/utils_4.c				\
			$(SRC_COM)/inventory.c				\
			$(SRC_COM)/computing_turns.c			\
			$(SRC_COM)/ia_turn.c				\
			$(SRC_COM)/texts.c				\
			$(SRC_COM)/end_combat.c				\
			$(SRC_COM)/../base/my_strndup.c			\
			$(SRC_COM)/../base/my_strcmp.c			\
			$(SRC_COM)/../base/my_strrevcmp.c		\
			$(SRC_COM)/../base/my_strcat.c			\
			$(SRC_COM)/../base/my_strlen.c			\
			$(SRC_COM)/../base/my_revstr.c			\
			$(SRC_COM)/particles/particle_system.c		\
			$(SRC_COM)/particles/particle_system_2.c	\
			$(SRC_COM)/particles/particle_system_3.c	\
			$(SRC_LOAD)/src/main.c				\
			$(SRC_LOAD)/src/get_next_line.c			\
			$(SRC_LOAD)/src/get_next_line_2.c		\
			$(SRC_LOAD)/fct_option/example.c		\
			$(SRC_LOAD)/fct_option/tab_ptr_fct.c		\
			$(SRC_LOAD)/fct_option/swap_map_1.c		\
			$(SRC_LOAD)/fct_option/swap_map_2.c		\
			$(SRC_LOAD)/fct_option/swap_map_donjon_1.c	\
			$(SRC_LOAD)/src/init_1.c			\
			$(SRC_LOAD)/src/init_1_2.c			\
			$(SRC_LOAD)/src/init_2.c			\
			$(SRC_LOAD)/src/init_3.c			\
			$(SRC_LOAD)/src/init_4.c			\
			$(SRC_LOAD)/src/load_disp2.c			\
			$(SRC_LOAD)/src/load_disp.c			\
			$(SRC_LOAD)/src/move_r_l.c			\
			$(SRC_LOAD)/src/move_r_l2.c			\
			$(SRC_LOAD)/src/move_up_down.c			\
			$(SRC_LOAD)/src/move_up_down2.c			\
			$(SRC_LOAD)/src/init_menu.c			\
			$(SRC_LOAD)/src/main_theo.c			\
			$(SRC_LOAD)/src/menu_event.c			\
			$(SRC_LOAD)/src/setup_menu.c			\
			$(SRC_LOAD)/src/sprite_creation.c		\
			$(SRC_LOAD)/src/fct_array_pointer.c		\
			$(SRC_LOAD)/src/option.c			\
			$(SRC_LOAD)/src/set_pos.c			\
			$(SRC_LIB)/my_put_err.c				\
			$(SRC_LIB)/my_strncmp.c				\
			$(SRC_LIB)/my_getnbr.c				\
			$(SRC_LIB)/my_putstr.c				\
			$(SRC_LIB)/my_strdup.c				\
			$(SRC_LIB)/my_strcpy.c

SRC_UT_DIR	=	$(realpath .)

SRC_UT		=	$(SRC_UT_DIR)/redirect_all_std.c	\
			$(SRC_UT_DIR)/unit_test_rpg_1.c

OBJ		=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage -I ../include

LDFLAGS		=	-lcriterion -lgcov

GRAPH		=	-l c_graph_prog -lm

NAME		=	unit_test

all:            $(NAME) run fclean

$(NAME):        lib $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(GRAPH)

lib:
		make -C .. lib

run:		$(NAME)
		./unit_test

clean:
		@rm -f $(OBJ)
		@rm -f *~
		@find ../ -type f -name '*.gcda' -delete
		@find ../ -type f -name '*.gcno' -delete

fclean:         clean
		@rm -f $(NAME)

re:             fclean all
