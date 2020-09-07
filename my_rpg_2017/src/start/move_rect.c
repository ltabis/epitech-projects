/*
** EPITECH PROJECT, 2018
** move_rect.c
** File description:
** functions for move all rect
*/

#include "menu.h"
#include "proto.h"

void move_rect_miniature_right(choose_player_t *var)
{
	if (var->rect_mini.left >= 240)
		var->rect_mini.left = 0;
	else
		var->rect_mini.left += 80;
	sfSprite_setTextureRect(var->miniature, var->rect_mini);
}

void move_rect_miniature_left(choose_player_t *var)
{
	if (var->rect_mini.left <= 0)
		var->rect_mini.left = 240;
	else
		var->rect_mini.left -= 80;
	sfSprite_setTextureRect(var->miniature, var->rect_mini);
}

void move_rect_player_right(player_t *player)
{
	if (player->rect.left >= 315)
		player->rect.left = 0;
	else
		player->rect.left += 105;
	sfSprite_setTextureRect(player->sprite, player->rect);
}

void move_rect_player_left(player_t *player)
{
	if (player->rect.left <= 0)
		player->rect.left = 315;
	else
		player->rect.left -= 105;
	sfSprite_setTextureRect(player->sprite, player->rect);
}
