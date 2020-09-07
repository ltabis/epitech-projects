/*
** EPITECH PROJECT, 2017
** unit_test_my_sokoban.c
** File description:
** unti tests for my_sokoban
*/
#include <criterion/criterion.h>
#include <stdlib.h>
#include "../include/proto.h"
#include "../include/my.h"

Test(sokoban_test, check_player_position_map_1)
{
	map_t *map = malloc(sizeof(map_t));
	map->sc = malloc(sizeof(score));

	if (!map || !map->sc)
		exit(84);
	map = initialise_values(map);
	verify_file_stat("./map4.txt");
	map = find_widht_and_height(map, "./map4.txt");
	map = load_2d_arr_from_file("./map4.txt", map);
	cr_assert_neq(map, NULL);
	cr_assert_eq(map->p_pos_y_base, 1);
	cr_assert_eq(map->p_pos_x_base, 7);
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
	free(map);
}

Test(sokoban_test, check_player_position_map_2)
{
	map_t *map = malloc(sizeof(map_t));
	map->sc = malloc(sizeof(score));

	if (!map || !map->sc)
		exit(84);
	map = initialise_values(map);
	verify_file_stat("./map1.txt");
	map = find_widht_and_height(map, "./map1.txt");
	map = load_2d_arr_from_file("./map1.txt", map);
	cr_assert_neq(map, NULL);
	cr_assert_eq(map->p_pos_y_base, 2);
	cr_assert_eq(map->p_pos_x_base, 5);
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
	free(map);
}

Test(sokoban_test, check_player_position_map_3)
{
	map_t *map = malloc(sizeof(map_t));
	map->sc = malloc(sizeof(score));

	if (!map || !map->sc)
		exit(84);
	map = initialise_values(map);
	verify_file_stat("./map2.txt");
	map = find_widht_and_height(map, "./map2.txt");
	map = load_2d_arr_from_file("./map2.txt", map);
	cr_assert_neq(map, NULL);
	cr_assert_eq(map->p_pos_y_base, 7);
	cr_assert_eq(map->p_pos_x_base, 4);
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
	free(map);
}

Test(sokoban_test, check_player_position_map_4)
{
	map_t *map = malloc(sizeof(map_t));
	map->sc = malloc(sizeof(score));

	if (!map || !map->sc)
		exit(84);
	map = initialise_values(map);
	verify_file_stat("./map3.txt");
	map = find_widht_and_height(map, "./map3.txt");
	map = load_2d_arr_from_file("./map3.txt", map);
	cr_assert_neq(map, NULL);
	cr_assert_eq(map->p_pos_y_base, 1);
	cr_assert_eq(map->p_pos_x_base, 4);
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
	free(map);
}

Test(sokoban_test, check_wall_colision)
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
	map = mv_p_down(map);
	for (unsigned int i = 0; i < 3; i++)
		map = mv_p_right(map);
	cr_assert_eq(map->x_file[2][6], 'P');
	cr_assert_eq(map->x_file[2][7], '#');
	for (int y = 0; y < map->y; y++)
		free(map->x_file[y]);
	for (int y = 0; y < map->y; y++)
		free(map->x_file_save[y]);
}
