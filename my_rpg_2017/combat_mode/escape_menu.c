/*
** EPITECH PROJECT, 2018
** escape_menu.c
** File description:
** escape menu functions for the combat mod
*/

#include "combat.h"

char display_escape_menu(sfRenderWindow *w, map_cb_t *map)
{
	sfRectangleShape *escape = launch_escape_anim(w, map);
	sfSprite **but = create_escape_buttons();
	char stop = -1;

	if (!but)
		return (-1);
	while (stop == -1) {
		for (sfEvent ev; sfRenderWindow_pollEvent(w, &ev);)
			stop = check_buttons_ret_value(but, w, ev);
		sfRenderWindow_clear(w, sfBlack);
		draw_2d_map(w, *map,
		(sfVector2i){MAP_SIZE, MAP_SIZE}, map->state);
		sfRenderWindow_drawRectangleShape(w, escape, NULL);
		for (unsigned int i = 0; i < 3; i++)
			sfRenderWindow_drawSprite(w, but[i], NULL);
		sfRenderWindow_display(w);
	}
	sfRectangleShape_destroy(escape);
	return (stop);
}

sfRectangleShape *launch_escape_anim(sfRenderWindow *w, map_cb_t *map)
{
	sfRectangleShape *escape = sfRectangleShape_create();
	sfFloatRect re;

	if (!escape)
		return (NULL);
	sfRectangleShape_setSize(escape, (sfVector2f){192, 108});
	re = sfRectangleShape_getLocalBounds(escape);
	sfRectangleShape_setOrigin(escape,
	(sfVector2f){re.left + re.width / 2.0f, re.top + re.height / 2.0f});
	sfRectangleShape_setPosition(escape, (sfVector2f){970, 540});
	sfRectangleShape_setFillColor(escape, (sfColor){100, 100, 100, 200});
	for (sfVector2f size = {0, 0}; size.x < 5;) {
		size = sfRectangleShape_getScale(escape);
		sfRenderWindow_clear(w, sfBlack);
		draw_2d_map(w, *map, (sfVector2i){20, 20}, map->state);
		sfRectangleShape_scale(escape, (sfVector2f){1.1, 1.1});
		sfRenderWindow_drawRectangleShape(w, escape, NULL);
		sfRenderWindow_display(w);
	}
	return (escape);
}

sfSprite **create_escape_buttons(void)
{
	sfSprite **tuto = malloc(sizeof(sfSprite *) * 3);
	sfTexture *but1 = sfTexture_createFromFile(ESC_ONE, NULL);
	sfTexture *but2 = sfTexture_createFromFile(ESC_TWO, NULL);
	sfTexture *but3 = sfTexture_createFromFile(ESC_TRE, NULL);

	if (!tuto || !but1 || !but2 || !but3)
		return (NULL);
	for (unsigned int i = 0; i < 3; i++)
		if (!(tuto[i] = sfSprite_create()))
			return (NULL);
	sfSprite_setTexture(tuto[0], but1, 0);
	sfSprite_setTexture(tuto[1], but2, 0);
	sfSprite_setTexture(tuto[2], but3, 0);
	set_escape_but_pos(tuto);
	return (tuto);
}

void set_escape_but_pos(sfSprite **but)
{
	unsigned int pos = 1080 / 3;
	sfVector2f origin = {100, 28};

	sfSprite_setOrigin(but[0], origin);
	sfSprite_setOrigin(but[1], origin);
	sfSprite_setOrigin(but[2], origin);
	origin.x = 2;
	origin.y = 2;
	sfSprite_setScale(but[0], origin);
	sfSprite_setScale(but[1], origin);
	sfSprite_setScale(but[2], origin);
	sfSprite_setPosition(but[0], (sfVector2f){1920 / 2, pos});
	pos += 200;
	sfSprite_setPosition(but[1], (sfVector2f){1920 / 2, pos});
	pos += 200;
	sfSprite_setPosition(but[2], (sfVector2f){1920 / 2, pos});
}

char check_buttons_actions_escape(sfSprite *but, sfRenderWindow *w,
	int ret, sfEvent event)
{
	sfVector2i mos_pos = sfMouse_getPositionRenderWindow(w);
	sfVector2f spr_pos = sfSprite_getPosition(but);

	if (mos_pos.y >= spr_pos.y - 56 && mos_pos.x <= spr_pos.x + 200 &&
	mos_pos.y <= spr_pos.y + 56 && mos_pos.x >= spr_pos.x - 200 &&
	sfMouse_isButtonPressed(sfMouseLeft) &&
	event.type == sfEvtMouseButtonPressed)
		return (ret);
	else if (mos_pos.y >= spr_pos.y - 56 && mos_pos.x <= spr_pos.x + 200 &&
	mos_pos.y <= spr_pos.y + 56 && mos_pos.x >= spr_pos.x - 200)
		sfSprite_setColor(but, (sfColor){255, 255, 0, 255});
	else
		sfSprite_setColor(but, (sfColor){255, 255, 255, 255});
	return (-1);
}
