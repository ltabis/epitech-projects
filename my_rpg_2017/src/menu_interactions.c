/*
** EPITECH PROJECT, 2018
** menu_interactions.c
** File description:
** functions for interact with menu
*/

#include "menu.h"

int check_pos(button_t *button, sfVector2i mouse_pos)
{
	if (mouse_pos.x >= button->pos.x && mouse_pos.x <= button->pos.x
	+ button->size.x)
		if (mouse_pos.y >= button->pos.y && mouse_pos.y <=
		button->pos.y + button->size.y)
			return (1);
	return (0);
}
