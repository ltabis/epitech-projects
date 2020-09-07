/*
** EPITECH PROJECT, 2018
** computing_turns.c
** File description:
** computing play turns
*/

#include "../include/combat.h"
#include "../include/monster.h"

void compute_turns(player_stat_t *player, map_cb_t *map,
	sfRenderWindow *w)
{
	sfFloatRect re = sfText_getLocalBounds(map->play);

	sfText_setOrigin(map->play,
	(sfVector2f){re.left + re.width / 2.0f, re.top + re.height / 2.0f});
	sfText_setPosition(map->play, (sfVector2f){1920 / 2.0f, 1080 / 10.0f});
	sfRenderWindow_drawText(w, map->play, NULL);
	if (map->turn == PLAYER_TURN) {
		compute_player_turn(player, map, w);
		map->turn *= player->stats->current_st <= 0 ? -1 : 1;
		sfText_setColor(map->play, sfGreen);
		change_text_string(player->stats->current_st,
		player->stats->max_st, map->hud);
	} else if (map->turn == ENEMY_TURN) {
		player->stats->current_st = player->stats->max_st;
		change_text_string(player->stats->current_st,
		player->stats->max_st, map->hud);
		sfText_setColor(map->play, sfRed);
		compute_enemy_turn(map, player);
		map->turn = PLAYER_TURN;
	}
}

void compute_player_turn(player_stat_t *player,
	map_cb_t *map, sfRenderWindow *w)
{
	for (sfVector2i pos = {0, 0}; pos.y < 20; pos.y++)
		for (pos.x = 0; pos.x < 20; pos.x++)
			check_if_quad_got_clicked(map, w, pos, player);
}

void check_if_quad_got_clicked(map_cb_t *map, sfRenderWindow *window,
	sfVector2i pos, player_stat_t *player)
{
	sfVector2i mos_pos = sfMouse_getPositionRenderWindow(window);

	if (pos.x + 1 < 20 && pos.y + 1 < 20) {
		if (mos_pos.y >= map->map_2d[pos.y][pos.x].y &&
		mos_pos.x <= map->map_2d[pos.y][pos.x + 1].x &&
		mos_pos.y <= map->map_2d[pos.y + 1][pos.x + 1].y &&
		mos_pos.x >= map->map_2d[pos.y + 1][pos.x].x &&
		map->tiles[pos.y][pos.x].type != TREE) {
			check_controls(map, pos, player, window);
			change_cursor(map, pos);
		}
	}
}

void change_cursor(map_cb_t *map, sfVector2i pos)
{
	for (unsigned int i = 0; i < 19; i++)
		for (unsigned int j = 0; j < 19; j++)
			map->tiles[i][j].cursor = 0;
	map->tiles[pos.y][pos.x].cursor = 1;
}

void check_controls(map_cb_t *map, sfVector2i pos,
	player_stat_t *player, sfRenderWindow *w)
{
	sfEvent event;
	sfVector2i p_pos = get_player_pos(map);

	while (sfRenderWindow_pollEvent(w, &event))
		if (event.type == sfEvtMouseButtonPressed)
			check_valid_action(map, pos, p_pos, player);
}
