/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** some usual functions for csfml
*/

#include "my.h"
#include "proto.h"
#include "menu.h"

sfTexture *create_texture(char *path)
{
	sfTexture *texture;

	texture = sfTexture_createFromFile(path, NULL);
	return (texture);
}

sfSprite *create_sprite(char *path)
{
	sfTexture *texture;
	sfSprite *sprite = sfSprite_create();

	check_sprite_path(path);
	texture = create_texture(path);
	sfSprite_setTexture(sprite, texture, 0);
	return (sprite);
}

sfIntRect create_rect(int top, int left, int width, int height)
{
	sfIntRect rect;

	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

sfVector2f create_vect(int x, int y)
{
	sfVector2f vect;

	vect.x = x;
	vect.y = y;
	return (vect);
}

button_t *create_but(sfVector2f pos, sfVector2f size, sfSprite *sprite,
		sfIntRect rect)
{
	button_t *but = malloc(sizeof(button_t));

	if (but == NULL) {
		my_put_err("Invalid malloc for a button\n");
		return (NULL);
	}
	but->exist = 0;
	but->pos = pos;
	but->real_pos.x = pos.x + 370;
	but->real_pos.y = pos.y + 200;
	but->size = size;
	but->sprite = sprite;
	but->rect = rect;
	sfSprite_setTextureRect(but->sprite, but->rect);
	sfSprite_setPosition(but->sprite, but->pos);
	return (but);
}
