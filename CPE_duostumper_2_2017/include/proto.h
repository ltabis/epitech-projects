/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** prototypes stuper
*/

#ifndef PROTO_H_
#define PROTO_H_

#define NBR_OPT		5

typedef struct grid_info_s {
	int width;
	int height;
	char p1;
	char p2;
	char ref;
} grid_info_t;

void display_first_line(grid_info_t *);
void display_pipe(grid_info_t *, char **);
void generate_game_env(grid_info_t);
char **create_board(grid_info_t);
int parse_line(char *, grid_info_t, char **, char);
int checking_parameter(grid_info_t *);
void update_board(int, char, char **);
void parse_input(int, char * const *, grid_info_t *);
void update_widht(grid_info_t *, const char *, const char *, int *);
void update_height(grid_info_t *, const char *, const char *, int *);
void update_player_one(grid_info_t *, const char *, const char *, int *);
void update_player_two(grid_info_t *, const char *, const char *, int *);
void update_referee(grid_info_t *, const char *, const char *, int *);
int is_number(const char *);

#endif
