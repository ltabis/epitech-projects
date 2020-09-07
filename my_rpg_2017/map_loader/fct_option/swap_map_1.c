/*
** EPITECH PROJECT, 2018
** swap_map_1.c
** File description:
** swapping the firsts map
*/

#include "my.h"
#include "proto.h"

void ship_to_map_1(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	sfMusic_stop(all_map->audio->msc_ship);
	sfMusic_play(all_map->audio->msc_norm);
	all_map->tab_map = init_tab_map("map_loader/map/map_1");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 5;
	all_map->tab_map->pos_y = 5;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void map_1_to_map_2(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_2");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 1;
	all_map->tab_map->pos_y = 4;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void map_2_to_map_1(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_1");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 46;
	all_map->tab_map->pos_y = 4;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void map_1_to_map_3(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_3");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 1;
	all_map->tab_map->pos_y = 14;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void map_3_to_map_1(map_all_t *all_map,
	sfRenderWindow *window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/map_1");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->tab_map->pos_x = 46;
	all_map->tab_map->pos_y = 40;
	all_map->player = init_player(all_map->tab_map, all_map->rect);
	load_map(all_map);
	disp_map(all_map, window, 1);
}
