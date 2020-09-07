/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** game loop for my_sokoban project
*/
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/proto.h"

void game_loop(map_t *map)
{
	int input = 0;

	map =setup_window(map);
	map = put_targ_coords(map);
	while (input != 27) {
		input = wgetch(stdscr);
		map = compute_gameplay(map, input);
		verify_window_size(map);
		if (map->boxes_stuck >= map->boxes)
			display_game_loose(map);
		verify_score(map);
		werase(stdscr);
		display_game(map);
		refresh();
	}
	endwin();
}

void display_game(map_t *map)
{
	for (int i = 0; i < map->y; i++)
		mvprintw(i, 0, map->x_file[i]);
}

void display_game_win(map_t *map)
{
	for (int i = 0; i < map->y - 1; i++)
		free(map->x_file[i]);
	for (int i = 0; i < map->y - 1; i++)
		free(map->x_file_save[i]);
	free(map->x_file);
	free(map->x_file_save);
	free(map);
	refresh();
	endwin();
	exit(0);
}

map_t *setup_window(map_t *map)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	werase(stdscr);
	display_game(map);
	refresh();
	return (map);
}

void verify_window_size(map_t *map)
{
	int x = 0;
	int y = 0;
	char str[] = "The window is too small !";

	while (y <= map->y || x <= map->x) {
		getmaxyx(stdscr, y, x);
		werase(stdscr);
		mvprintw(y / 2, x / 2, str);
		refresh();
	}
}
