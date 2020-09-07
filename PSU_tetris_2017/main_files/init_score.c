/*
** EPITECH PROJECT, 2018
** init score
** File description:
** init score
*/

#include "tetris.h"

score_t init_new_score(char *full_name)
{
	score_t *sc = malloc(sizeof(score_t));

	if (!sc)
		exit(84);
	sc->name = NULL;
	sc->score = 0;
	sc->scoreboard = my_strcpy(sc->scoreboard, full_name);
	return (*sc);
}

score_t init_score(char *name)
{
	score_t *sc = malloc(sizeof(score_t));

	if (!sc)
		exit(84);
	sc->name = my_strcpy(sc->name, name);
	sc->score = 0;
	sc->scoreboard = NULL;
	return (*sc);
}

score_t init_full_score(char *name, char *scoreboard, int score)
{
	score_t *sc = malloc(sizeof(score_t));

	if (!sc)
		exit(84);
	sc->name = my_strcpy(sc->name, name);
	sc->scoreboard = my_strcpy(sc->scoreboard, scoreboard);
	sc->score = score;
	return (*sc);
}
