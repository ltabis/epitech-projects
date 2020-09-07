/*
** EPITECH PROJECT, 2017
** key_handling_gameplay_bis.c
** File description:
** verification for stuck boxes
*/
#include <stdlib.h>
#include <ncurses.h>
#include "include/my.h"
#include "include/proto.h"

map_t *mv_p_left_check_bis(map_t *map)
{
	map->x_file[map->p_pos_y][map->p_pos_x - 2] = 'X';
	map->p_pos_x--;
	if (map->x_file[map->p_pos_y][map->p_pos_x - 2] == '#' &&
	(map->x_file[map->p_pos_y + 1][map->p_pos_x - 1] == '#' ||
	map->x_file[map->p_pos_y + 1][map->p_pos_x - 1] == 'X'))
		map->boxes_stuck++;
	else if (map->x_file[map->p_pos_y][map->p_pos_x - 2] == '#' &&
	(map->x_file[map->p_pos_y - 1][map->p_pos_x - 1] == '#' ||
	map->x_file[map->p_pos_y - 1][map->p_pos_x - 1] == 'X'))
		map->boxes_stuck++;
	return (map);
}

map_t *mv_p_up_check_bis(map_t *map)
{
	map->x_file[map->p_pos_y - 2][map->p_pos_x] = 'X';
	map->p_pos_y--;
	if (map->x_file[map->p_pos_y - 2][map->p_pos_x] == '#' &&
	(map->x_file[map->p_pos_y - 1][map->p_pos_x + 1] == '#' ||
	map->x_file[map->p_pos_y - 1][map->p_pos_x + 1] == 'X'))
		map->boxes_stuck++;
	else if (map->x_file[map->p_pos_y - 2][map->p_pos_x] == '#' &&
	(map->x_file[map->p_pos_y - 1][map->p_pos_x - 1] == '#' ||
	 map->x_file[map->p_pos_y - 1][map->p_pos_x - 1] == 'X'))
		map->boxes_stuck++;
	return (map);
}

map_t *mv_p_right_check_bis(map_t *map)
{
	map->x_file[map->p_pos_y][map->p_pos_x + 2] = 'X';
	map->p_pos_x++;
	if (map->x_file[map->p_pos_y][map->p_pos_x + 2] == '#' &&
	(map->x_file[map->p_pos_y - 1][map->p_pos_x + 1] == '#' ||
	map->x_file[map->p_pos_y - 1][map->p_pos_x + 1] == 'X'))
		map->boxes_stuck++;
	else if (map->x_file[map->p_pos_y][map->p_pos_x + 2] == '#' &&
	(map->x_file[map->p_pos_y + 1][map->p_pos_x + 1] == '#' ||
	map->x_file[map->p_pos_y + 1][map->p_pos_x + 1] == 'X'))
		map->boxes_stuck++;
	return (map);
}

map_t *mv_p_down_check_bis(map_t *map)
{
	map->x_file[map->p_pos_y + 2][map->p_pos_x] = 'X';
	map->p_pos_y++;
	if (map->x_file[map->p_pos_y + 2][map->p_pos_x] == '#' &&
	(map->x_file[map->p_pos_y + 1][map->p_pos_x + 1] == '#' ||
	map->x_file[map->p_pos_y + 1][map->p_pos_x + 1] == 'X'))
		map->boxes_stuck++;
	else if (map->x_file[map->p_pos_y + 2][map->p_pos_x] == '#' &&
	(map->x_file[map->p_pos_y + 1][map->p_pos_x - 1] == '#' ||
	map->x_file[map->p_pos_y + 1][map->p_pos_x - 1] == 'X'))
		map->boxes_stuck++;
	return (map);
}

void display_game_loose(map_t *map)
{
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
	free(map);
	refresh();
	endwin();
	exit(1);
}
