/*
** EPITECH PROJECT, 2018
** end_events.c
** File description:
** ending screens
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/proto.h"

int display_won_game(sfRenderWindow *window, sfText *scr)
{
	sfSprite *spr = sfSprite_create();
	sfTexture *txt = sfTexture_createFromFile
	("Sprites/Background/End_screen2.png", NULL);

	while (sfRenderWindow_isOpen(window)) {
		sfSprite_setTexture(spr, txt, 0);
		sfRenderWindow_drawSprite(window, spr, NULL);
		sfRenderWindow_drawText(window, scr, NULL);
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeySpace)) {
			sfSprite_destroy(spr);
			sfTexture_destroy(txt);
			return (1);
		} else if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
			sfRenderWindow_close(window);
			sfSprite_destroy(spr);
			sfTexture_destroy(txt);
		}
	}
	return (0);
}

int display_lost_game(sfRenderWindow *window, sfText *scr)
{
	sfSprite *spr = sfSprite_create();
	sfTexture *txt = sfTexture_createFromFile
	("Sprites/Background/End_screen.png", NULL);

	while (sfRenderWindow_isOpen(window)) {
		sfSprite_setTexture(spr, txt, 0);
		sfRenderWindow_drawSprite(window, spr, NULL);
		sfRenderWindow_drawText(window, scr, NULL);
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeySpace)) {
			sfSprite_destroy(spr);
			sfTexture_destroy(txt);
			return (1);
		} else if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
			sfRenderWindow_close(window);
			sfSprite_destroy(spr);
			sfTexture_destroy(txt);
		}
	}
	return (0);
}

sfText *create_text(void)
{
	sfVector2f vector;
	sfText *Score;
	sfFont *font;

	vector.x = 1920 / 2 - 100;
	vector.y = 30;
	Score = sfText_create();
	if (!Score)
		return (NULL);
	font = sfFont_createFromFile("Sprites/Background/pixelmix.ttf");
	sfText_setFont(Score, font);
	sfText_setString(Score, "0%");
	sfText_setPosition(Score, vector);
	return (Score);
}

sfText *update_text(sfText *Score, int x, sfRenderWindow *window)
{
	sfText_setString(Score, my_put_char(x));
	sfRenderWindow_drawText(window, Score, NULL);
	sfRenderWindow_display(window);
	return (Score);
}

char *my_put_char(int nb)
{
	int i = 1;
	int nb2 = nb;
	char *c;

	for (; nb >= 10; i++)
		nb = nb / 10;
	c = malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	c[0] = (nb2 % 10) + 48;
	for (i = 1; nb2 >= 10; i++) {
		nb2 = nb2 / 10;
		c[i] = (nb2 % 10) + 48;
	}
	c[i] = '\0';
	c = my_revstr(c);
	return (c);
}
