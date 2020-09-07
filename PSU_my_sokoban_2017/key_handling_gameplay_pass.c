/*
** EPITECH PROJECT, 2017
** key_handling_gameplay_pass.c
** File description:
** when the player walks on 'O'
*/
#include <ncurses.h>
#include "include/my.h"
#include "include/proto.h"

map_t *mv_p_left_pass(map_t *map)
{
	if (map->x_file[map->p_pos_y][map->p_pos_x - 1] != 'X') {
		map->pos_x_cir = map->p_pos_x - 1;
		map->pos_y_cir = map->p_pos_y;
		map->x_file[map->p_pos_y][map->p_pos_x - 1] = 'P';
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->p_pos_x--;
	}
	return (map);
}

map_t *mv_p_up_pass(map_t *map)
{
	if (map->x_file[map->p_pos_y - 1][map->p_pos_x] != 'X') {
		map->pos_x_cir = map->p_pos_x;
		map->pos_y_cir = map->p_pos_y - 1;
		map->x_file[map->p_pos_y - 1][map->p_pos_x] = 'P';
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->p_pos_y--;
	}
	return (map);
}

map_t *mv_p_right_pass(map_t *map)
{
	if (map->x_file[map->p_pos_y][map->p_pos_x + 1] != 'X') {
		map->pos_x_cir = map->p_pos_x + 1;
		map->pos_y_cir = map->p_pos_y;
		map->x_file[map->p_pos_y][map->p_pos_x + 1] = 'P';
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->p_pos_x++;
	}
	return (map);
}

map_t *mv_p_down_pass(map_t *map)
{
	if (map->x_file[map->p_pos_y + 1][map->p_pos_x] != 'X') {
		map->pos_x_cir = map->p_pos_x;
		map->pos_y_cir = map->p_pos_y + 1;
		map->x_file[map->p_pos_y + 1][map->p_pos_x] = 'P';
		map->x_file[map->p_pos_y][map->p_pos_x] = ' ';
		map->p_pos_y++;
	}
	return (map);
}
