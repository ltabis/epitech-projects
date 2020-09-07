/*
** EPITECH PROJECT, 2018
** compute_gameplay_2.c
** File description:
** gameplay computing
*/

#include "tetris.h"

void display_tetriminos_in_color(window_t *w, tetrimino_t *tetr,
	sz_t decal, control_t cntrl)
{
	werase(w->game);
	for (unsigned int i = 0; tetr[cntrl.curr_tetr].piece[i]; i++) {
		for (unsigned j = 0; tetr[cntrl.curr_tetr].piece[i][j]; j++) {
			(tetr[cntrl.curr_tetr].piece[i][j] == '*' ?
			wattron(w->game,
			COLOR_PAIR(tetr[cntrl.curr_tetr].info.color)),
			mvwprintw(w->game,
			decal.y + i + 1, decal.x + j + 1, " "),
			wattroff(w->game,
			COLOR_PAIR(tetr[cntrl.curr_tetr].info.color)) : 0);
		}
	}
}

void display_game_board(char **game_board, window_t *w)
{
	for (unsigned int i = 0; game_board[i]; i++) {
		for (unsigned int j = 0; game_board[i][j] != 0; j++) {
			(game_board[i][j] != -1 ?
			wattron(w->game, COLOR_PAIR(game_board[i][j])),
			mvwprintw(w->game, i, j + 1, " "),
			wattroff(w->game, COLOR_PAIR(game_board[i][j])) : 0);
		}
	}
}

int check_tetriminos_collision(sz_t *decal,
			char **game_board, tetrimino_t tet)
{
	int ret = 0;
	sz_t part = {0, 0};

	decal->y++;
	for (unsigned int i = 0; tet.piece[i] && ret < 1; i++) {
		for (unsigned int j = 0; tet.piece[i][j] && ret < 1; j++) {
			part.x = j;
			part.y = i;
			ret = test_all_colisions(*decal, part, game_board, tet);
		}
	}
	return (ret);
}

int test_all_colisions(sz_t decal, sz_t part,
	char **game_board, tetrimino_t tetr)
{
	if (tetr.piece[part.y][part.x] != '*')
		return (0);
	else if (game_board[part.y + decal.y + 2] == NULL)
		return (2);
	else if (game_board[part.y + decal.y + 1][part.x + decal.x] != -1)
		return (2);
	return (0);
}

void write_tetriminos_and_pass(char **game_board, tetrimino_t *tetr,
	control_t controls, sz_t *decal)
{
	for (unsigned int i = 0;
	tetr[controls.curr_tetr].piece[i]; i++) {
		for (unsigned int j = 0;
		tetr[controls.curr_tetr].piece[i][j]; j++) {
			game_board[i + decal->y][j + decal->x] =
			(tetr[controls.curr_tetr].piece[i][j] == '*' ?
			tetr[controls.curr_tetr].info.color :
			game_board[i + decal->y][j + decal->x]);
		}
	}
	decal->x = 0;
	decal->y = 0;
}
