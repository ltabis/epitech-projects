/*
** EPITECH PROJECT, 2018
** option_video.c
** File description:
** functions for video options
*/

#include "proto.h"

void set_framerate(game_s *game, int plus, sfRenderWindow *window)
{
	if (plus == 1)
		game->fps += 10;
	else
		game->fps -= 10;
	sfRenderWindow_setFramerateLimit(window, game->fps);
}

void set_sync(map_all_t *map_all, sfRenderWindow *window)
{
	game_s *game = map_all->game;

	game->v_sync == 0 ? (game->v_sync = 1) : (game->v_sync = 0);
	if (game->v_sync == 1)
		sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
	else
		sfRenderWindow_setVerticalSyncEnabled(window, sfFalse);
}
