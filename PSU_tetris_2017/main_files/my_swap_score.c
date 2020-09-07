/*
** EPITECH PROJECT, 2018
** swap score_t
** File description:
** swap score_t
*/

#include "tetris.h"

void my_swap_score(score_t *scoreb, score_t *s)
{
	score_t tmp = init_full_score(scoreb->name,
					scoreb->scoreboard,
					scoreb->score);
	*scoreb = init_full_score(s->name, s->scoreboard, s->score);
	*s = init_full_score(tmp.name, tmp.scoreboard, tmp.score);
}
