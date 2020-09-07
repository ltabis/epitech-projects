/*
** EPITECH PROJECT, 2018
** choose_perso.c
** File description:
** functions for chosen caractere
*/

#include <stdlib.h>
#include "menu.h"
#include "map.h"
#include "proto.h"

void change_sprite_player(sfEvent event, sfVector2i pos, player_t *player,
		choose_player_t *var)
{
	if (check_pos(var->buttons[0], pos) == 1 ||
	event.key.code == sfKeyRight) {
		move_rect_player_right(player);
		move_rect_miniature_right(var);
	} else if (check_pos(var->buttons[1], pos) == 1 ||
	event.key.code == sfKeyLeft) {
		move_rect_player_left(player);
		move_rect_miniature_left(var);
	} else if (check_pos(var->buttons[2], pos) == 1)
		var->stop = 1;
}

void manage_event(sfEvent event, sfRenderWindow *window,
player_t *player, choose_player_t * var)
{
	sfVector2i pos = {0, 0};

	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event.type == sfEvtMouseButtonReleased) {
		pos = sfMouse_getPositionRenderWindow(window);
		change_sprite_player(event, pos, player, var);
	} if (event.type == sfEvtKeyReleased)
		change_sprite_player(event, pos, player, var);
}

void display(choose_player_t *var, sfRenderWindow *window, player_t *player)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, var->bg, 0);
	sfRenderWindow_drawSprite(window, var->miniature, 0);
	sfRenderWindow_drawSprite(window, player->sprite, 0);
	sfRenderWindow_drawSprite(window, var->buttons[0]->sprite, 0);
	sfRenderWindow_drawSprite(window, var->buttons[1]->sprite, 0);
	sfRenderWindow_drawSprite(window, var->buttons[2]->sprite, 0);
	sfRenderWindow_display(window);
}

void set_player_rect(sfIntRect *src, sfIntRect *dest)
{
	dest->width = src->width;
	dest->height = src->height;
	dest->top = src->top;
	dest->left = src->left;
}

int choose_player(player_t *player,
	sfRenderWindow *window, UNUSED sfView *view)
{
	int bool_e = 1;
	player_t *tmp = player;
	choose_player_t *var = init_menu_choose_player();
	sfVector2f save = sfSprite_getPosition(player->sprite);

	prepare_player(tmp);
	while (bool_e == 1 && sfRenderWindow_isOpen(window) && var->stop != 1) {
		display(var, window, player);
		while (sfRenderWindow_pollEvent(window, &var->event) &&
		bool_e == 1) {
			bool_e =
			sfKeyboard_isKeyPressed(sfKeyEscape) ? 0 : bool_e;
			manage_event(var->event, window, player, var);
		}
	}
	set_player_rect(&(tmp->rect), &(player->rect));
	free_choose_menu(var);
	player->position = save;
	return (player->rect.left);
}
