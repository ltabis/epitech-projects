/*
** EPITECH PROJECT, 2018
** init_1.c
** File description:
** initialisation
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "map.h"
#include "my.h"
#include "proto.h"

void init_move(map_all_t *map)
{
	map->move = malloc(sizeof(move_t));
	map->move->position = (sfVector2f){4000, 4000};
	map->move->sprite = sfSprite_create();
	map->move->texture = sfTexture_createFromFile(
	"ressources/pictures/menu/main_menu/npcs.png", NULL);
	map->move->rect = create_rect(0, 210, 35, 35);
	sfSprite_setPosition(map->move->sprite, map->move->position);
	sfSprite_setTexture(map->move->sprite, map->move->texture, 0);
	sfSprite_setTextureRect(map->move->sprite, map->move->rect);
	sfSprite_scale(map->move->sprite, (sfVector2f){2, 2});
	map->move->clock = sfClock_create();
	map->move->move = 1;
}
