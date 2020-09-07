/*
** EPITECH PROJECT, 2018
** inventory.c
** File description:
** inventory managment
*/

#include "../include/combat.h"

void open_inventory(sfRenderWindow *w)
{
	sfRectangleShape *inventory = launch_inventory_anim(w);

	if (!inventory)
		return;
	while (!sfKeyboard_isKeyPressed(sfKeyTab)){}
	end_inventory_anim(inventory, w);
	sfRectangleShape_destroy(inventory);
}

sfRectangleShape *launch_inventory_anim(sfRenderWindow *w)
{
	sfRectangleShape *inventory = sfRectangleShape_create();
	sfFloatRect rect;

	if (!inventory)
		return (NULL);
	sfRectangleShape_setSize(inventory, (sfVector2f){192, 108});
	rect = sfRectangleShape_getLocalBounds(inventory);
	sfRectangleShape_setOrigin(inventory,
	(sfVector2f){rect.left + rect.width / 2.0f,
	rect.top + rect.height / 2.0f});
	sfRectangleShape_setPosition(inventory, (sfVector2f){970, 540});
	sfRectangleShape_setFillColor(inventory, (sfColor){255, 255, 255, 100});
	for (sfVector2f size = {0, 0}; size.x < 1920;) {
		size = sfRectangleShape_getScale(inventory);
		sfRenderWindow_clear(w, sfBlack);
		sfRectangleShape_scale(inventory, (sfVector2f){1.1, 1.1});
		sfRenderWindow_drawRectangleShape(w, inventory, NULL);
		sfRenderWindow_display(w);
	}
	return (inventory);
}

void end_inventory_anim(sfRectangleShape *inventory, sfRenderWindow *w)
{
	sfVector2f size = sfRectangleShape_getScale(inventory);

	if (!inventory)
		return;
	while (size.x > 100) {
		size = sfRectangleShape_getScale(inventory);
		sfRenderWindow_clear(w, sfBlack);
		sfRectangleShape_scale(inventory, (sfVector2f){0.9, 0.9});
		sfRenderWindow_drawRectangleShape(w, inventory, NULL);
		sfRenderWindow_display(w);
	}
}
