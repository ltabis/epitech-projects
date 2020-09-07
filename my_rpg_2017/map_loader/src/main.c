/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file for the map loader
*/

#include <stdlib.h>
#include <fcntl.h>
#include "map.h"
#include "proto.h"
#include "sound.h"

void launch_2d_map(char *tilemap, char *map, sfRenderWindow *window)
{
	int d = 1;
	map_all_t *all_map = init_struct_map(tilemap, map);
	sfClock *clock = sfClock_create();

	if (!all_map || !clock)
		return;
	load_map(all_map);
	sfMusic_play(all_map->audio->msc_ship);
	for (sfEvent event; sfRenderWindow_isOpen(window) &&
	all_map->pl_stats->stats->current_hp != -1;) {
		while (sfRenderWindow_pollEvent(window, &event))
			analyse_event(event, all_map, window);
		turn(all_map, window, clock);
		disp_map(all_map, window, d);
		d = 0;
	}
	destroy_all_musics(all_map->audio);
	sfView_setCenter(all_map->view_map, (sfVector2f){1920 / 2, 1080 / 2});
	sfRenderWindow_setView(window, all_map->view_map);
	free(all_map);
}
