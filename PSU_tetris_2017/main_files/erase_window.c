/*
** EPITECH PROJECT, 2018
** erase window
** File description:
** erase window
*/

#include "tetris.h"

void erase_window(window_t *w)
{
	erase();
	werase(w->game);
	werase(w->next);
	werase(w->highscore);
}
