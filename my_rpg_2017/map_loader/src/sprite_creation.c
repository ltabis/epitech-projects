/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** sprite creation
*/

#include "proto.h"

sprite_s *sprite_drawing(char *str, sprite_s *image)
{
	image->texture = sfTexture_createFromFile(str, NULL);
	image->sprite = sfSprite_create();
	sfSprite_setTexture(image->sprite, image->texture, sfTrue);
	return (image);
}

sprite_s *sprite_init(sprite_s *sprite, sfVector2f pos, sfVector2f size,
char *name)
{
	sprite->pos.x = pos.x;
	sprite->pos.y = pos.y;
	sprite->size.x = size.x;
	sprite->size.y = size.y;
	sprite = sprite_drawing(name, sprite);
	sfSprite_setPosition(sprite->sprite, sprite->pos);
	sprite->exist = 0;
	return (sprite);
}
