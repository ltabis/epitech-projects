/*
** EPITECH PROJECT, 2018
** inventory.c
** File description:
** functions for inventory interaction
*/

#include "proto.h"

int *init_inventory(void)
{
	int *result = malloc(sizeof(int) * INV_SIZE);

	result[0] = 100;
	result[1] = 200;
	for (int i = 2; i < INV_SIZE; i++)
		result[i] = 0;
	return (result);
}

void disp_inventory(sfRenderWindow *window, sfView *view, obj_t *obj, int *inv)
{
	int i = 0;
	sfVector2f middle = sfView_getCenter(view);
	sfVector2f pos = {middle.x + 153, middle.y - 260};
	obj_t *tmp = obj;

	for (; i < INV_SIZE && inv[i] != 0; i++) {
		for (tmp = obj; tmp != NULL && tmp->id != inv[i];
		tmp = tmp->next);
		sfSprite_setPosition(tmp->sprite, pos);
		if (pos.x > middle.x + 347) {
			pos.x = middle.x + 153;
			pos.y += 88;
		} else
			pos.x += 97;
		sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
	}
}
