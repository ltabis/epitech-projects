/*
** EPITECH PROJECT, 2018
** gameplay.h
** File description:
** gameplay functions prototypes
*/

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "debug.h"
#include "args.h"

char **search_best_players(void);
int check_valid_line(char *, unsigned int);
control_t compute_gameplay(control_t , tetrimino_t *, window_t *, char **);
void display_best_players(window_t *, int);

#endif /* !GAMEPLAY_H */
