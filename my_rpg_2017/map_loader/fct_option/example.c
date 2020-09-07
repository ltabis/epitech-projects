/*
** EPITECH PROJECT, 2018
** exemple.c
** File description:
** exemples
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "proto.h"
#include "my.h"
#include <fcntl.h>

void swap_map(map_all_t *all_map, sfRenderWindow* window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/lol1");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->player = init_player(all_map->tab_map, 0);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void swap_a(map_all_t *all_map, sfRenderWindow* window, UNUSED int back)
{
	all_map->tab_map = init_tab_map("map_loader/map/maaaap");
	all_map->map = init_map(all_map->tab_map);
	all_map->texture_map =
	sfTexture_createFromFile("picture/tile_mapok.png", NULL);
	all_map->player = init_player(all_map->tab_map, 0);
	load_map(all_map);
	disp_map(all_map, window, 1);
}

void swap(map_all_t *all_map, UNUSED sfRenderWindow* window, UNUSED int back)
{
	all_map->pl_stats->stats->current_hp = -1;
}

void env_actions(map_all_t *map, UNUSED sfRenderWindow *window,
	sfVector2i pos, int nbr)
{
	if (nbr == 26 && map->pl_stats->stats->current_hp > 20) {
		map->map[pos.y][pos.x]->option = 1;
		map->pl_stats->stats->current_hp -= 20;
	} else if (nbr == 25)
		map->map[pos.y][pos.x]->option = 27;
}
