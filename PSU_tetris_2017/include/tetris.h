/*
** EPITECH PROJECT, 2017
** tetris.h
** File description:
** prototypes for the tetris progam
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <ncurses.h>
#include "window.h"
#include "base.h"
#include "args.h"
#include "debug.h"
#include "gameplay.h"
#include "get_next_line.h"

#define TIME_FALL 1000

typedef struct score {
	char *name;
	int score;
	char *scoreboard;
} score_t;

void erase_window(window_t *);
score_t *read_score_file(void);
score_t *sort_scoreboard(score_t *);
score_t init_full_score(char *, char *, int);
char *my_put_score(int);
void my_swap_score(score_t *, score_t *);
score_t init_new_score(char *);
score_t init_score(char *);
void handle_highscore(int, window_t *, struct termios);
void check_map_size(control_t, tetrimino_t *, int);
control_t check_end_game(control_t, tetrimino_t *, char **);
void lower_lines(char **, int, control_t, int *);
void check_lines(char **, control_t, int *);
char **my_rotate(tetrimino_t);
void decal_tetrimino(sz_t *, control_t *, char **, tetrimino_t *);
int check_key_active(char *, control_t);
void set_up_arrows(control_t *);
void display_game_board(char **, window_t *);
void write_tetriminos_and_pass(char **, tetrimino_t *, control_t, sz_t *);
int check_tetriminos_collision(sz_t *, char **, tetrimino_t);
int test_all_colisions(sz_t, sz_t, char **, tetrimino_t);
void display_tetriminos_in_color(window_t *, tetrimino_t *,
	sz_t, control_t);
void write_tetrimino_on_board(control_t, tetrimino_t *, window_t *, char **);
char **create_game_board(control_t);
control_t choose_next_tetriminos(tetrimino_t *, window_t *, control_t);
void delete_ressources(window_t *, char **, control_t);
void display_borders(window_t *);
void do_read_sort(struct dirent *, int *, char **);
void do_count(struct dirent *, int *);
void handle_windows(window_t *, int, int, control_t);
void get_window_sizes(window_t *, int *, int *);
control_t check_event(control_t);
int start_tetris(control_t, tetrimino_t *, int, struct termios);
int count_file(void);
int check_sort(char **);
char *my_realloc_and_fill_str(char *, int);
int my_swap_str(char **, char **);
void do_sorting(char **);
void sorting_names(char **);
char **do_sort_names(char **, char *, int *);
char **sort_names(int);

#endif /* !TETRIS_H_ */
