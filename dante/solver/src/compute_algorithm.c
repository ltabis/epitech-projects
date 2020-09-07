/*
** EPITECH PROJECT, 2018
** compute_algorithm.c
** File description:
** main file for generator
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "solver.h"

void choose_and_compute_algorithm(char **av)
{
	char *maze = start_wall_algorithm(av[1]);

	if (maze) {
		write(1, maze, strlen(maze));
		free(maze);
	}
}

char *start_wall_algorithm(char *filepath)
{
	coords_t lim = {1, 0};
	char *maze = NULL;
	char *line = NULL;
	size_t len = 0;
	FILE *stm = fopen(filepath, "r");

	if (!stm || getline(&maze, &len, stm) == -1)
		return (NULL);
	for (lim.x = strlen(maze) - 1; getline(&line, &len, stm) != -1; lim.y++)
		maze = my_strcat(maze, line);
	free(line);
	fclose(stm);
	if (compute_wall_algorithm(maze, &lim, 0) == 0) {
		printf("no solution found\n");
		free(maze);
		return (NULL);
	}
	for (unsigned int i = 0; maze[i]; i++)
		maze[i] = maze[i] == 'z' ? '*' : maze[i];
	return (maze);
}

char compute_wall_algorithm(char *maze, coords_t *lim, int pos)
{
	if (strlen(maze) == 1 && maze[0] == '*') {
		maze[0] = 'o';
		return (1);
	} else if (maze[0] == 'X')
		return (0);
	for (char first = 0; pos != (lim->x + 1) * lim->y - 2;) {
		if (first != 0 && pos == 0)
			return (0);
		pos = is_open(maze, lim, pos);
		first = 1;
	}
	maze[(lim->x + 1) * lim->y - 2] = 'o';
	return (1);
}

int is_open(char *maze, coords_t *lim, int pos)
{
	if (pos - (lim->x + 1) >= 0 && maze[pos - (lim->x + 1)] == '*') {
		maze[pos] = 'o';
		pos -= (lim->x + 1);
	} else if (pos + 1 < lim->y * (lim->x + 1) && maze[pos + 1] == '*') {
		maze[pos++] = 'o';
	} else if (pos + (lim->x + 1) < lim->y * (lim->x + 1) &&
	maze[pos + (lim->x + 1)] == '*') {
		maze[pos] = 'o';
		pos += (lim->x + 1);
	} else if (pos - 1 >= 0 && maze[pos - 1] == '*') {
		maze[pos--] = 'o';
	} else if (pos != (lim->x + 1) * lim->y - 2)
		pos = backtrack(maze, lim, pos);
	return (pos);
}

int backtrack(char *maze, coords_t *lim, int pos)
{
	if (pos - (lim->x + 1) >= 0 && maze[pos - (lim->x + 1)] == 'o') {
		maze[pos] = 'z';
		pos -= (lim->x + 1);
	} else if (pos + 1 < lim->y * (lim->x + 1) && maze[pos + 1] == 'o') {
		maze[pos++] = 'z';
	} else if (pos + (lim->x + 1) < lim->y * (lim->x + 1) &&
	maze[pos + (lim->x + 1)] == 'o') {
		maze[pos] = 'z';
		pos += (lim->x + 1);
	} else if (pos - 1 >= 0 && maze[pos - 1] == 'o')
		maze[pos--] = 'z';
	return (pos);
}
