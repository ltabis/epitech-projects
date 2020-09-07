/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** set right position with sfView
*/

#include "proto.h"

void set_pos_text(sfView *view, game_s *g)
{
	sfVector2f screen_center = sfView_getCenter(view);

	screen_center.x -= 170;
	sfText_setPosition(g->framerate, screen_center);
	sfText_setPosition(g->sound, screen_center);
}

void set_pos_button(sfVector2f screen_center, button_t *button)
{
	screen_center.x += button->pos.x;
	screen_center.y += button->pos.y;
	sfSprite_setPosition(button->sprite, screen_center);
}

sfVector2f set_pos_sprite(sprite_s *sprite, sfView *view)
{
	sfVector2f screen_center = sfView_getCenter(view);

	screen_center.x -= (sprite->size.x / 2) + 1;
	screen_center.y -= (sprite->size.y / 2) + 1;
	sfSprite_setPosition(sprite->sprite, screen_center);
	return (screen_center);
}

void exit_game(map_all_t *map_all, sfRenderWindow *window)
{
	(void)map_all;
	sfRenderWindow_close(window);
}