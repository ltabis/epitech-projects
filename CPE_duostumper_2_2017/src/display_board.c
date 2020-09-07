/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** display board
*/

#include "../include/proto.h"
#include <unistd.h>
#include <stdio.h>

void display_first_line(grid_info_t *var)
{
	int i = 0;

	for (; i < var->width + 2; i++)
		write(1, "+", 1);
	write(1, "\n", 1);
}

void display_pipe(grid_info_t *var, char **board)
{
	display_first_line(var);
	for (int i = 0; i < var->height; i++) {
		write(1, "|", 1);
		write(1, board[i], var->width);
		write(1, "|\n", 2);
	}
	display_first_line(var);
}
