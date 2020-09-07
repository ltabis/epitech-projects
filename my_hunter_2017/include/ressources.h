/*
** EPITECH PROJECT, 2017
** ressources.h
** File description:
** ressources needed by my_huner
*/
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

#ifndef RESSOURCES_H_
#define RESSOURCES_H_

typedef struct sprite_s {
	sfSprite *sprite;
	sfSprite *sprite_background;
} sprite_t;

typedef struct texture_s {
        sfTexture *texture;
        sfTexture *background;
} texture_t;

typedef struct integ_s {
	int speed;
	int miss;
        int hit;
} integ_t;

typedef struct ressources_s {
	sfRenderWindow *window;
	sprite_t *sprites;
	texture_t *textures;
	integ_t *integers;
	sfVector2u pos;
	sfVector2f spr_pos;
	sfVector2f spr_cross_pos;
	sfIntRect rect;
	sfIntRect rect_crosshair;
	sfClock *clock;
	sfTime time;
	float seconds;
} ressources_t;

#endif /* !RESSOURCES_H_ */
