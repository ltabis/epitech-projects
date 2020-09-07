/*
** EPITECH PROJECT, 2018
** compute_gameplay_3.c
** File description:
** gameplay computing
*/

#include "tetris.h"

void check_lines(char **game_board, control_t controls, int *score)
{
	int stock_y = 0;
	int decal = 0;

	for (; game_board[stock_y] &&
	decal != controls.map_size.x - 2; stock_y++) {
		decal = 0;
		for (unsigned int j = 0;
		game_board[stock_y][j] && decal != controls.map_size.x - 2; j++)
			decal += (game_board[stock_y][j] != -1 ? 1 : 0);
	}
	if (decal == controls.map_size.x - 2)
		lower_lines(game_board, stock_y, controls, score);
}

void lower_lines(char **game_board, int stock_y, control_t controls, int *score)
{
	for (; stock_y > 1; stock_y--)
		for (int j = 1; j < controls.map_size.x - 1 ; j++) {
			game_board[stock_y][j] = game_board[stock_y - 1][j];
		}
	*score += 10;
}

control_t check_end_game(control_t ctrl, tetrimino_t *tetr, char **game_board)
{
	char end = 0;

	for (unsigned int i = 0;
	tetr[ctrl.curr_tetr].piece[i] && end != 1; i++) {
		for (unsigned int j = 0;
		tetr[ctrl.curr_tetr].piece[i][j] && end != 1; j++) {
			end = (tetr[ctrl.curr_tetr].piece[i][j] == '*' &&
			game_board[i][j + 1] != -1 ? 1 : 0);
		}
	}
	if (end == 1)
		ctrl.pass = 2;
	return (ctrl);
}
