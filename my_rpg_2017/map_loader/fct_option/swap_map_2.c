/*
** EPITECH PROJECT, 2018
** swap_map_1.c
** File description:
** swapping the firsts map
*/

#include "my.h"
#include "proto.h"

void map_2_to_map_3(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_3");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 13;
	all_map->tab_map->pos_y = 1;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void map_3_to_map_2(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_2");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 13;
	all_map->tab_map->pos_y = 21;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void donjon_3_to_map_3(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_3");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 5;
	all_map->tab_map->pos_y = 8;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void map_2_to_boss(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_boss");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 12;
	all_map->tab_map->pos_y = 1;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void boss_to_map_2(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_3");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 12;
	all_map->tab_map->pos_y = 21;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}
