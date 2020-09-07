/*
** EPITECH PROJECT, 2018
** combat_controls.c
** File description:
** all controls detected and used here
*/

#include "combat.h"

char compute_controls(sfEvent event, map_cb_t *map,
	sfRenderWindow *window)
{
	char ret = -1;

	if (event.type == sfEvtClosed)
		return (1);
	check_camera_movement(map, window);
	if (event.type == sfEvtMouseWheelScrolled)
		augment_or_decrease_size(event, map);
	if (event.type == sfEvtKeyPressed &&
	sfKeyboard_isKeyPressed(sfKeyEscape))
		ret = display_escape_menu(window, map);
	else if (sfKeyboard_isKeyPressed(sfKeyTab))
		open_inventory(window);
	return (ret == -1 ? 0 : ret);
}

void check_camera_movement(map_cb_t *map, sfRenderWindow *window)
{
	sfVector2i mos_pos = sfMouse_getPosition((sfWindow *)window);
	sfVector2u win_size = sfRenderWindow_getSize(window);

	(mos_pos.x >= (int)win_size.x - 20 ?
	map->map_pos.x -= 10, map->map_pos.y += 10 : 0);
	(mos_pos.x <= 20 ?
	map->map_pos.x += 10, map->map_pos.y -= 10 : 0);
	(mos_pos.y >= (int)win_size.y - 20 ?
	map->map_pos.x -= 10, map->map_pos.y -= 10 : 0);
	(mos_pos.y <= 20 ?
	map->map_pos.x += 10, map->map_pos.y += 10 : 0);
	update_2d_map(map);
}

void augment_or_decrease_size(sfEvent event, map_cb_t *map)
{
	if (event.mouseWheelScroll.delta < 0 && map->map_zoom > 1)
		map->map_zoom -= 1;
	else if (event.mouseWheelScroll.delta > 0 && map->map_zoom <= 100)
		map->map_zoom += 1;
}

void draw_hud_status(player_stat_t *p, sfRenderWindow *window, map_cb_t *map)
{
	float sz_hp = BAR_SIZE_X;
	float sz_sp = BAR_SIZE_X;
	float sz_st = BAR_SIZE_X;

	if (p->stats->max_hp != p->stats->current_hp)
		sz_hp = BAR_SIZE_X * (p->stats->current_hp / p->stats->max_hp);
	if (p->stats->max_sp != p->stats->current_sp)
		sz_sp = BAR_SIZE_X * (p->stats->current_sp / p->stats->max_sp);
	if (p->stats->max_st != p->stats->current_st)
		sz_st = BAR_SIZE_X * (p->stats->current_st / p->stats->max_st);
	sfRectangleShape_setSize(p->hp_bar, (sfVector2f){sz_hp, BAR_SIZE_Y});
	sfRectangleShape_setSize(p->sp_bar, (sfVector2f){sz_sp, BAR_SIZE_Y});
	sfRectangleShape_setSize(p->st_bar, (sfVector2f){sz_st, BAR_SIZE_Y});
	sfRenderWindow_drawRectangleShape(window, p->hp_bar, NULL);
	sfRenderWindow_drawRectangleShape(window, p->sp_bar, NULL);
	sfRenderWindow_drawRectangleShape(window, p->st_bar, NULL);
	draw_texts(map, window);
	sfRenderWindow_display(window);
}

void change_player_pos(map_cb_t *map, player_stat_t *player)
{
	player->stats->current_st -= 1;
	for (unsigned int i = 0, trig = 0; i < 19 && trig != 1; i++)
		for (unsigned int j = 0; j < 19 && trig != 1; j++) {
			map->tiles[i][j].entity =
			map->tiles[i][j].cursor != 1 &&
			map->tiles[i][j].entity == 2 ?
			0 : map->tiles[i][j].entity;
			trig = map->tiles[i][j].cursor != 1 &&
			map->tiles[i][j].entity == 2 ? 1 : 0;
		}
	for (unsigned int i = 0; i < 19; i++)
		for (unsigned int j = 0; j < 19; j++) {
			map->tiles[i][j].entity =
			map->tiles[i][j].cursor == 1 &&
			map->tiles[i][j].entity != 1 ?
			2 : map->tiles[i][j].entity;
			map->tiles[i][j].cursor = 0;
		}
}
