/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** frame and music option
*/

#include "proto.h"

static void music_update(map_all_t *all_map, int change)
{
	if (all_map->game->volume >= 0 && all_map->game->volume <= 100)
		all_map->game->volume += change;
	if (all_map->game->volume < 0)
		all_map->game->volume = 0;
	else if (all_map->game->volume >= 100)
		all_map->game->volume = 100;
	sfMusic_setVolume(all_map->audio->msc_ship, all_map->game->volume);
	sfMusic_setVolume(all_map->audio->msc_norm, all_map->game->volume);
	sfMusic_setVolume(all_map->audio->msc_comb, all_map->game->volume);
	sfText_setString(all_map->game->sound
		, my_strcat("Sound = "
			, convert_nbr_to_str(all_map->game->volume)));
}

static void framerate_update(map_all_t *map_all, int change
	, sfRenderWindow *window)
{
	if (map_all->game->fps >= 0 && map_all->game->fps <= 120)
		map_all->game->fps += change;
	if (map_all->game->fps < 0)
		map_all->game->fps = 0;
	else if (map_all->game->fps >= 120)
		map_all->game->fps = 120;
	sfRenderWindow_setFramerateLimit(window, (unsigned)map_all->game->fps);
	sfText_setString(map_all->game->framerate
		, my_strcat("Framerate = "
			, convert_nbr_to_str(map_all->game->fps)));
}

void music_gestion(map_all_t *map_all, sfVector2f click_pos)
{
	if (map_all->game->sprite[1]->exist == 1) {
		if ((check_button(map_all->game->button[7], click_pos)) == 1) {
			music_update(map_all, 10);
		} else if ((check_button(map_all->game->button[8]
			, click_pos)) == 1)
			music_update(map_all, -10);
	}
}

void framerate_gestion(map_all_t *map_all, sfVector2f click_pos
	, sfRenderWindow *window)
{
	if (map_all->game->sprite[2]->exist == 1) {
		if ((check_button(map_all->game->button[7], click_pos)) == 1) {
			framerate_update(map_all, 5, window);
		} else if ((check_button(map_all->game->button[8]
			, click_pos)) == 1)
			framerate_update(map_all, -5, window);
	}
}
