/*
** EPITECH PROJECT, 2018
** utils_3.c
** File description:
** antoher utils fucntions
*/

#include "../include/combat.h"

void change_color(map_cb_t *map, sfVector2i *decal)
{
	sfColor color_1 = {255, 255, 255, 100};
	sfColor color_2 = {255, 255, 255, 255};

	if (map->tiles[decal->y][decal->x].entity == 1) {
		if (map->tiles[decal->y][decal->x].type == FOLLIAGE)
			sfSprite_setColor(
			map->tiles[decal->y][decal->x].ptr->spr, color_1);
		else
			sfSprite_setColor(
			map->tiles[decal->y][decal->x].ptr->spr, color_2);
	} else {
		if (map->tiles[decal->y][decal->x].type == FOLLIAGE)
			sfSprite_setColor(map->ter_spr, color_1);
		else
			sfSprite_setColor(map->ter_spr, color_2);
	}
}

void check_valid_coordinates(sfVector2i *row)
{
	row->x = row->x < 0 ? 0 : row->x;
	row->x = row->x >= 20 ? 19 : row->x;
	row->y = row->y < 0 ? 0 : row->y;
	row->y = row->y >= 20 ? 19 : row->y;
}

unsigned int attack_player(map_cb_t *map, sfVector2i *pos_original,
	sfVector2i *pos, player_stat_t *player)
{
	if (map->tiles[pos->y][pos->x].entity == 0 &&
	map->tiles[pos->y][pos->x].type != TREE) {
		player->stats->current_hp -=
		map->tiles[pos_original->y][pos_original->x].ptr->att;
		change_text_string_hp(player->stats->current_hp,
		player->stats->max_hp, map->hud);
		map->tiles[pos->y][pos->x].ptr =
		map->tiles[pos_original->y][pos_original->x].ptr;
		map->tiles[pos_original->y][pos_original->x].ptr = NULL;
		map->tiles[pos->y][pos->x].entity = 1;
		map->tiles[pos_original->y][pos_original->x].entity = 0;
		return (1);
	}
	return (0);
}

void change_background_color_1(background_t *back, unsigned int i,
	int color, player_stat_t *player)
{
	if (player->stats->current_hp <= player->stats->max_hp / 3) {
		back->buffer->pixels[i] = 255;
		back->buffer->pixels[i + 1] = 0;
		back->buffer->pixels[i + 2] = 0;
		back->buffer->pixels[i + 3] = 255 - color;
	} else
		back->buffer->pixels[i + 3] = 255 - color;
}

void change_background_color_2(background_t *back, unsigned int i,
	int color, player_stat_t *player)
{
	if (player->stats->current_hp <= player->stats->max_hp / 3) {
		back->buffer->pixels[i] = 255;
		back->buffer->pixels[i + 1] = 0;
		back->buffer->pixels[i + 2] = 0;
		back->buffer->pixels[i + 3] = color;
	} else
		back->buffer->pixels[i + 3] = color;
}
