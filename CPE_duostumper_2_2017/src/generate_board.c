/*
** EPITECH PROJECT, 2018
** generate_board.c
** File description:
** generating the game board
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/proto.h"

void generate_game_env(grid_info_t infos)
{
	char *line = NULL;
	size_t len = 0;
	char **board = create_board(infos);
	char ch[2] = {infos.p1, infos.p2};

	for (int stop = 0, player = 0, error = 0; stop != 1; error = 0) {
		printf("Player %c, where do you want to play: ", ch[player]);
		getline(&line, &len, stdin);
		error = parse_line(line, infos, board, ch[player]);
		if (player == 0)
			player = player == 0 && error == 0 ? 1 : 0;
		else
			player = player == 1 && error == 0 ? 0 : 1;
		display_pipe(&infos, board);
	}
	free(line);
}

char **create_board(grid_info_t infos)
{
	char **board = malloc(sizeof(char *) * (infos.height + 1));

	if (!board)
		return (NULL);
	for (int i = 0; i < infos.height; i++) {
		board[i] = malloc(sizeof(char) * (infos.width + 1));
		if (!board[i])
			return (NULL);
		for (int j = 0; j < infos.width; j++)
			board[i][j] = '.';
		board[i][infos.width] = 0;
	}
	board[infos.height] = NULL;
	return (board);
}

int parse_line(char *line, grid_info_t infos,
	char **board, char player)
{
	unsigned int i = 0;
	int row = 0;

	for (; line[i] && line[i] != '\n'; i++);
	line[i] = line[i] == '\n' ? 0 : line[i];
	if (is_number(line) == -1)
		return (-1);
	row = atoi(line);
	if (row <= 0 || row > infos.width)
		return (-1);
	if (board[0][row - 1] != '.')
		return (-1);
	update_board(row - 1, player, board);
	return (0);
}

void update_board(int input, char player, char **board)
{
	for (int i = -1, stop = 0; stop != 1;) {
		i++;
		if (!board[i] || board[i][input] != '.') {
			board[i - 1][input] = player;
			stop = 1;
		}
	}
}
