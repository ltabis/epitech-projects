/*
** EPITECH PROJECT, 2018
** pause.c
** File description:
** file that will take care of the pauses functions
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/proto.h"

void display_pause(sfRenderWindow *wind, sfClock *cloc, sfTime time, float sec)
{
	sfSprite *but1 = sfSprite_create();
	sfTexture *txt_but;
	sfVector2f pos;
	int trig = 1;

	for (int j = 0; j != 1; pos.y = 400, pos.x = 400, j = 1);
	txt_but = sfTexture_createFromFile("Sprites/Background/Pause.png", 0);
	sfSprite_setPosition(but1, pos);
	while (trig != 0) {
		time = sfClock_getElapsedTime(cloc);
		sec = time.microseconds / 1000000.0;
		sfSprite_setTexture(but1, txt_but, 0);
		sfRenderWindow_drawSprite(wind, but1, NULL);
		sfRenderWindow_display(wind);
		trig = check_input_when_pause(wind, sec);
	}
	sfClock_restart(cloc);
}

int check_input_when_pause(sfRenderWindow *window, float sec)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) ==
	sfTrue && sec > 0.5) {
		sfRenderWindow_close(window);
		return (0);
	} else if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
		return (0);
	return (1);
}
