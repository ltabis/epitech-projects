/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utilities for my_hunter
*/
#include <stdlib.h>
#include "../include/proto.h"
#include "../include/ressources.h"

ressources_t *malloc_ressources(ressources_t *res)
{
	res = malloc(sizeof(ressources_t));

	if (!res)
		return (NULL);
	res = malloc_integers(res);
	res->integers->miss = 0;
	res->integers->hit = 0;
	return (res);
}

ressources_t *malloc_integers(ressources_t *res)
{
	res->integers = malloc(sizeof(integ_t));
	return (!res ? NULL : res);
}

ressources_t *destroy_ressources(ressources_t *res)
{
	sfRenderWindow_destroy(res->window);
	sfSprite_destroy(res->sprites->sprite);
	sfSprite_destroy(res->sprites->sprite_background);
        sfTexture_destroy(res->textures->texture);
	sfTexture_destroy(res->textures->background);
        sfClock_destroy(res->clock);
	free(res->sprites);
	free(res->textures);
	free(res->integers);
	free(res);
	return (res);
}

ressources_t *load_texture_alt1(ressources_t *res)
{
	res->textures->texture =
		sfTexture_createFromFile("src/images/spritesheet2.png", NULL);
	return (res);
}

ressources_t *load_texture_alt2(ressources_t *res)
{
	res->textures->texture =
		sfTexture_createFromFile("src/images/spritesheet.png", NULL);
	return (res);
}
