/*
** EPITECH PROJECT, 2018
** main_generation.c
** File description:
** main generation of the maze
*/

#include <string.h>
#include <time.h>
#include "generator.h"

char *generate_maze(int x, int y, char *mode)
{
	register char *maze = malloc(sizeof(char) * (y * (x + 1)));
	cell_t *cells = NULL;

	srand(time(NULL));
	for (int i = 0; i < y * (x + 1) - 1; i++)
		maze[i] = (i + 1) % (x + 1) == 0 ? '\n' : 'X';
	maze[y * (x + 1) - 2] = '*';
	maze[0] = '*';
	maze[y * (x + 1) - 1] = 0;
	if ((cells = create_first_cell()) == NULL)
		return (NULL);
	if (mode && strcmp("perfect", mode) == 0)
		modify_perfect_maze(x, y, maze, cells);
	else
		modify_inperfect_maze(x, y, maze, cells);
	return (maze);
}

cell_t *create_first_cell(void)
{
	cell_t *cell = malloc(sizeof(cell_t));

	if (!cell)
		return (NULL);
	cell->idx = 0;
	cell->prev = NULL;
	return (cell);
}

cell_t *create_new_cell(unsigned int idx, cell_t *cells)
{
	cell_t *new_cell = malloc(sizeof(cell_t));

	if (!new_cell)
		return (NULL);
	new_cell->idx = idx;
	new_cell->prev = cells;
	return (new_cell);
}

cell_t *choose_destroy_or_end(char *maze, cell_t *cell,
	coords_t coords, int *random_way)
{
	cell_t *(*destroy_wall[2])(char *, cell_t *, int) =
	{
		destroy_left_wall_end,
		destroy_upper_wall_end
	};

	if (coords.y < 0)
		cell = (*destroy_wall[random_way[rand() % (coords.y * -1)]])
		(maze, cell, coords.x);
	else
		cell = put_last_way(maze, cell, coords);
	return (cell);
}

cell_t *put_last_way(char *maze, cell_t *cell, coords_t coords)
{
	if (cell->idx + 2 < coords.x && maze[cell->idx + 2] == '*')
		maze[cell->idx + 1] = '*';
	else if (cell->idx - 2 >= 0 && maze[cell->idx - 2] == '*')
		maze[cell->idx - 1] = '*';
	else if (cell->idx + (2 * coords.x + 2) < coords.y * (coords.x + 1) &&
	maze[cell->idx + (2 * coords.x + 2)] == '*')
		maze[cell->idx + coords.x + 1] = '*';
	else if (cell->idx - (2 * coords.x + 2) >= 0 &&
	maze[cell->idx - (2 * coords.x + 2)] == '*')
		maze[cell->idx - (coords.x + 1)] = '*';
	free_tree(cell);
	return (NULL);
}
