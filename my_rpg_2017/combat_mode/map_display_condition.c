/*
** EPITECH PROJECT, 2018
** map_display_condition.c
** File description:
** conditions for the display of the 2d map
*/

#include "combat.h"

void check_display_on_x_axes(sfVector2i decal, sfVector2i lims,
	map_cb_t map, sfRenderWindow *w)
{
	if (decal.x + 1 < lims.x)
		draw_tile_lines(map.map_2d, decal,
		(sfVector2i){1, 0}, w);
}

void check_display_on_y_axes(sfVector2i decal, sfVector2i lims,
	map_cb_t map, sfRenderWindow *w)
{
	if (decal.y + 1 < lims.y)
		draw_tile_lines(map.map_2d, decal,
		(sfVector2i){0, 1}, w);
}

void check_display_on_both_axes(sfVector2i decal, map_cb_t map,
	sfRenderWindow *w, sfRenderStates state)
{
	sfVertexArray *ver_1 = create_tiles(&map, decal);

	sfRenderWindow_drawVertexArray(w, ver_1, &state);
	set_trees(map, decal, w);
	sfVertexArray_destroy(ver_1);
}

char check_buttons_ret_value(sfSprite **but, sfRenderWindow *w,
	sfEvent event)
{
	char stop = -1;

	for (unsigned int i = 0; i < 3 && stop == -1; i++)
		stop = check_buttons_actions_escape(but[i], w, i, event);
	return (stop);
}

void check_valid_action(map_cb_t *map, sfVector2i pos,
	sfVector2i p_pos, player_stat_t *player)
{
	if (sfMouse_isButtonPressed(sfMouseLeft) &&
	map->tiles[pos.y][pos.x].entity == 1 &&
	map->tiles[pos.y][pos.x].type != FOLLIAGE &&
	map->tiles[p_pos.y][p_pos.x].type != FOLLIAGE) {
		player->stats->current_st -= 3;
		map->tiles[pos.y][pos.x].ptr->current_hp -= player->stats->att;
		if (map->tiles[pos.y][pos.x].ptr->current_hp <= 0) {
			player->stats->exp += 10;
			free(map->tiles[pos.y][pos.x].ptr);
			map->tiles[pos.y][pos.x].entity = 0;
		}
	} else if (sfMouse_isButtonPressed(sfMouseRight) &&
	map->tiles[pos.y][pos.x].entity != 1)
		change_player_pos(map, player);
	if (player->stats->exp >= 100)
		change_player_stat(player, map);
}
