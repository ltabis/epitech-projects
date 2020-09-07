/*
** EPITECH PROJECT, 2018
** window
** File description:
** window
*/

#ifndef WINDOW_H_
#define WINDOW_H_

typedef struct window {
	WINDOW *game;
	WINDOW *next;
	WINDOW *highscore;
	int x_game;
	int y_game;
	int x_next;
	int y_next;
	int x_highscore;
	int y_highscore;
} window_t;

#endif
