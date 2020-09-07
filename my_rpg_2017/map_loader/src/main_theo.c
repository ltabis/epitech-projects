/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** principal loop
*/

#include <stdio.h>
#include "menu.h"
#include "proto.h"
#include "../../include/proto.h"

int check_settings_exist(game_s *game, int exception)
{
	for (int i = 0; i < SPRITE_NBR; i++) {
		if (i != exception && game->sprite[i]->exist == 1)
			return (1);
	}
	return (0);
}

void draw_text_menu(map_all_t *all_map, sfRenderWindow *window)
{
	if (all_map->game->sprite[2]->exist == 1)
		sfRenderWindow_drawText(window, all_map->game->framerate
			, NULL);
	if (all_map->game->sprite[1]->exist == 1)
		sfRenderWindow_drawText(window, all_map->game->sound, NULL);
}

void display_fct_2(map_all_t *all_map, sfRenderWindow *window
	, sfVector2f screen_center)
{
	for (int i = 0; i < BUTTON_NBR; i++) {
		if (all_map->game->button[i]->exist == 1) {
			set_pos_button(screen_center
				, all_map->game->button[i]);
			sfRenderWindow_drawSprite(window
				, all_map->game->button[i]->sprite, NULL);
		}
	}
	set_pos_text(all_map->view_map, all_map->game);
	draw_text_menu(all_map, window);
}

void display_fct(map_all_t *all_map, sfRenderWindow *window, sfView *view)
{
	sfVector2f screen_center = {0, 0};

	for (int i = 0; i < SPRITE_NBR; i++) {
		if (all_map->game->sprite[i]->exist == 1) {
			screen_center = set_pos_sprite(
			all_map->game->sprite[i], view);
			sfRenderWindow_drawSprite(window,
			all_map->game->sprite[i]->sprite, NULL);
		}
		if (all_map->game->sprite[4]->exist == 1) {
			disp_inventory(window, view, all_map->game->obj,
			all_map->player->inventory);
			disp_stats(all_map->game->txt_stats, window);
		}
	}
	display_fct_2(all_map, window, screen_center);
}