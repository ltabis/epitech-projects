/*
** EPITECH PROJECT, 2017
** infinity_mod.c
** File description:
** file that take care of the infinity mod
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "include/proto.h"

object_t *create_objects_static(sfVector2f pos, sfIntRect rect)
{
	object_t *board = malloc(sizeof(object_t) * 7);
	int random = 0;

	srand(time(NULL));
	random = rand() % 300;
	if (random <= 100)
		board = create_room(board, pos, rect);
	else if (random > 100 && random <= 200)
		board = create_forest(board, pos, rect);
	else
		board = create_city(board, pos, rect);
	for (int i = 0; i < 7; i++) 
		if (board[i].initialisation == 1)
			return (board);
	return (board);
}

object_t create_object(char *path, sfVector2f pos, sfIntRect rect)
{
	object_t obj;

	obj.vect = pos;
	obj.rect = rect;
	obj.initialisation = 1;
	obj.speed = 4;
	obj.txt = sfTexture_createFromFile(path, NULL);
	obj.spr = sfSprite_create();
	obj.type = 'M';
	obj.end = 0;
	if (!obj.spr || !obj.txt)
		return (obj);
	sfSprite_setTexture(obj.spr, obj.txt, 0);
	sfSprite_setPosition(obj.spr, pos);
	obj.initialisation = 0;
	return (obj);
}

object_t create_player(char *path)
{
	object_t obj;
	sfVector2f pos;
	sfIntRect rect;

	pos.x = 0;
	pos.y = 545;
	rect.left = 0;
	rect.width = 500;
	rect.height = 348;
	rect.top = 0;
	obj = create_object(path, pos, rect);
	return (obj);
}

sfRenderWindow *construct_window(void)
{
	sfRenderWindow *window;
	sfVideoMode mode = sfVideoMode_getDesktopMode();

	window = sfRenderWindow_create(mode,
	"The tale of washy", sfResize | sfFullscreen, NULL);
	sfRenderWindow_setFramerateLimit(window, 60);
	return (window);
}
