/*
** EPITECH PROJECT, 2017
** key_handling.c
** File description:
** functions that handle the input
*/
#include <ncurses.h>
#include "include/my.h"
#include "include/proto.h"

map_t *mv_p_left(map_t *map)
{
	if (map->x_file[map->p_pos_y][map->p_pos_x - 1] == 'O')
		map = mv_p_left_pass(map);
	else if (map->x_file[map->p_pos_y][map->p_pos_x - 1] != '#') {
		map = mv_p_left_check(map);
		map->pos_x_cir = 0;
		map->pos_y_cir = 0;
	}
	werase(stdscr);
	display_game(map);
	refresh();
	return (map);
}

map_t *mv_p_up(map_t *map)
{
	if (map->x_file[map->p_pos_y - 1][map->p_pos_x] == 'O')
		map = mv_p_up_pass(map);
	else if (map->x_file[map->p_pos_y - 1][map->p_pos_x] != '#') {
		map = mv_p_up_check(map);
		map->pos_x_cir = 0;
		map->pos_y_cir = 0;
	}
	werase(stdscr);
	display_game(map);
	refresh();
	return (map);
}

map_t *mv_p_right(map_t *map)
{
	if (map->x_file[map->p_pos_y][map->p_pos_x + 1] == 'O')
		map = mv_p_right_pass(map);
	else if (map->x_file[map->p_pos_y][map->p_pos_x + 1] != '#') {
		map = mv_p_right_check(map);
		map->pos_x_cir = 0;
		map->pos_y_cir = 0;
	}
	werase(stdscr);
	display_game(map);
	refresh();
	return (map);
}

map_t *mv_p_down(map_t *map)
{
	if (map->x_file[map->p_pos_y + 1][map->p_pos_x] == 'O')
		map = mv_p_down_pass(map);
	else if (map->x_file[map->p_pos_y + 1][map->p_pos_x] != '#') {
		map = mv_p_down_check(map);
		map->pos_x_cir = 0;
		map->pos_y_cir = 0;
	}
	werase(stdscr);
	display_game(map);
	refresh();
	return (map);
}

map_t *mv_space(map_t *map)
{
	map = mv_p_space_check(map);
	return (map);
}
