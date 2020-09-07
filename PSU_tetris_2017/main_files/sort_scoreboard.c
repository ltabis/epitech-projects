/*
** EPITECH PROJECT, 2018
** sort scoreboard
** File description:
** sort scoreboard
*/

#include "tetris.h"

score_t *sort_the_board(score_t *s)
{
	for (int i = 0; s[i].name != NULL && i < 5; i++) {
		if (s[i].score < s[i + 1].score) {
			my_swap_score(&s[i], &s[i + 1]);
		}
	}
	return (s);
}

int check_sort_scoreboard(score_t *s)
{
	int i = 0;
	int count = 0;

	for (; s[i].name != NULL && i < 5; i++) {
		if (s[i].score >= s[i + 1].score)
			count++;
	}
	if (count == i)
		return (0);
	return (1);
}

score_t *sort_scoreboard(score_t *scoreboard)
{
	while (check_sort_scoreboard(scoreboard) == 1)
		sort_the_board(scoreboard);
	return (scoreboard);
}
