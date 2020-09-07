/*
** EPITECH PROJECT, 2018
** generate_perfect_maze.c
** File description:
** generating a perfect maze
*/

#include "generator.h"

void modify_perfect_maze(int x, int y, char *maze, cell_t *cells)
{
	cell_t *last_cell = create_first_cell();

	last_cell->idx = y * (x + 1) - 2;
	for (unsigned int i = 0; i == 0 || cells->prev; i++)
		cells = choose_random_way(x, y, maze, cells);
	free_tree(cells);
	while (last_cell)
		last_cell = choose_random_last(x, y, maze, last_cell);
	fill_last_walls(y, x, maze);
}

cell_t *choose_random_way(int x, int y, char *maze, cell_t *cell)
{
	int random_way[4] = {-1, -1, -1, -1};
	int av_wall = 0;
	coords_t coords = {y, x};

	if (cell->idx + 2 < y * (x + 1) && maze[cell->idx] != '\n' &&
	maze[cell->idx + 1] != '\n' && maze[cell->idx + 2] == 'X')
		random_way[av_wall++] = 0;
	if (cell->idx - 2 >= 0 && maze[cell->idx] != '\n' &&
	maze[cell->idx - 1] != '\n' && maze[cell->idx - 2] == 'X')
		random_way[av_wall++] = 1;
	if (cell->idx + (2 * x + 2) < y * (x + 1) &&
	maze[cell->idx + (2 * x + 2)] == 'X')
		random_way[av_wall++] = 2;
	if (cell->idx - (2 * x + 2) >= 0 &&
	maze[cell->idx - (2 * x + 2)] == 'X')
		random_way[av_wall++] = 3;
	coords = av_wall != 0 ? (coords_t){-1 * av_wall, coords.x} : coords;
	cell = choose_destroy_or_backtrack(maze, cell, coords, random_way);
	return (cell);
}

cell_t *choose_random_last(int x, int y, char *maze, cell_t *cell)
{
	int random_way[4] = {-1, -1};
	int av_wall = 0;
	coords_t coords = {y, x};

	if (cell->idx - 1 >= 0 && maze[cell->idx - 1] == 'X' &&
	maze[cell->idx - (x + 1)] != '*')
		random_way[av_wall++] = 0;
	if (cell->idx - (x + 1) >= 0 && maze[cell->idx - (x + 1)] == 'X' &&
	maze[cell->idx - 1] != '*')
		random_way[av_wall++] = 1;
	coords = av_wall != 0 ? (coords_t){-1 * av_wall, coords.x} : coords;
	cell = choose_destroy_or_end(maze, cell, coords, random_way);
	return (cell);
}

cell_t *choose_destroy_or_backtrack(char *maze, cell_t *cell,
	coords_t coords, int *random_way)
{
	cell_t *(*destroy_wall[4])(char *, cell_t *, int) =
	{
		destroy_right_wall, destroy_left_wall,
		destroy_below_wall, destroy_upper_wall
	};

	if (coords.y < 0)
		cell = (*destroy_wall[random_way[rand() % (coords.y * -1)]])
		(maze, cell, coords.x);
	else
		cell = get_back_to_previous_cell(maze, cell, coords);
	return (cell);
}

cell_t *get_back_to_previous_cell(char *maze, cell_t *cell, coords_t crds)
{
	cell_t *tmp = cell;

	for (; cell->prev; tmp = cell) {
		if (cell->idx + 2 < crds.y * (crds.x + 1) &&
		maze[cell->idx] != '\n' &&
		maze[cell->idx + 1] != '\n' && maze[cell->idx + 2] == 'X')
			return (cell);
		if (cell->idx - 2 >= 0 && maze[cell->idx] != '\n' &&
		maze[cell->idx - 1] != '\n' && maze[cell->idx - 2] == 'X')
			return (cell);
		if (cell->idx + (2 * crds.x + 2) < crds.y * (crds.x + 1) &&
		maze[cell->idx + (2 * crds.x + 2)] == 'X')
			return (cell);
		if (cell->idx - (2 * crds.x + 2) >= 0 &&
		maze[cell->idx - (2 * crds.x + 2)] == 'X')
			return (cell);
		cell = cell->prev;
		free(tmp);
	}
	return (cell);
}
