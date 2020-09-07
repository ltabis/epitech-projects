/*
** EPITECH PROJECT, 2018
** rotate
** File description:
** rotate
*/

#include "tetris.h"

int found_max(char **str)
{
	int j = 0;
	int max = 0;

	for (int i = 0; str[i]; i++) {
		for (; str[i][j]; j++);
		if (j > max)
			max = j;
		j = 0;
	}
	for (; str[0][j]; j++);
	if (str[0][j - 1] == '\n')
		return (max - 1);
	else
		return (max);
}

int get_absolute_value(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void do_my_rotate(char **piece, char **new, int max_x)
{
	int x = 0;
	int y = 0;

	for (int i = 0; piece[i]; i++) {
		for (int j = 0; piece[i][j] != '\n' && piece[i][j]; j++) {
			x = i;
			y = j - (max_x - 1);
			y = get_absolute_value(y);
			new[y][x] = piece[i][j];
		}
	}
}

char **my_rotate(tetrimino_t t)
{
	char **new = NULL;
	int max_x = found_max(t.piece);
	int max_y = 0;

	for (; t.piece[max_y]; max_y++);
	new = malloc(sizeof(char *) * (max_x + 1));
	if (!new)
		exit(84);
	for (int i = 0; i < max_x; i++) {
		new[i] = malloc(sizeof(char) * (max_y + 1));
		if (!new[i])
			exit(84);
		for (int j = 0; j < max_y; j++)
			new[i][j] = ' ';
		new[i][max_y] = 0;
	}
	new[max_x] = 0;
	do_my_rotate(t.piece, new, max_x);
	return (new);
}
