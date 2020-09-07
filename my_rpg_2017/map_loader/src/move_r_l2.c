/*
** EPITECH PROJECT, 2018
** move_r_l.c
** File description:
** another move functions
*/

#include <stdlib.h>
#include <fcntl.h>
#include "proto.h"
#include "my.h"

int png_left(map_all_t *mp)
{
	if (mp->move->position.x + 50 > mp->player->position.x &&
	mp->move->position.x < mp->player->position.x) {
		if (mp->player->position.y + 50 > mp->move->position.y &&
		mp->player->position.y < mp->move->position.y + 50)
			return (1);
	}
	return (0);
}

