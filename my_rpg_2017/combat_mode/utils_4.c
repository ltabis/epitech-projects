/*
** EPITECH PROJECT, 2018
** utils_3.c
** File description:
** antoher utils fucntions
*/

#include "../include/combat.h"

void set_up_end_texts_lose(sfText *lose_1, sfText *lose_2)
{
	sfFont *font = sfFont_createFromFile("pixelmix.ttf");
	sfFloatRect rect;

	if (!lose_1 || !lose_2 || !font)
		return;
	sfText_setFont(lose_1, font);
	sfText_setFont(lose_2, font);
	sfText_setString(lose_1, "Archi naze, vous etes");
	sfText_setString(lose_2, "DECEDE");
	sfText_setScale(lose_2, (sfVector2f){5.0, 5.0});
	rect = sfText_getLocalBounds(lose_1);
	sfText_setOrigin(lose_1, (sfVector2f){rect.left + rect.width / 2,
	rect.top + rect.height / 2});
	rect = sfText_getLocalBounds(lose_2);
	sfText_setOrigin(lose_2, (sfVector2f){rect.left + rect.width / 2,
	rect.top + rect.height / 2});
	sfText_setPosition(lose_1, (sfVector2f){1920 / 2, 400});
	sfText_setPosition(lose_2, (sfVector2f){1920 / 2, 1080 / 2});
	sfText_setColor(lose_1, (sfColor){255, 0, 0, 255});
	sfText_setColor(lose_2, (sfColor){255, 0, 0, 255});
}

void set_up_end_texts_win(sfText *win_1, sfText *win_2)
{
	sfFont *font = sfFont_createFromFile("pixelmix.ttf");
	sfFloatRect rect;

	if (!win_1 || !win_2 || !font)
		return;
	sfText_setFont(win_1, font);
	sfText_setFont(win_2, font);
	sfText_setString(win_1, "Incroyable, vous avez une");
	sfText_setString(win_2, "GROSSE BITE");
	sfText_setScale(win_2, (sfVector2f){5.0, 5.0});
	rect = sfText_getLocalBounds(win_1);
	sfText_setOrigin(win_1, (sfVector2f){rect.left + rect.width / 2,
	rect.top + rect.height / 2});
	rect = sfText_getLocalBounds(win_2);
	sfText_setOrigin(win_2, (sfVector2f){rect.left + rect.width / 2,
	rect.top + rect.height / 2});
	sfText_setPosition(win_1, (sfVector2f){1920 / 2, 400});
	sfText_setPosition(win_2, (sfVector2f){1920 / 2, 1080 / 2});
	sfText_setColor(win_1, (sfColor){0, 0, 255, 255});
	sfText_setColor(win_2, (sfColor){0, 0, 255, 255});
}

sfSprite **create_end_buttons_lose(void)
{
	sfSprite **but = malloc(sizeof(sfSprite *) * 2);
	sfTexture *txt_1 = sfTexture_createFromFile("sprites/replay.png", NULL);
	sfTexture *txt_2 = sfTexture_createFromFile("sprites/quit.png", NULL);

	if (!but || !(but[0] = sfSprite_create()) ||
	!(but[1] = sfSprite_create()) || !txt_1 || !txt_2)
		return (NULL);
	sfSprite_setTexture(but[0], txt_1, 0);
	sfSprite_setTexture(but[1], txt_2, 0);
	sfSprite_setOrigin(but[0], (sfVector2f){100, 50});
	sfSprite_setOrigin(but[1], (sfVector2f){100, 50});
	sfSprite_setPosition(but[0], (sfVector2f){1920 / 4, 1080 - 1080 / 4});
	sfSprite_setPosition(but[1],
	(sfVector2f){1920 - 1920 / 4, 1080 - 1080 / 4});
	return (but);
}

sfSprite *create_end_button_win(void)
{
	sfSprite *but = sfSprite_create();
	sfTexture *txt = sfTexture_createFromFile("sprites/continue.png", NULL);

	if (!but || !txt)
		return (NULL);
	sfSprite_setTexture(but, txt, 0);
	sfSprite_setOrigin(but, (sfVector2f){100, 50});
	sfSprite_setPosition(but, (sfVector2f){1920 / 2, 900});
	return (but);
}

int check_buttons_actions(sfSprite *but, sfRenderWindow *w, int ret)
{
	sfVector2i mos_pos = sfMouse_getPositionRenderWindow(w);
	sfVector2f spr_pos = sfSprite_getPosition(but);

	if (mos_pos.y >= spr_pos.y - 50 && mos_pos.x <= spr_pos.x + 100 &&
	mos_pos.y <= spr_pos.y + 50 && mos_pos.x >= spr_pos.x - 100 &&
	sfMouse_isButtonPressed(sfMouseLeft))
		return (ret);
	else if (mos_pos.y >= spr_pos.y - 50 && mos_pos.x <= spr_pos.x + 100 &&
	mos_pos.y <= spr_pos.y + 50 && mos_pos.x >= spr_pos.x - 100)
		sfSprite_setColor(but, (sfColor){255, 255, 0, 255});
	else
		sfSprite_setColor(but, (sfColor){255, 255, 255, 255});
	return (0);
}
