/*
** EPITECH PROJECT, 2018
** texts.c
** File description:
** texts handling
*/

#include "combat.h"
#include "base.h"

void change_text_string(int current_st, int max_st, hud_t *hud)
{
	sfText_setString(hud->st,
	my_strcat(convert_nbr_to_str(current_st)
	, my_strcat(" / ", convert_nbr_to_str(max_st))));
}

void change_text_string_hp(int current_hp, int max_hp, hud_t *hud)
{
	sfText_setString(hud->hp,
	my_strcat(convert_nbr_to_str(current_hp)
	, my_strcat(" / ", convert_nbr_to_str(max_hp))));
}

void change_player_stat(player_stat_t *player, map_cb_t *map)
{
	player->stats->lvl += 1;
	player->stats->exp = 0;
	player->stats->max_hp += 50;
	player->stats->max_st += 2;
	player->stats->current_hp = player->stats->max_hp;
	change_text_string_hp(player->stats->current_hp,
	player->stats->max_hp, map->hud);
}
