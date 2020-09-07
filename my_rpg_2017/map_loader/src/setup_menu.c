/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** setup menus
*/

#include "proto.h"

void option_screen(map_all_t *map_all)
{
	game_s *game = map_all->game;

	game->sprite[0]->exist == 0 ?
	(game->sprite[0]->exist = 1) : (game->sprite[0]->exist = 0);
	game->sprite[0]->exist == 1 ?
	(game->button[0]->exist = 1) : (game->button[0]->exist = 0);
	game->sprite[0]->exist == 1 ?
	(game->button[1]->exist = 1) : (game->button[1]->exist = 0);
	game->sprite[0]->exist == 1 ?
	(game->button[2]->exist = 1) : (game->button[2]->exist = 0);
	game->sprite[0]->exist == 1 ?
	(game->button[3]->exist = 1) : (game->button[3]->exist = 0);
	game->sprite[0]->exist == 1 ?
	(game->button[6]->exist = 1) : (game->button[6]->exist = 0);
}

void stats_window(map_all_t *map_all)
{
	int check = 0;

	for (int i = 0; i < 4; i++) {
		if (map_all->game->sprite[i]->exist == 1)
			check++;
	}
	if (check == 0) {
		map_all->game->sprite[4]->exist == 0 ?
		(map_all->game->sprite[4]->exist = 1) :
		(map_all->game->sprite[4]->exist = 0);
		map_all->game->txt_stats = update_stats(map_all->view_map
			, map_all->pl_stats->stats);
	}
}

void audio_setup(map_all_t *map_all, sfRenderWindow *window)
{
	game_s *game = map_all->game;

	(void)window;
	if (game->sprite[0]->exist == 1)
		option_screen(map_all);
	game->sprite[1]->exist == 0 ?
	(game->sprite[1]->exist = 1) : (game->sprite[1]->exist = 0);
	game->sprite[1]->exist == 1 ?
	(game->button[3]->exist = 1) : (game->button[3]->exist = 0);
	game->sprite[1]->exist == 1 ?
	(game->button[7]->exist = 1) : (game->button[7]->exist = 0);
	game->sprite[1]->exist == 1 ?
	(game->button[8]->exist = 1) : (game->button[8]->exist = 0);
}

void video_setup(map_all_t *map_all, sfRenderWindow *window)
{
	game_s *game = map_all->game;

	(void)window;
	if (game->sprite[0]->exist == 1)
		option_screen(map_all);
	game->sprite[2]->exist == 0 ?
	(game->sprite[2]->exist = 1) : (game->sprite[2]->exist = 0);
	game->sprite[2]->exist == 1 ?
	(game->button[3]->exist = 1) : (game->button[3]->exist = 0);
	game->sprite[2]->exist == 1 ?
	(game->button[4]->exist = 1) : (game->button[4]->exist = 0);
	game->sprite[2]->exist == 1 ?
	(game->button[7]->exist = 1) : (game->button[7]->exist = 0);
	game->sprite[2]->exist == 1 ?
	(game->button[8]->exist = 1) : (game->button[8]->exist = 0);
}

void control_setup(map_all_t *map_all, sfRenderWindow *window)
{
	game_s *game = map_all->game;

	(void)window;
	if (game->sprite[0]->exist == 1)
		option_screen(map_all);
	game->sprite[3]->exist == 0 ?
	(game->sprite[3]->exist = 1) : (game->sprite[3]->exist = 0);
	game->sprite[3]->exist == 1 ?
	(game->button[3]->exist = 1) : (game->button[3]->exist = 0);
	game->sprite[3]->exist == 1 ?
	(game->button[5]->exist = 1) : (game->button[5]->exist = 0);
}
