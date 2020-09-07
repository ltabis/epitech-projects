/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** functions for main menu
*/

#include "proto.h"
#include "menu.h"

int main_menu(sfRenderWindow *window, sfSprite **buttons,
	sfSprite *corewar)
{
	int ret = -1;

	sfRenderWindow_drawSprite(window, corewar, NULL);
	sfRenderWindow_drawSprite(window, buttons[0], NULL);
	sfRenderWindow_drawSprite(window, buttons[1], NULL);
	sfRenderWindow_drawSprite(window, buttons[2], NULL);
	sfRenderWindow_drawSprite(window, buttons[3], NULL);
	for (unsigned int i = 0; i < 4 && ret == -1; i++)
		ret = check_buttons_actions_but(buttons[i], window, i);
	sfRenderWindow_display(window);
	return (sfKeyboard_isKeyPressed(sfKeyEscape) ? 3 : ret);
}

sfSprite **create_menu_buttons(void)
{
	sfSprite **buttons = malloc(sizeof(sfSprite *) * 4);
	sfTexture *but1 = sfTexture_createFromFile(TXT_ONE, NULL);
	sfTexture *but2 = sfTexture_createFromFile(TXT_TWO, NULL);
	sfTexture *but3 = sfTexture_createFromFile(TXT_TRE, NULL);
	sfTexture *but4 = sfTexture_createFromFile(TXT_FOR, NULL);

	if (!buttons || !but1 || !but2 || !but3 || !but4)
		return (NULL);
	for (unsigned int i = 0; i < 4; i++)
		if (!(buttons[i] = sfSprite_create()))
			return (NULL);
	sfSprite_setTexture(buttons[0], but1, 0);
	sfSprite_setTexture(buttons[1], but2, 0);
	sfSprite_setTexture(buttons[2], but3, 0);
	sfSprite_setTexture(buttons[3], but4, 0);
	set_menu_button_pos(buttons);
	return (buttons);
}

void set_menu_button_pos(sfSprite **but)
{
	unsigned int pos = 1080 / 3;
	sfVector2f origin = {100, 28};
	sfVector2f scale = {2, 2};

	sfSprite_setOrigin(but[0], origin);
	sfSprite_setOrigin(but[1], origin);
	sfSprite_setOrigin(but[2], origin);
	sfSprite_setOrigin(but[3], origin);
	sfSprite_setScale(but[0], scale);
	sfSprite_setScale(but[1], scale);
	sfSprite_setScale(but[2], scale);
	sfSprite_setScale(but[3], scale);
	sfSprite_setPosition(but[0], (sfVector2f){1920 / 2, pos});
	pos += 150;
	sfSprite_setPosition(but[1], (sfVector2f){1920 / 2, pos});
	pos += 150;
	sfSprite_setPosition(but[2], (sfVector2f){1920 / 2, pos});
	pos += 150;
	sfSprite_setPosition(but[3], (sfVector2f){1920 / 2, pos});
}

int check_buttons_actions_but(sfSprite *but, sfRenderWindow *w,
	int ret)
{
	sfVector2i mos_pos = sfMouse_getPositionRenderWindow(w);
	sfVector2f spr_pos = sfSprite_getPosition(but);

	if (mos_pos.y >= spr_pos.y - 56 && mos_pos.x <= spr_pos.x + 200 &&
	mos_pos.y <= spr_pos.y + 56 && mos_pos.x >= spr_pos.x - 200 &&
	sfMouse_isButtonPressed(sfMouseLeft))
		return (ret);
	else if (mos_pos.y >= spr_pos.y - 56 && mos_pos.x <= spr_pos.x + 200 &&
	mos_pos.y <= spr_pos.y + 56 && mos_pos.x >= spr_pos.x - 200)
		sfSprite_setColor(but, (sfColor){255, 255, 255, 150});
	else
		sfSprite_setColor(but, (sfColor){255, 255, 255, 255});
	return (-1);
}

sfSprite *create_corewar_sprite(void)
{
	sfSprite *corewar = sfSprite_create();
	sfTexture *txt = sfTexture_createFromFile(
	"ressources/pictures/menu/main_menu/axel.png", NULL);

	if (!corewar || !txt)
		return (NULL);
	sfSprite_setTexture(corewar, txt, 0);
	sfSprite_setOrigin(corewar, (sfVector2f){350, 478});
	sfSprite_setPosition(corewar, (sfVector2f){1920 / 2, 1080 / 2});
	sfSprite_setColor(corewar, (sfColor){255, 255, 255, 100});
	return (corewar);
}
