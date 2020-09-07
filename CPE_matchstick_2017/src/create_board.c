/*
** EPITECH PROJECT, 2018
** create_board.c
** File description:
** functions that will create the board
*/
#include <stdlib.h>
#include "../include/proto.h"

int create_game_environnement(char *arg_1, char *arg_2)
{
	unsigned int nb_lines = (unsigned int)my_getnbr(arg_1);
	unsigned int nb_matchs = (unsigned int)my_getnbr(arg_2);
	unsigned char *board;
	int error = 0;

	if ((nb_lines <= 1 || nb_lines >= 100) || nb_matchs < 1)
		return (-1);
	board = create_game_board(nb_lines);
	if (!board)
		return (-1);
	error = main_loop(board, nb_matchs, nb_lines);
	free(board);
	if (error == -1)
		return (-1);
	return (error);
}

unsigned char *create_game_board(unsigned int ln)
{
	unsigned int i = 0;
	unsigned char *board = malloc(sizeof(unsigned char) * ln);

	if (!board)
		return (NULL);
	for (unsigned int matchs = 1; i < ln ; i++, matchs += 2)
		board[i] = matchs;
	return (board);
}
