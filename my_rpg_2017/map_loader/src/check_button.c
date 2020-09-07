/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** checking button
*/

#include "proto.h"

void check_video_button(game_s *game)
{
	if (game->sprite[2]->exist == 1) {
		game->button[3]->exist = 1;
		game->button[4]->exist = 1;
	} else {
		game->button[3]->exist = 0;
		game->button[4]->exist = 0;
	}
}

void check_control_button(game_s *game)
{
	if (game->sprite[3]->exist == 1)
		game->button[3]->exist = 1;
	else
		game->button[3]->exist = 0;
}

void check_audio_button(game_s *game)
{
	if (game->sprite[1]->exist == 1)
		game->button[3]->exist = 1;
	else
		game->button[3]->exist = 0;
}

void check_option_button(game_s *game)
{
	if (game->sprite[0]->exist == 1) {
		game->button[0]->exist = 1;
		game->button[1]->exist = 1;
		game->button[2]->exist = 1;
		game->button[3]->exist = 1;
	} else {
		game->button[0]->exist = 0;
		game->button[1]->exist = 0;
		game->button[2]->exist = 0;
		game->button[3]->exist = 0;
	}
}

void check_button_exist(game_s *game)
{
	check_option_button(game);
	check_audio_button(game);
	check_video_button(game);
	check_control_button(game);
}
