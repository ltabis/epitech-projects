/*
** EPITECH PROJECT, 2018
** generate_perfect_maze.c
** File description:
** generating a perfect maze
*/

#include "generator.h"

void modify_inperfect_maze(int x, int y, char *maze, cell_t *cells)
{
	coords_t coords = {y, x};

	modify_perfect_maze(x, y, maze, cells);
	for (int i = 0; i < (x * y) / 4; i++)
		choose_random_place(rand() % y, rand() % x, maze, coords);
}

void choose_random_place(int y, int x, char *maze, coords_t coords)
{
	y = y == coords.y ? y - 1 : y;
	x = x == coords.x ? x - 1 : x;
	if (maze[y * coords.x + x] == 'X' &&
	((x + 1 < coords.x && maze[y * coords.x + (x + 1)] != '\n') ||
	(x - 1 >= 0 && maze[y * coords.x + (x - 1)] != '\n') ||
	(y + 1 < coords.y && maze[(y + 1) * coords.x + x] != '\n') ||
	(y - 1 >= 0 && maze[(y - 1)* coords.x + x] != '\n')))
		maze[y * coords.x + x] = '*';
}

void fill_last_walls(int y, int x, char *maze)
{
	for (int i = 0, random = 0; i < x / 2 && y != 1 && x != 1; i++) {
		random = rand() % x - 1;
		if ((y - 2) * (x + 1) + random + 1 < y * (x + 1) &&
		(y - 2) * (x + 1) + random - 1 >= 0 &&
		maze[(y - 2) * (x + 1) + random] == '*' &&
		maze[(y - 1) * (x + 1) + random - 1] != '*' &&
		maze[(y - 1) * (x + 1) + random + 1] != '*')
			maze[(y - 1) * (x + 1) + random] = '*';
	}
	for (int i = 0, random = 0; i < y / 2; i++) {
		random = rand() % y - 1;
		if ((random - 1) * (x + 1) - 3 > 0 &&
		(random + 1) * (x + 1) - 3 < y * (x + 1) &&
		maze[random * (x + 1) - 3] == '*' &&
		maze[(random + 1) * (x + 1) - 2] != '*' &&
		maze[(random - 1) * (x + 1) - 2] != '*')
			maze[random * (x + 1) - 2] = '*';
	}
}
