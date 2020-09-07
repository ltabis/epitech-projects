/*
** EPITECH PROJECT, 2017
** initiate_ressources.c
** File description:
** iniating diiferent ressources
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../include/proto.h"
#include "../include/ressources.h"

ressources_t *load_sprites(ressources_t *res)
{
	res->sprites = malloc(sizeof(sprite_t));
	res->textures = malloc(sizeof(texture_t));
	res->integers->speed = 1;
	res->sprites->sprite = sfSprite_create();
	res->sprites->sprite_background = sfSprite_create();
	return (res);
}

ressources_t *load_textures(ressources_t *res)
{
	res->textures->texture =
		sfTexture_createFromFile("src/images/spritesheet.png", NULL);
	res->textures->background =
		sfTexture_createFromFile("src/images/background.png", NULL);
	return (res);
}

ressources_t *initiate_structs(ressources_t *res)
{
	res->rect.top = 0;
	res->rect.left = 0;
	res->rect.width = 110;
	res->rect.height = 110;
	res->pos.x = 0;
	res->pos.y = 0;
	res->spr_pos.x = 0;
	res->spr_pos.y = 0;
	res->spr_cross_pos.x = 0;
	res->spr_cross_pos.y = 0;
	return (res);
}

ressources_t *initiate_ressources(ressources_t *res)
{
	res->clock = sfClock_create();
	res = construct_window(res);
	res = load_sprites(res);
	res = load_textures(res);
	res = initiate_structs(res);
	return (res);
}
