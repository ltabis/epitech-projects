/*
** EPITECH PROJECT, 2017
** boot_test.c
** File description:
** my_hunter main functions
*/
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "include/proto.h"
#include "include/mymacro.h"
#include "include/ressources.h"

int main(int argc, char **argv)
{
	ressources_t *res = malloc_ressources(res);

	if (argc == 2)
		if (argv[1][0] == '-' && argv[1][1] == 'h') {
			display_how_to_use();
			return (0);
		}
	res = initiate_ressources(res);
	sfRenderWindow_setFramerateLimit(res->window, 60);
	for (sfEvent event; sfRenderWindow_isOpen(res->window);) {
		while (sfRenderWindow_pollEvent(res->window, &event))
			analyse_events(event, res);
		if (res->integers->miss == 2) {
			game_over(res);
			return (0);
		}
		game_loop(res);
	}
	res = destroy_ressources(res);
	return (0);
}

ressources_t *construct_window(ressources_t *res)
{
	sfVideoMode mode = {WIDTH, HEIGHT, 32};

	res->window = sfRenderWindow_create(mode,
		"Duck killing simulator", sfResize | sfClose, NULL);
	return (res);
}

ressources_t *analyse_events(sfEvent event, ressources_t *res)
{
	sfMouseButtonEvent ev = {sfEvtMouseButtonPressed, sfMouseRight};
	sfVector2i MosPos;
	sfVector2f SprPos;

	if (event.type == sfEvtClosed)
		sfRenderWindow_close(res->window);
	if (event.type == sfEvtMouseButtonPressed) {
		MosPos = sfMouse_getPosition((sfWindow *)res->window);
		SprPos = sfSprite_getPosition(res->sprites->sprite);
		ev.x = MosPos.x;
		ev.y = MosPos.y;
		if ((ev.x <= SprPos.x + 100 && ev.x >= SprPos.x - 100) &&
		(ev.y <= SprPos.y + 100 && ev.y >= SprPos.y - 100)) {
			res = move_sprite_to_beginning(res);
			res->integers->speed++;
		} else
			res->integers->miss++;
	}
	return (res);
}

void game_loop(ressources_t *res)
{
	res->time = sfClock_getElapsedTime(res->clock);
	res->seconds = res->time.microseconds / 1000000.0;
	res = compute_gameplay(res);
	sfRenderWindow_clear(res->window, sfBlack);
	sfSprite_setTexture(res->sprites->sprite,
			res->textures->texture, sfTrue);
        sfSprite_setTexture(res->sprites->sprite_background,
			res->textures->background, sfTrue);
	sfSprite_setTextureRect(res->sprites->sprite, res->rect);
        draw_sprites(res);
}

void draw_sprites(ressources_t *res)
{
	sfRenderWindow_drawSprite(res->window,
				res->sprites->sprite_background, NULL);
	sfRenderWindow_drawSprite(res->window,
				res->sprites->sprite, NULL);
	sfRenderWindow_display(res->window);
	if (res->spr_pos.x >= WIDTH) {
		sfRenderWindow_clear(res->window, sfBlack);
		res = load_texture_alt1(res);
		res->integers->speed *= -1;
	}
	else if (res->spr_pos.x < 0) {
		sfRenderWindow_clear(res->window, sfBlack);
		res = load_texture_alt2(res);
		res->integers->speed *= -1;
	}
}
