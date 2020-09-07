/*
** EPITECH PROJECT, 2018
** lore.c
** File description:
** functions for display lore
*/

#include "menu.h"
#include "proto.h"

button_t *init_but(void)
{
	sfVector2f but_pos = create_vect(150, 1000);
	sfVector2f but_size = create_vect(200, 56);
	sfIntRect but_rect = create_rect(0, 0, 200, 56);
	button_t *button = create_but(but_pos, but_size,
	create_sprite(TUTB_TWO), but_rect);

	return (button);
}

int check_click(sfVector2i click, button_t *button)
{
	int lim_x = button->pos.x + button->size.x;
	int lim_y = button->pos.y + button->size.y;

	if (click.x > button->pos.x && click.x < lim_x
	&& click.y > button->pos.y && click.y < lim_y)
		return (1);
	return (0);
}

void disp_lore(sfRenderWindow *win, sfSprite *lore, sfSprite *but)
{
	sfRenderWindow_clear(win, sfBlack);
	sfRenderWindow_drawSprite(win, lore, NULL);
	sfRenderWindow_drawSprite(win, but, NULL);
	sfRenderWindow_display(win);
}

void manage_lore_event(sfEvent event, sfRenderWindow *win, button_t *button,
int *stop)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(win);

	if (event.type == sfEvtClosed) {
		sfRenderWindow_close(win);
	} else if (event.type == sfEvtMouseButtonReleased) {
		if (check_click(pos, button) == 1)
			(*stop) = 1;
	} else if (event.type == sfEvtMouseButtonPressed) {
		if (check_click(pos, button) == 1)
			sfSprite_setColor(button->sprite, sfYellow);
	}
}

void launch_lore(sfRenderWindow *win)
{
	int stop = 0;
	sfVector2i pos;
	sfSprite *lore = create_sprite(IMG_LORE);
	button_t *but = init_but();
	sfEvent event;

	while (sfRenderWindow_isOpen(win) && but != NULL && stop == 0) {
		pos = sfMouse_getPositionRenderWindow(win);
		disp_lore(win, lore, but->sprite);
		if (check_click(pos, but) == 1 &&
		event.type != sfEvtMouseButtonPressed)
			sfSprite_setColor(but->sprite,
			(sfColor){255, 255, 255, 150});
		else if (event.type != sfEvtMouseButtonPressed)
			sfSprite_setColor(but->sprite,
			(sfColor){255, 255, 255, 255});
		while (sfRenderWindow_pollEvent(win, &event))
			manage_lore_event(event, win, but, &stop);
	}
}
