/*
** EPITECH PROJECT, 2018
** window.c
** File description:
** functions for windows
*/

#include <stdlib.h>
#include "proto.h"
#include <time.h>

sfRenderWindow *create_window(void)
{
	sfVideoMode size = sfVideoMode_getDesktopMode();
	sfRenderWindow *window =
	sfRenderWindow_create(size, TITLE, sfFullscreen | sfClose, NULL);

	srand(time(NULL));
	sfRenderWindow_setFramerateLimit(window, 120);
	return (window);
}
