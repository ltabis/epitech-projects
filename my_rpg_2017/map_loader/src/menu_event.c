/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** menu_event
*/

#include "proto.h"

void mouse_event(sfEvent event, map_all_t *map_all, sfRenderWindow *window)
{
	game_s *game = map_all->game;
	sfVector2f click_pos;
	sfVector2f cursor_pos;

	if (event.type == sfEvtMouseMoved) {
		manage_cursor_move(event.mouseMove, &cursor_pos);
		button_hover_fct_pointer(game, cursor_pos);
	}
	manage_mouse_click(event.mouseButton, &click_pos);
	if (event.type == sfEvtMouseButtonPressed)
		button_click_fct_pointer(game, click_pos);
	if (event.type == sfEvtMouseButtonReleased)
		button_activate_fct_pointer(map_all, click_pos, window);
}

void analyse_event(sfEvent event, map_all_t *map_all, sfRenderWindow *window)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event.type == sfEvtKeyReleased)
		key_fct_array(event, map_all);
	mouse_event(event, map_all, window);
}

void manage_mouse_click(sfMouseButtonEvent event, sfVector2f *click)
{
	click->x = event.x;
	click->y = event.y;
}

void manage_cursor_move(sfMouseMoveEvent event, sfVector2f *cursor)
{
	cursor->x = event.x;
	cursor->y = event.y;
}

int check_button(button_t *button, sfVector2f mouse_pos)
{
	if (mouse_pos.x >= button->real_pos.x &&
	mouse_pos.x <= button->real_pos.x + button->size.x)
		if (mouse_pos.y >= button->real_pos.y &&
		mouse_pos.y <= button->real_pos.y + button->size.y)
			return (1);
	return (0);
}
