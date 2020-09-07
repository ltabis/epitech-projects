/*
** EPITECH PROJECT, 2018
** end_combat.c
** File description:
** checking if the game is ending or not
*/

#include "combat.h"
#include "particles.h"
#include "menu.h"

char end_combat(player_stat_t *player, map_cb_t *map,
	background_t *back, sfRenderWindow *w)
{
	char trig = 0;
	int ret = 0;

	if (player->stats->current_hp <= 0) {
		ret = launch_end_lose_scene(map, w, back);
		if (ret == 2) {
			player->stats->current_hp = -1;
		} else
			player->stats->current_hp = player->stats->max_hp;
		return (1);
	}
	for (unsigned int i = 0; i < 19 && trig != 1; i++)
		for (unsigned int j = 0; j < 19 && trig != 1; j++)
			trig = map->tiles[i][j].entity == 1 ? 1 : 0;
	if (trig != 1)
		launch_end_win_scene(map, w, back);
	return (trig != 1 ? 1 : 0);
}

int launch_end_lose_scene(map_cb_t *map,
	sfRenderWindow *w, background_t *back)
{
	sfText *lose_1 = sfText_create();
	sfText *lose_2 = sfText_create();
	sfSprite **but = create_end_buttons_lose();
	int stop = 0;

	set_up_end_texts_lose(lose_1, lose_2);
	create_white_background(back, w, map);
	for (; stop == 0 && but;) {
		sfRenderWindow_drawSprite(w, back->spr, NULL);
		sfRenderWindow_drawText(w, lose_1, NULL);
		sfRenderWindow_drawText(w, lose_2, NULL);
		sfRenderWindow_drawSprite(w, but[0], NULL);
		sfRenderWindow_drawSprite(w, but[1], NULL);
		sfRenderWindow_display(w);
		stop = check_buttons_actions(but[0], w, 1);
		stop = stop == 0 ? check_buttons_actions(but[1], w, 2) : stop;
	}
	sfSprite_destroy(but[0]);
	sfSprite_destroy(but[1]);
	return (stop);
}

int launch_end_win_scene(map_cb_t *map,
	sfRenderWindow *w, background_t *back)
{
	sfText *win_1 = sfText_create();
	sfText *win_2 = sfText_create();
	sfSprite *but = create_end_button_win();
	int stop = 0;

	set_up_end_texts_win(win_1, win_2);
	create_white_background(back, w, map);
	for (; stop == 0 && but;) {
		sfRenderWindow_drawSprite(w, back->spr, NULL);
		sfRenderWindow_drawText(w, win_1, NULL);
		sfRenderWindow_drawText(w, win_2, NULL);
		sfRenderWindow_drawSprite(w, but, NULL);
		sfRenderWindow_display(w);
		stop = check_buttons_actions(but, w, 2);
	}
	sfSprite_destroy(but);
	return (stop);
}

void create_white_background(background_t *back,
	sfRenderWindow *w, map_cb_t *map)
{
	clear_buffer(back->buffer, 1919, 1079);
	for (unsigned int i = 0; i < 1080 * 1920 * 4; i += 4) {
		back->buffer->pixels[i] = 255;
		back->buffer->pixels[i + 1] = 255;
		back->buffer->pixels[i + 2] = 255;
		back->buffer->pixels[i + 3] = 0;
	}
	for (unsigned int color = 0;
	back->buffer->pixels[1080 * 1920 * 4 - 1] != 255; color++) {
		for (unsigned int i = 0; i < 1920 * 1080 * 4; i += 4)
			back->buffer->pixels[i + 3] = color;
		sfRenderWindow_clear(w, sfBlack);
		draw_2d_map(w, *map,
		(sfVector2i){MAP_SIZE, MAP_SIZE}, map->state);
		sfTexture_updateFromPixels(back->txt, back->buffer->pixels,
		1920, 1080, 0, 0);
		sfRenderWindow_drawSprite(w, back->spr, NULL);
		sfRenderWindow_display(w);
	}
}

sfVector2i get_player_pos(map_cb_t *map)
{
	sfVector2i p_pos = {0, 0};

	for (char i = 0; p_pos.y < 19 && i != 1; p_pos.y++)
		for (p_pos.x = 0; p_pos.x < 19 && i != 1; p_pos.x++)
			i = map->tiles[p_pos.y][p_pos.x].entity == 2 ? 1 : 0;
	p_pos.y--;
	p_pos.x--;
	return (p_pos);
}
