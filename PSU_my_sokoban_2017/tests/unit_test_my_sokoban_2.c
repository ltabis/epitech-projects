/*
** EPITECH PROJECT, 2017
** unit_test_my_sokoban_2.c
** File description:
** second part of the unit testing
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "../include/proto.h"
#include "../include/my.h"

Test(sokoban_test, check_box_colision)
{
	map_t *map = malloc(sizeof(map_t));
	map->sc = malloc(sizeof(score));

	if (!map || !map->sc)
		exit(84);
	map = initialise_values(map);
	verify_file_stat("./map3.txt");
	map = find_widht_and_height(map, "./map3.txt");
	map->p_pos_x = map->p_pos_x_base - 1;
	map->p_pos_y = map->p_pos_y_base;
	map = load_2d_arr_from_file("./map3.txt", map);
	map = mv_p_right(map);
	cr_assert_eq(map->p_pos_x, 4);
	cr_assert_eq(map->p_pos_y, 1);
	cr_assert_eq(map->x_file[1][4], 'P');
	cr_assert_eq(map->x_file[1][5], 'X');
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
}

Test(sokoban_test, check_memory_allocation_col)
{
	int i = allocate_memory(10, "./map1.txt");
	cr_assert_eq(i, 12);
}

Test(sokoban_test, check_move_around_box_left)
{
	map_t *map = malloc(sizeof(map_t));
	map->sc = malloc(sizeof(score));

	if (!map || !map->sc)
		exit(84);
	map = initialise_values(map);
	verify_file_stat("./map5.txt");
	map = find_widht_and_height(map, "./map5.txt");
	map->p_pos_x = map->p_pos_x_base - 1;
	map->p_pos_y = map->p_pos_y_base;
	map = load_2d_arr_from_file("./map5.txt", map);
	map = mv_p_left(map);
	cr_assert_eq(map->x_file[1][2], 'P');
	cr_assert_eq(map->x_file[1][1], 'X');
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
}

Test(sokoban_test, check_move_around_box_up)
{
	map_t *map = malloc(sizeof(map_t));
	map->sc = malloc(sizeof(score));

	if (!map || !map->sc)
		exit(84);
	map = initialise_values(map);
	verify_file_stat("./map6.txt");
	map = find_widht_and_height(map, "./map6.txt");
	map->p_pos_x = map->p_pos_x_base - 1;
	map->p_pos_y = map->p_pos_y_base;
	map = load_2d_arr_from_file("./map6.txt", map);
	map = mv_p_up(map);
	cr_assert_eq(map->x_file[2][1], 'P');
	cr_assert_eq(map->x_file[1][1], 'X');
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
}
