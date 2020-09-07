/*
** EPITECH PROJECT, 2018
** handle border
** File description:
** handle border
*/

#include "tetris.h"

void handle_windows(window_t *w, int y_game,
	int x_game, control_t controls)
{
	int x = 0;
	int y = 0;

	getmaxyx(stdscr, y, x);
	while (y <= y_game || x <= x_game) {
		werase(w->game);
		werase(w->next);
		werase(w->highscore);
		getmaxyx(stdscr, y, x);
		mvprintw(y / 2, x / 2 - 22,
		"Your terminal is too small, please extend it");
		refresh();
		erase();
	}
	display_borders(w);
	wrefresh(w->game);
	wrefresh(w->highscore);
	if (controls.act_next_tetr == 0)
		wrefresh(w->next);
	refresh();
}

void get_window_sizes(window_t *w, int *x, int *y)
{
	int x_cur = 0;
	int y_cur = 0;

	*x = 0;
	*y = 0;
	getmaxyx(w->game, y_cur, x_cur);
	*x += x_cur;
	*y = (y_cur > *y ? y_cur : *y);
	getmaxyx(w->next, y_cur, x_cur);
	*x += x_cur;
	*y = (y_cur > *y ? y_cur : *y);
	getmaxyx(w->highscore, y_cur, x_cur);
	*x += x_cur;
	*y = (y_cur > *y ? y_cur : *y);
}

void display_borders(window_t *w)
{
	wattron(w->game, COLOR_PAIR(1));
	wattron(w->highscore, COLOR_PAIR(3));
	wborder(w->highscore, 0, 0, 0, 0, '/', '\\', '\\', '/');
	wborder(w->game, 0, 0, 0, 0, '/', '\\', '\\', '/');
	wborder(w->next, 0, 0, 0, 0, 0, 0, 0, 0);
	mvwprintw(w->next, 0, 0, "Next");
	wattroff(w->game, COLOR_PAIR(1));
	wattroff(w->highscore, COLOR_PAIR(3));
}