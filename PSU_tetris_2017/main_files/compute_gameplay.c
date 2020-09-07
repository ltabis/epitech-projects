/*
** EPITECH PROJECT, 2018
** compute_gameplay.c
** File description:
** gameplay computing
*/

#include "tetris.h"
#include <time.h>
#include <stdlib.h>

control_t compute_gameplay(control_t cl, tetrimino_t *tetr,
	window_t *w, char **brd)
{
	clock_t time = clock() % CLOCKS_PER_SEC;
	static int next_move = 0;
	static sz_t dec = {0, 0};
	int val = 0;

	cl = check_event(cl);
	if (next_move + TIME_FALL <= time) {
		next_move = time % CLOCKS_PER_SEC + TIME_FALL;
		val = check_tetriminos_collision(&dec, brd, tetr[cl.curr_tetr]);
		if (val == 2) {
			write_tetriminos_and_pass(brd, tetr, cl, &dec);
			cl = choose_next_tetriminos(tetr, w, cl);
			cl = check_end_game(cl, tetr, brd);
		}
	}
	decal_tetrimino(&dec, &cl, brd, tetr);
	if (val != 2)
		display_tetriminos_in_color(w, tetr, dec, cl);
	display_game_board(brd, w);
	return (cl);
}

control_t choose_next_tetriminos(tetrimino_t *tetr,
	window_t *w, control_t controls)
{
	unsigned int nxt = 0;

	werase(w->next);
	for (char trig = 0; controls.nbr_files - 1 > 0 && trig != 1;) {
		nxt = rand() % controls.nbr_files;
		trig = (tetr[nxt].info.state == -1 ? 0 : 1);
	}
	for (unsigned int i = 0; tetr[nxt].piece[i]; i++) {
		for (unsigned j = 0; tetr[nxt].piece[i][j]; j++) {
			(tetr[nxt].piece[i][j] == '*' ?
			wattron(w->next,
			COLOR_PAIR(tetr[nxt].info.color)),
			mvwprintw(w->next, i + 1, j + 1, " "),
			wattroff(w->next,
			COLOR_PAIR(tetr[nxt].info.color)) : 0);
		}
	}
	controls.curr_tetr = controls.next_tetr;
	controls.next_tetr = nxt;
	return (controls);
}

char **create_game_board(control_t cntrl)
{
	char **game_board = malloc(sizeof(char *) * (cntrl.map_size.y + 1));

	if (!game_board) {
		write(2, "Error", 1);
		exit(84);
	}
	for (int i = 0; i < cntrl.map_size.y; i++) {
		game_board[i] = malloc(sizeof(char) * (cntrl.map_size.x + 1));
		if (!game_board[i])
			exit(84);
		for (int j = 0; j < cntrl.map_size.x; j++)
			game_board[i][j] = -1;
		game_board[i][cntrl.map_size.x] = 0;
	}
	game_board[cntrl.map_size.y] = NULL;
	return (game_board);
}

void check_all_lines(char **game_board, window_t *w)
{
	for (unsigned int i = 0; game_board[i]; i++) {
		for (unsigned int j = 0; game_board[i][j]; j++) {
			w = w;
			game_board = game_board;
		}
	}
}
