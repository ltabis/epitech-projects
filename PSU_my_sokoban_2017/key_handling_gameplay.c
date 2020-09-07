/*
** EPITECH PROJECT, 2017
** key_handling_gameplay.c
** File description:
** what appens in ceratain conditions
*/
#include <ncurses.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/proto.h"

map_t *mv_p_left_check(map_t *map)
{
	if (map->x_file[map->p_pos_y][map->p_pos_x - 1] == 'X' &&
	map->x_file[map->p_pos_y][map->p_pos_x - 2] == ' ') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y][map->p_pos_x - 1] = 'P';
		map = mv_p_left_check_bis(map);
	} else if (map->x_file[map->p_pos_y][map->p_pos_x - 1] == 'X' &&
		map->x_file[map->p_pos_y][map->p_pos_x - 2] == 'O') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y][map->p_pos_x - 1] = 'P';
		map->x_file[map->p_pos_y][map->p_pos_x - 2] = 'X';
		map->p_pos_x--;
	} else if (map->x_file[map->p_pos_y][map->p_pos_x - 1] == ' ') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y][map->p_pos_x - 1] = 'P';
		map->p_pos_x--;
	}
	return (map);
}

map_t *mv_p_up_check(map_t *map)
{
	if (map->x_file[map->p_pos_y - 1][map->p_pos_x] == 'X' &&
	map->x_file[map->p_pos_y - 2][map->p_pos_x] == ' ') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y - 1][map->p_pos_x] = 'P';
		map = mv_p_up_check_bis(map);
	} else if (map->x_file[map->p_pos_y - 1][map->p_pos_x] == 'X' &&
	map->x_file[map->p_pos_y - 2][map->p_pos_x] == 'O') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y - 1][map->p_pos_x] = 'P';
		map->x_file[map->p_pos_y - 2][map->p_pos_x] = 'X';
		map->p_pos_y--;
	} else if (map->x_file[map->p_pos_y - 1][map->p_pos_x] == ' ') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y - 1][map->p_pos_x] = 'P';
		map->p_pos_y--;
	}
	return (map);
}

map_t *mv_p_right_check(map_t *map)
{
	if (map->x_file[map->p_pos_y][map->p_pos_x + 1] == 'X' &&
	map->x_file[map->p_pos_y][map->p_pos_x + 2] == ' ') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y][map->p_pos_x + 1] = 'P';
		map = mv_p_right_check_bis(map);
	} else if (map->x_file[map->p_pos_y][map->p_pos_x + 1] == 'X' &&
	map->x_file[map->p_pos_y][map->p_pos_x + 2] == 'O') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y][map->p_pos_x + 1] = 'P';
		map->x_file[map->p_pos_y][map->p_pos_x + 2] = 'X';
		map->p_pos_x++;
	} else if (map->x_file[map->p_pos_y][map->p_pos_x + 1] == ' ') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y][map->p_pos_x + 1] = 'P';
		map->p_pos_x++;
	}
	return (map);
}

map_t *mv_p_down_check(map_t *map)
{
	if (map->x_file[map->p_pos_y + 1][map->p_pos_x] == 'X' &&
	map->x_file[map->p_pos_y + 2][map->p_pos_x] == ' ') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y + 1][map->p_pos_x] = 'P';
		map = mv_p_down_check_bis(map);
	} else if (map->x_file[map->p_pos_y + 1][map->p_pos_x] == 'X' &&
	map->x_file[map->p_pos_y + 2][map->p_pos_x] == 'O') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y + 1][map->p_pos_x] = 'P';
		map->x_file[map->p_pos_y + 2][map->p_pos_x] = 'X';
		map->p_pos_y++;
	} else if (map->x_file[map->p_pos_y + 1][map->p_pos_x] == ' ') {
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->x_file[map->p_pos_y + 1][map->p_pos_x] = 'P';
		map->p_pos_y++;
	}
	return (map);
}

map_t *mv_p_space_check(map_t *map)
{
	int i = 0;

	map->p_pos_y = map->p_pos_y_base;
	map->p_pos_x = map->p_pos_x_base - 1;
	for (; i < map->y; i++)
		my_strcpy(map->x_file[i], map->x_file_save[i]);
	map->boxes_stuck = 0;
	map->boxes = map->score_goal;
	return (map);
}
