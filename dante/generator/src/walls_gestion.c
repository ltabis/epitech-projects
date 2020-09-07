/*
** EPITECH PROJECT, 2018
** walls_gestion.c
** File description:
** destroying walls when needed
*/

#include "generator.h"

cell_t *destroy_left_wall(char *maze, cell_t *cells,
	__attribute__ ((unused)) int x)
{
	maze[cells->idx - 1] = '*';
	maze[cells->idx - 2] = '*';
	cells = create_new_cell(cells->idx - 2, cells);
	return (cells);
}

cell_t *destroy_right_wall(char *maze, cell_t *cells,
	__attribute__ ((unused)) int x)
{
	maze[cells->idx + 1] = '*';
	maze[cells->idx + 2] = '*';
	cells = create_new_cell(cells->idx + 2, cells);
	return (cells);
}

cell_t *destroy_upper_wall(char *maze, cell_t *cells, int x)
{
	maze[cells->idx - (x + 1)] = '*';
	maze[cells->idx - (2 * x + 2)] = '*';
	cells = create_new_cell(cells->idx - (2 * x + 2), cells);
	return (cells);
}

cell_t *destroy_below_wall(char *maze, cell_t *cells, int x)
{
	maze[cells->idx + (x + 1)] = '*';
	maze[cells->idx + (2 * x + 2)] = '*';
	cells = create_new_cell(cells->idx + (2 * x + 2), cells);
	return (cells);
}
