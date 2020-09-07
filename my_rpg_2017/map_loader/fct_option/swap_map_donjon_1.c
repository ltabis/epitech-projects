/*
** EPITECH PROJECT, 2018
** swap_map_1.c
** File description:
** swapping the firsts map
*/

#include "my.h"
#include "proto.h"

void map_1_to_donjon_1(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	char trig = 0;

	for (int i = 0; i < all_map->tab_map->size_y && trig != 1; i++)
		for (int j = 0; j < all_map->tab_map->size_x && trig != 1; j++)
			trig = all_map->map[i][j]->option == 27 ? 1 : trig;
	if (trig == 0) {
		all_map->tab_map->pos_x = 11;
		all_map->tab_map->pos_y = 35;
		all_map->player = init_player(all_map->tab_map, all_map->rect);
		return;
	}
	all_map->tab_map = init_tab_map("map_loader/map/dungeon1");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 6;
	all_map->tab_map->pos_y = 9;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void donjon_1_to_map_1(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_1");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 11;
	all_map->tab_map->pos_y = 35;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void map_2_to_donjon_2(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	char trig = 0;

	for (int i = 0; i < all_map->tab_map->size_y && trig != 1; i++)
		for (int j = 0; j < all_map->tab_map->size_x && trig != 1; j++)
			trig = all_map->map[i][j]->option == 27 ? 1 : trig;
	if (trig == 0) {
		all_map->tab_map->pos_x = 20;
		all_map->tab_map->pos_y = 6;
		all_map->player = init_player(all_map->tab_map, all_map->rect);
		return;
	}
	all_map->tab_map = init_tab_map("map_loader/map/dungeon2");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 5;
	all_map->tab_map->pos_y = 6;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void donjon_2_to_map_2(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_2");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 20;
	all_map->tab_map->pos_y = 6;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void map_3_to_donjon_3(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	char trig = 0;

	for (int i = 0; i < all_map->tab_map->size_y && trig != 1; i++)
		for (int j = 0; j < all_map->tab_map->size_x && trig != 1; j++)
			trig = all_map->map[i][j]->option == 27 ? 1 : trig;
	if (trig == 0) {
		all_map->tab_map->pos_x = 5;
		all_map->tab_map->pos_y = 8;
		all_map->player = init_player(all_map->tab_map, all_map->rect);
		return;
	}
	all_map->tab_map = init_tab_map("map_loader/map/dungeon3");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 4;
	all_map->tab_map->pos_y = 7;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}
