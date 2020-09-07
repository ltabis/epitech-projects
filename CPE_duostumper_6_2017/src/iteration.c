/*
** EPITECH PROJECT, 2018
** iteration.c
** File description:
** doing as many iteration as the user want
*/

#include "proto.h"

int repeat_iteration(grid_info_t *info, int iteration)
{
	for (int i = 0; i < iteration; i++) {
		if (update_new_iteration(info) == -1)
			return (-1);
		free_old_grid(info);
		info->grid = info->new_grid;
	}
	display_grid(info);
	free_old_grid(info);
	return (0);
}

void display_grid(grid_info_t *info)
{
	for (unsigned int i = 0; i < info->y; i++)
		printf("%s\n", info->grid[i]);
}

int update_new_iteration(grid_info_t *info)
{
	if (!(info->new_grid = copy_grid(info)))
		return (-1);
	for (unsigned int i = 0; i < info->y; i++)
		for (unsigned int j = 0; info->grid[i][j]; j++)
			count_cells(info, j, i);
	return (0);
}

void count_cells(grid_info_t *info, unsigned int x, unsigned int y)
{
	int curr_x = x - 1;
	int curr_y = y - 1;
	unsigned int cells = 0;

	for (char i = 0, j = 0; i < 3; i++, curr_y++) {
		for (j = 0, curr_x = x - 1; j < 3; j++, curr_x++) {
			cells += curr_x < (int)info->x && curr_x >= 0 &&
			curr_y < (int)info->y && curr_y >= 0 &&
			(curr_y != (int)y || curr_x != (int)x) &&
			info->grid[curr_y][curr_x] == 'X' ? 1 : 0;
		}
	}
	update_grid(info, x, y, cells);
}

void free_old_grid(grid_info_t *info)
{
	for (unsigned int i = 0; i < info->y; i++)
		free(info->grid[i]);
	free(info->grid);
}
