/*
** EPITECH PROJECT, 2018
** load_disp.c
** File description:
** load map
*/

#include <stdlib.h>
#include <fcntl.h>
#include "proto.h"

void load_png(map_all_t *all_map, int i, int j)
{
	if (all_map->map[i][j]->option == 24)
		sfSprite_setPosition(all_map->spr_npcs
		[all_map->map[i][j]->option - 24],
		all_map->map[i][j]->position);
}

void load_map(map_all_t *all_map)
{
	for (int i = 0; i < all_map->tab_map->size_y; i++) {
		for (int j = 0; j < all_map->tab_map->size_x; j++) {
			init_sprite(all_map->map, i,
			j, all_map->tab_map);
			sfSprite_setTexture(all_map->map[i][j]->sprite,
			all_map->texture_map, sfTrue);
			sfSprite_setPosition(all_map->map[i][j]->sprite,
			all_map->map[i][j]->position);
			load_png(all_map, i, j);
			sfSprite_setTextureRect(all_map->map[i][j]->sprite,
			all_map->map[i][j]->rect);
		}
	}
}

void disp_map(map_all_t *maps, sfRenderWindow* w, int d)
{
	sfVector2f ntm2 = {1920, 1080};
	sfVector2f pos = {0, 0};

	sfRenderWindow_clear(w, sfBlack);
	for (int i = 0; i < maps->tab_map->size_y; i++)
		for (int j = 0; j < maps->tab_map->size_x; j++)
			display_npc(w, (sfVector2i){j, i}, maps);
	sfSprite_setPosition(maps->player->sprite, maps->player->position);
	sfRenderWindow_setView(w, maps->view_map);
	pos.x = maps->tab_map->pos_x * 100;
	pos.y = maps->tab_map->pos_y * 100;
	sfView_setSize(maps->view_map, ntm2);
	move_png(maps, w);
	if (d == 1)
		sfView_setCenter(maps->view_map, pos);
	sfRenderWindow_drawSprite(w, maps->player->sprite, NULL);
	sfRenderWindow_drawSprite(w, maps->move->sprite, NULL);
	display_fct(maps, w, maps->view_map);
	sfRenderWindow_display(w);
}

void anim_player(map_all_t *maps, int y)
{
	if (maps->player->sens < 20) {
		maps->player->sens++;
		return;
	}
	maps->player->sens = 0;
	maps->player->rect.top = y;
	if (maps->player->rect.left < maps->rect + 70)
		maps->player->rect.left = maps->player->rect.left + 35;
	else
		maps->player->rect.left = maps->rect;
	sfSprite_setTextureRect(maps->player->sprite,
	maps->player->rect);
}

void display_npc(sfRenderWindow *window, sfVector2i coords, map_all_t *map)
{
	sfIntRect rect = {0, 0, 100, 100};

	sfRenderWindow_drawSprite(window,
	map->map[coords.y][coords.x]->sprite, NULL);
	if (map->map[coords.y][coords.x]->option == 24)
		sfRenderWindow_drawSprite(window,
		map->spr_npcs[map->map[coords.y][coords.x]->option - 24], NULL);
	else if (map->map[coords.y][coords.x]->option == 25) {
		sfSprite_setTextureRect(map->spr_obj, rect);
		sfSprite_setPosition(map->spr_obj,
		map->map[coords.y][coords.x]->position);
		sfRenderWindow_drawSprite(window, map->spr_obj, NULL);
	} else if (map->map[coords.y][coords.x]->option > 25) {
		rect.left +=
		map->map[coords.y][coords.x]->option == 26 ? 100 : 200;
		sfSprite_setTextureRect(map->spr_obj, rect);
		sfSprite_setPosition(map->spr_obj,
		map->map[coords.y][coords.x]->position);
		sfRenderWindow_drawSprite(window, map->spr_obj, NULL);
	}
}
