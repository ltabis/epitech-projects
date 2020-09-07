/*
** EPITECH PROJECT, 2018
** check_cells.c
** File description:
** check the cells around empty square
*/

#include "proto.h"

void update_grid(grid_info_t *info, unsigned int x,
	unsigned int y, unsigned int cells)
{
	if (info->grid[y][x] == '.' && cells == 3)
		info->new_grid[y][x] = 'X';
	else if (info->grid[y][x] == 'X' && cells <= 1)
		info->new_grid[y][x] = '.';
	else if (info->grid[y][x] == 'X' && cells >= 4)
		info->new_grid[y][x] = '.';
	else
		info->new_grid[y][x] = info->grid[y][x];
}

char **copy_grid(grid_info_t *info)
{
	char **new_map = malloc(sizeof(char *) * (info->y + 1));

	if (!new_map)
		return (NULL);
	for (unsigned int i = 0; info->grid[i]; i++) {
		new_map[i] = malloc(sizeof(char) * info->x);
		if (!new_map[i])
			return (NULL);
		for (unsigned int j = 0; j < info->x; j++)
			new_map[i][j] = 0;
		new_map[i][info->x - 1] = 0;
	}
	new_map[info->y] = NULL;
	return (new_map);
}

int check_map_error(grid_info_t *info)
{
	char trig = 0;

	for (unsigned int i = 0; i < info->y && trig != 1; i++)
		for (unsigned int j = 0; j < info->x && trig != 1; j++)
			trig = info->grid[i][j] != '.' &&
			info->grid[i][j] != 'X' &&
			info->grid[i][j] != 0 ? 1 : 0;
	return (trig == 1 ? -1 : 0);
}
