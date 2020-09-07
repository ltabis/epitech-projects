/*
** EPITECH PROJECT, 2018
** init_4.c
** File description:
** initialisation methods
*/

#include <stdlib.h>
#include <fcntl.h>
#include "proto.h"
#include "combat.h"
#include "sound.h"
#include "../../include/proto.h"

player_t *init_player(tab_map_t *tab_map, int origin)
{
	player_t *player = malloc(sizeof(player_t));

	player->sprite = sfSprite_create();
	player->texture = sfTexture_createFromFile(IMG_PLAYER, NULL);
	sfSprite_setTexture(player->sprite, player->texture, sfTrue);
	player->position.x = tab_map->pos_x * 100;
	player->position.y = tab_map->pos_y * 100;
	sfSprite_setPosition(player->sprite, player->position);
	player->rect = create_rect(0, origin, 35, 35);
	player->tempo_x = 50;
	player->tempo_y = 50;
	player->case_x = tab_map->pos_x;
	player->case_y = tab_map->pos_y;
	player->sens = 0;
	player->inventory = init_inventory();
	sfSprite_setTextureRect(player->sprite, player->rect);
	sfSprite_scale(player->sprite, (sfVector2f){2, 2});
	return (player);
}

map_all_t *init_struct_map(char *tile_map, char *map_file)
{
	map_all_t *map = malloc(sizeof(map_all_t));

	if (!(map->game = malloc(sizeof(game_s))))
		return (NULL);
	init_npcs(map);
	map->npc = npc_parser("ressources/npc.txt");
	map->txt = text_parser("ressources/texts/npc_dialogue.txt");
	map->tab_map = init_tab_map(map_file);
	map->map = init_map(map->tab_map);
	map->view_map = sfView_create();
	map->texture_map = sfTexture_createFromFile(tile_map, NULL);
	map->player = init_player(map->tab_map, map->rect);
	init_struct(map->game);
	map->game = game_initialisation(map->game, map->view_map);
	map->pl_stats = create_player();
	map->tilemap = &(tilemap_t){
	sfTexture_createFromFile("sprites/plain/tm_ground.png", NULL),
	NULL, NULL, NULL, NULL};
	map->audio = set_sounds();
	return (map);
}

stats_t *create_player_stats(void)
{
	stats_t *player_stats = malloc(sizeof(stats_t));

	if (!player_stats)
		return (NULL);
	player_stats->current_hp = 100;
	player_stats->current_sp = 100;
	player_stats->current_st = 5;
	player_stats->max_hp = 100;
	player_stats->max_sp = 100;
	player_stats->max_st = 5;
	player_stats->att = 20;
	player_stats->def = 10;
	player_stats->spd = 1;
	player_stats->lvl = 1;
	player_stats->exp = 0;
	return (player_stats);
}

player_stat_t *create_player(void)
{
	player_stat_t *player = malloc(sizeof(player_stat_t));

	if (!player)
		return (NULL);
	player->perso = sfSprite_create();
	player->tilemap = sfTexture_createFromFile(
	"ressources/pictures/perso/perso.png", NULL);
	if (!player->perso || !player->tilemap)
		return (NULL);
	sfSprite_setTexture(player->perso, player->tilemap, 0);
	player->rect = (sfIntRect){0, 0, 35, 35};
	player->hp_bar = sfRectangleShape_create();
	player->sp_bar = sfRectangleShape_create();
	player->st_bar = sfRectangleShape_create();
	player->stats = create_player_stats();
	if (!player->hp_bar || !player->sp_bar || !player->st_bar ||
	!player->stats)
		return (NULL);
	change_hud_colors(player);
	return (player);
}

void change_hud_colors(player_stat_t *player)
{
	sfVector2f origin = {BAR_SIZE_X, BAR_SIZE_Y / 2};

	sfRectangleShape_setFillColor(
	player->hp_bar, (sfColor){255, 100, 100, 255});
	sfRectangleShape_setFillColor(
	player->sp_bar, (sfColor){100, 100, 255, 255});
	sfRectangleShape_setFillColor(
	player->st_bar, (sfColor){100, 255, 100, 255});
	sfRectangleShape_setSize(player->hp_bar,
	(sfVector2f){BAR_SIZE_X, BAR_SIZE_Y});
	sfRectangleShape_setSize(player->sp_bar,
	(sfVector2f){BAR_SIZE_X, BAR_SIZE_Y});
	sfRectangleShape_setSize(player->st_bar,
	(sfVector2f){BAR_SIZE_X, BAR_SIZE_Y});
	sfRectangleShape_setPosition(player->sp_bar, (sfVector2f){1880, 980});
	sfRectangleShape_setPosition(player->hp_bar, (sfVector2f){1880, 1000});
	sfRectangleShape_setPosition(player->st_bar, (sfVector2f){1880, 1020});
	sfRectangleShape_setOrigin(player->hp_bar, origin);
	sfRectangleShape_setOrigin(player->sp_bar, origin);
	sfRectangleShape_setOrigin(player->st_bar, origin);
}
