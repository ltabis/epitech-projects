/*
** EPITECH PROJECT, 2018
** display_background.c
** File description:
** displaying the background
*/

#include "../include/particles.h"
#include "../include/monster.h"

background_t *init_background(sfRenderWindow *window)
{
	background_t *back = malloc(sizeof(background_t));

	if (!back ||
	(back->buffer = framebuffer_create(1920, 1080)) == NULL)
		return (NULL);
	for (unsigned int i = 0, random = 0;
	i < back->buffer->width * back->buffer->height * 4; i += 4) {
		random = rand() % 1000;
		if (random > 980) {
			back->buffer->pixels[i] = 255;
			back->buffer->pixels[i + 1] = 255;
			back->buffer->pixels[i + 2] = 255;
			back->buffer->pixels[i + 3] = 255;
		}
	}
	back->spr = sfSprite_create();
	back->txt = sfTexture_create(back->buffer->width, back->buffer->height);
	sfSprite_setTexture(back->spr, back->txt, 0);
	sfRenderWindow_drawSprite(window, back->spr, NULL);
	return (back);
}

void display_background(background_t *back, int color,
	sfRenderWindow *w, player_stat_t *player)
{
	sfRenderWindow_clear(w, sfBlack);
	for (unsigned int i = 0, demi = 0;
	i < back->buffer->width * back->buffer->height * 4; i += 4) {
		if (demi % 2 == 0 && back->buffer->pixels[i] == 255) {
			change_background_color_1(back, i, color, player);
			demi++;
		} else if (demi % 2 != 0 && back->buffer->pixels[i] == 255) {
			change_background_color_2(back, i, color, player);
			demi++;
		}
	}
	sfTexture_updateFromPixels(back->txt, back->buffer->pixels,
	back->buffer->width, back->buffer->height, 0, 0);
}

void compute_background(sfRenderWindow *window,
	background_t *back, sfClock *clock, player_stat_t *player)
{
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 100000.0;
	static int color = 0;
	static char mul = '+';

	if (seconds > 0.01) {
		color += color != 255 && mul == '+' ? 5 : 0;
		color -= color != 0 && mul == '-' ? 5 : 0;
		mul = color == 255 && mul == '+' ? '-' : mul;
		mul = color == 0 && mul == '-' ? '+' : mul;
		display_background(back, color, window, player);
		sfClock_restart(clock);
	}
	sfRenderWindow_drawSprite(window, back->spr, NULL);
}
