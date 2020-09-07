/*
** EPITECH PROJECT, 2018
** check sort
** File description:
** check if the tab is sorted
*/

#include "../include/tetris.h"

int check_sort(char **names)
{
	unsigned int sort = 0;
	unsigned int i = 0;

	for (unsigned int j = 0; names[i + 1]; i++) {
		j = 0;
		for (; names[i][j] == names[i + 1][j] &&
		names[i + 1][j]; j++);
		(names[i][j] < names[i + 1][j] ? sort++ : 0);
	}
	return (sort == i ? 1 : 0);
}
