/*
** EPITECH PROJECT, 2018
** tutorial.c
** File description:
** turorial display
*/

#include "proto.h"
#include "menu.h"

void launch_tutorial(sfRenderWindow *w)
{
	sfSprite **tutorials = create_tutorial_sprites((sfVector2f){2, 2});
	sfSprite **buttons = create_tutorial_buttons();
	sfEvent event;

	if (!tutorials || !buttons)
		return;
	for (int i = 0, rt = -1; sfRenderWindow_isOpen(w) && i != -2; rt = -1) {
		while (sfRenderWindow_pollEvent(w, &event))
			rt = check_all_buttons(rt, buttons, w, event);
		i += rt == 0 ? -1 : 0;
		i = rt == 1 ? -2 : i;
		i += rt == 2 ? 1 : 0;
		i = i < 0 && i != -2 ? 0 : i;
		i = i > 4 ? 4 : i;
		if (i >= 0)
			sfRenderWindow_drawSprite(w, tutorials[i], NULL);
		for (unsigned int j = 0; j < 3; j++)
			sfRenderWindow_drawSprite(w, buttons[j], NULL);
		sfRenderWindow_display(w);
	}
}

sfSprite **create_tutorial_buttons(void)
{
	sfSprite **tuto = malloc(sizeof(sfSprite *) * 3);
	sfTexture *but1 = sfTexture_createFromFile(TUTB_ONE, NULL);
	sfTexture *but2 = sfTexture_createFromFile(TUTB_TWO, NULL);
	sfTexture *but3 = sfTexture_createFromFile(TUTB_TRE, NULL);

	if (!tuto || !but1 || !but2 || !but3)
		return (NULL);
	for (unsigned int i = 0; i < 3; i++)
		if (!(tuto[i] = sfSprite_create()))
			return (NULL);
	sfSprite_setTexture(tuto[0], but1, 0);
	sfSprite_setTexture(tuto[1], but2, 0);
	sfSprite_setTexture(tuto[2], but3, 0);
	set_tutorial_but_pos(tuto);
	return (tuto);
}

sfSprite **create_tutorial_sprites(sfVector2f scale)
{
	sfSprite **tuto = malloc(sizeof(sfSprite *) * 5);
	sfTexture *but1 = sfTexture_createFromFile(TUT_FOR, NULL);
	sfTexture *but2 = sfTexture_createFromFile(TUT_ONE, NULL);
	sfTexture *but3 = sfTexture_createFromFile(TUT_TWO, NULL);
	sfTexture *but4 = sfTexture_createFromFile(TUT_TRE, NULL);
	sfTexture *but5 = sfTexture_createFromFile(TUT_FIV, NULL);

	if (!tuto || !but1 || !but2 || !but3 || !but4 || !but5)
		return (NULL);
	for (unsigned int i = 0; i < 5; i++)
		if (!(tuto[i] = sfSprite_create()))
			return (NULL);
	sfSprite_setTexture(tuto[0], but1, 0);
	sfSprite_setTexture(tuto[1], but2, 0);
	sfSprite_setTexture(tuto[2], but3, 0);
	sfSprite_setTexture(tuto[3], but4, 0);
	sfSprite_setTexture(tuto[4], but5, 0);
	for (unsigned int i = 0; i < 5; i++)
		sfSprite_setScale(tuto[i], scale);
	return (tuto);
}

void set_tutorial_but_pos(sfSprite **but)
{
	unsigned int pos = 200;
	sfVector2f origin = {100, 28};

	sfSprite_setOrigin(but[0], origin);
	sfSprite_setOrigin(but[1], origin);
	sfSprite_setOrigin(but[2], origin);
	sfSprite_setPosition(but[0], (sfVector2f){pos, 1040});
	pos += 300;
	sfSprite_setPosition(but[1], (sfVector2f){pos, 1040});
	pos += 300;
	sfSprite_setPosition(but[2], (sfVector2f){pos, 1040});
}

int check_buttons_actions_tuto(sfSprite *but, sfRenderWindow *w,
	int ret, sfEvent event)
{
	sfVector2i mos_pos = sfMouse_getPositionRenderWindow(w);
	sfVector2f spr_pos = sfSprite_getPosition(but);

	if (mos_pos.y >= spr_pos.y - 28 && mos_pos.x <= spr_pos.x + 100 &&
	mos_pos.y <= spr_pos.y + 28 && mos_pos.x >= spr_pos.x - 100 &&
	sfMouse_isButtonPressed(sfMouseLeft) &&
	event.type == sfEvtMouseButtonPressed) {
		sfSprite_setColor(but, (sfColor){255, 255, 0, 255});
		return (ret);
	}
	else if (mos_pos.y >= spr_pos.y - 28 && mos_pos.x <= spr_pos.x + 100 &&
	mos_pos.y <= spr_pos.y + 28 && mos_pos.x >= spr_pos.x - 100)
		sfSprite_setColor(but, (sfColor){255, 255, 255, 150});
	else
		sfSprite_setColor(but, (sfColor){255, 255, 255, 255});
	return (-1);
}
