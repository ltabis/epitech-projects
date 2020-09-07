/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** function pointer
*/

#include "proto.h"
#include "../../include/proto.h"

void button_hover_fct_pointer(game_s *game, sfVector2f click_pos)
{
	for (int i = 0; i < BUTTON_NBR; i++) {
		if ((check_button(game->button[i], click_pos)) == 1)
			sfSprite_setColor(game->button[i]->sprite, sfBlue);
		else
			sfSprite_setColor(game->button[i]->sprite, sfWhite);
	}
}

void button_click_fct_pointer(game_s *game, sfVector2f click_pos)
{
	for (int i = 0; i < BUTTON_NBR; i++) {
		if ((check_button(game->button[i], click_pos)) == 1)
			sfSprite_setColor(game->button[i]->sprite, sfYellow);
		else
			sfSprite_setColor(game->button[i]->sprite, sfWhite);
	}
}

void button_activate_fct_pointer(map_all_t *map_all, sfVector2f click_pos
	, sfRenderWindow *window)
{
	game_s *game = map_all->game;
	void(*fct_arr[7])(map_all_t *, sfRenderWindow *) = {audio_setup,
	control_setup, video_setup, back_fct, set_sync, invert_key, exit_game};

	for (int i = 0; i < 7; i++) {
		if (game->button[i]->exist == 1 &&
			(check_button(game->button[i], click_pos)) == 1)
			fct_arr[i](map_all, window);
	}
	music_gestion(map_all, click_pos);
	framerate_gestion(map_all, click_pos, window);
}

void key_fct_array(sfEvent event, map_all_t *map_all)
{
	sfKeyCode base[3] = {sfKeyEscape, sfKeyI, sfKeyUnknown};
	void (*fct_arr[2])(map_all_t *) = {option_screen, stats_window};

	for (int i = 0; base[i] != sfKeyUnknown; i++) {
		if (event.key.code == base[i])
			fct_arr[i](map_all);
	}
}

void back_fct(map_all_t *map_all, sfRenderWindow *window)
{
	void (*fct_tab[3])(map_all_t *, sfRenderWindow *) = {audio_setup
		, video_setup, control_setup};

	if (map_all->game->sprite[0]->exist == 1)
		option_screen(map_all);
	for (int i = 1; i < 4; i++) {
		if (map_all->game->sprite[i]->exist == 1) {
			fct_tab[i - 1](map_all, window);
		}
	}
}
