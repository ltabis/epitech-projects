/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/

#ifndef PROTO_H_
#define PROTO_H_

typedef struct score_s {
	int x;
	int y;
} score;

typedef struct map_s {
	int stop;
	int x;
	int y;
	int score_goal;
	int boxes_stuck;
	int boxes;
	int boxes_base;
	int p_pos_x;
	int p_pos_y;
	int p_pos_x_base;
	int p_pos_y_base;
	int pos_x_cir;
	int pos_y_cir;
        char **x_file;
	char **x_file_save;
	score *O_pos;
        score *sc;
} map_t;

int detect_key(int);
int allocate_memory(int, char *);
void game_loop(map_t *);
void verify_score(map_t *);
void display_game(map_t *);
void display_how_to_use(void);
void display_game_win(map_t *);
void display_game_loose(map_t *);
void verify_file_stat(char *);
void verify_window_size(map_t *);
void verify_file_content(char *);
char *concat_params(char *, char *);
map_t *mv_p_up(map_t *);
map_t *mv_space(map_t *);
map_t *mv_p_down(map_t *);
map_t *mv_p_left(map_t *);
map_t *mv_p_right(map_t *);
map_t *mv_p_up_pass(map_t *);
map_t *setup_window(map_t *);
map_t *mv_p_up_check(map_t *);
map_t *mv_p_down_pass(map_t *);
map_t *mv_p_left_pass(map_t *);
map_t *put_targ_coords(map_t *);
map_t *mv_p_down_check(map_t *);
map_t *mv_p_left_check(map_t *);
map_t *mv_p_right_pass(map_t *);
map_t *mv_p_right_check(map_t *);
map_t *mv_p_space_check(map_t *);
map_t *initialise_values(map_t *);
map_t *mv_p_up_check_bis(map_t *);
map_t *mv_p_down_check_bis(map_t *);
map_t *mv_p_left_check_bis(map_t *);
map_t *mv_p_right_check_bis(map_t *);
map_t *compute_gameplay(map_t *, int);
map_t *load_2d_arr_from_file(char *, map_t *);
map_t *find_widht_and_height(map_t *, char *);
map_t *load_2d_arr_from_file_save(char *, map_t *);

#endif /* !PROTO_H_ */
