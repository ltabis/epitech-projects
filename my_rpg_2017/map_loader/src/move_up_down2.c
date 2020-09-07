/*
** EPITECH PROJECT, 2018
** move_up_down.c
** File description:
** functions to move the player around the map
*/

#include <stdlib.h>
#include <fcntl.h>
#include "proto.h"
#include "my.h"

int png_up(map_all_t *mp)
{
	if (mp->move->position.y + 50 > mp->player->position.y
	&& mp->move->position.y < mp->player->position.y) {
		if (mp->player->position.x + 50 > mp->move->position.x
		&& mp->player->position.x < mp->move->position.x + 50)
			return (1);
	}
	return (0);
}

void up_nd(map_all_t *mp)
{
	mp->player->tempo_y = mp->player->tempo_y - 3;
	mp->player->position.y = mp->player->position.y -3;
	anim_player(mp, 105);
}

int png_down(map_all_t *mp)
{
	if (mp->move->position.y < mp->player->position.y + 50 &&
	mp->move->position.y > mp->player->position.y) {
		if (mp->player->position.x + 50 > mp->move->position.x &&
		mp->player->position.x < mp->move->position.x + 50)
			return (1);
	}
	return (0);
}

void down_nd(map_all_t *mp)
{
	mp->player->tempo_y = mp->player->tempo_y + 3;
	mp->player->position.y = mp->player->position.y + 3;
	anim_player(mp, 0);
}

