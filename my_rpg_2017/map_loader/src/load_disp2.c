/*
** EPITECH PROJECT, 2018
** load_disp.c
** File description:
** load map
*/

#include <stdlib.h>
#include <fcntl.h>
#include "proto.h"

int check_png_right(map_all_t *mp)
{
	if (mp->player->position.x < mp->move->position.x + 50 &&
	mp->player->position.x > mp->move->position.x) {
		if (mp->move->position.y + 50 > mp->player->position.y
		&& mp->move->position.y < mp->player->position.y + 50)
			return (1);
	}
	return (0);
}

int check_png_left(map_all_t *mp)
{
	if (mp->player->position.x + 50 > mp->move->position.x &&
	mp->player->position.x < mp->move->position.x) {
		if (mp->move->position.y + 50 > mp->player->position.y
		&& mp->move->position.y < mp->player->position.y + 50)
			return (1);
	}
	return (0);
}

void move_png(map_all_t *maps, UNUSED sfRenderWindow* w)
{
	float sd = sfTime_asSeconds(sfClock_getElapsedTime(maps->move->clock));

	if (sd > 0.02 && maps->move->move == 1) {
		if (check_png_right(maps) == 1)
			return;
		sfClock_restart(maps->move->clock);
		maps->move->position.x = maps->move->position.x + 2;
		sfSprite_setPosition(maps->move->sprite, maps->move->position);
		if (maps->move->position.x >= 4300)
			maps->move->move = 2;
	}
	if (sd > 0.02 && maps->move->move == 2) {
		if (check_png_left(maps) == 1)
			return;
		sfClock_restart(maps->move->clock);
		maps->move->position.x = maps->move->position.x - 2;
		sfSprite_setPosition(maps->move->sprite, maps->move->position);
		if (maps->move->position.x <= 4000)
			maps->move->move = 1;
	}
}
