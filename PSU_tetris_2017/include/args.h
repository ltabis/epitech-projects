/*
** EPITECH PROJECT, 2017
** args.h
** File description:
** prototypes for the tetris progam
*/

#ifndef ARGS_H_
#define ARGS_H_

#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <ncurses.h>
#include "debug.h"
#include "get_next_line.h"
#include <getopt.h>

#define TRUE  1
#define FALSE 0

typedef struct control_s {
	sz_t map_size;
	char *key_left2;
	char *key_right2;
	char *key_turn2;
	char *key_drop2;
	char *key_quit2;
	char *key_pause2;
	int level;
	char debug;
	char act_next_tetr;
	int nbr_files;
	int len_max;
	char pass;
	unsigned int curr_tetr;
	unsigned int next_tetr;
} control_t;

char *alloc_tetriminos_line(char *, int);
void check_term_errors_and_free(char *);
void check_valid_arguments(int, char **);
void check_other_valid_arguments(int, char **);
void display_key_special(char *);
void free_structs(tetrimino_t *, control_t *, unsigned int, struct termios);
void display_infos(tetrimino_t);
void display_debug_mode(control_t, tetrimino_t *, unsigned int);
void display_controls_informations(control_t);
void set_up_terminal(control_t *, char **);
sz_t check_valid_map_size(char *);
control_t handle_arguments(int, char **, char **);
control_t assign_default_controls(char **);
void display_help(char *);
void change_defaut_setting(control_t *, int, int, char *);
tetrimino_t *create_tetriminos(tetrimino_t *, char **names);
char **load_tetriminos(char *, tetrimino_t *);
void check_spaces_between_lines(char *);
void change_map_size(control_t *, char *);
void change_key_left(control_t *, char *);
void change_key_right(control_t *, char *);
void change_key_turn(control_t *, char *);
void change_key_drop(control_t *, char *);
void change_key_quit(control_t *, char *);
void change_key_pause(control_t *, char *);
void change_level(control_t *, char *);
void change_debug(control_t *, char *);
void change_next(control_t *, char *);

#endif /* !ARGS_H_ */
