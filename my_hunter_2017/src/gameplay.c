/*
** EPITECH PROJECT, 2017
** gameplay.c
** File description:
** functions for the gamaplay of the game
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../include/proto.h"
#include "../include/mymacro.h"
#include "../include/ressources.h"

ressources_t *compute_gameplay(ressources_t *res)
{
	if (res->seconds > 0.02) {
		sfSprite_setPosition(res->sprites->sprite,
				res->spr_pos);
		res->spr_pos.x += res->integers->speed;
	}
	if (res->seconds > 0.105) {
		move_rect(&res->rect, 110, 330);
		sfClock_restart(res->clock);
	}
	return (res);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
	if (rect->left <= offset)
		rect->left += 110;
	else if (rect->left > offset)
		rect->left = 0;
}

ressources_t *move_sprite_to_beginning(ressources_t *res)
{
	unsigned int random = rand() % HEIGHT;

	my_putstr("Well done !\n");
	my_putstr("score : ");
	my_put_nbr(res->integers->hit + 1);
	my_putchar('\n');
	res->integers->hit++;
	if (random >= HEIGHT - 50)
		random = HEIGHT - 100;
	if (random <= 50)
		random += 100;
	sfRenderWindow_clear(res->window, sfBlack);
	res->spr_pos.y = random;
	res->spr_pos.x = 0;
	return (res);
}

void display_how_to_use(void)
{
	my_putstr("\nIT'S TIME TO KICK ASS AND SHOOT DUCKS\n\n");
	my_putstr("How to play :\nUse right click to shoot\n");
	my_putstr("The game ends if you miss 2 times\n");
	my_putstr("Good luck pal!\n\n");
}

void game_over(ressources_t *res)
{
	my_putstr("Final score: ");
	my_put_nbr(res->integers->hit);
	my_putchar('\n');
	my_putstr("Final missed: ");
	my_put_nbr(res->integers->miss);
	my_putchar('\n');
}
