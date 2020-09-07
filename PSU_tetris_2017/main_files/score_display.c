/*
** EPITECH PROJECT, 2018
** score_display.c
** File description:
** search score to be displayed
*/

#include "tetris.h"

void display_best_players(window_t *w, int score)
{
	int y = 3;
	score_t *s = read_score_file();

	score = score;
	mvwprintw(w->highscore, 1, 8, "Hall of Fame");
	for (int i = 0; s[i].name != NULL; i++) {
		mvwprintw(w->highscore, y, 3, "%s\n", s[i].scoreboard);
		y += 1;
	}
	y += 2;
	mvwprintw(w->highscore, y, 8, "Your score :\n\t   %d", score);
	wrefresh(w->highscore);
}

int check_valid_line(char *line, unsigned int i)
{
	char *tmp = line;
	char step = 0;

	for (; tmp[0]; tmp++) {
		if (tmp[0] == ' ' && tmp[1] == '=')
			step = 1;
		if (tmp[0] < '0' && tmp[0] > '9' && step == 1) {
			i--;
			return (i);
		}
	}
	if (!tmp[0] && step == 1)
		return (i);
	i--;
	return (i);
}
