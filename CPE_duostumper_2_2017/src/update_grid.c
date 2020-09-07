/*
** EPITECH PROJECT, 2018
** update_grid.c
** File description:
** updating grid infos
*/

#include <string.h>
#include <stdlib.h>
#include "../include/proto.h"

void update_widht(grid_info_t *infos,
	const char *line, const char *new_line, int *i)
{
	unsigned int line_len = strlen(line);

	if (line_len != 2) {
		if (is_number(&line[2]) == -1)
			return;
		infos->width = atoi(&line[2]);
	} else {
		if (is_number(new_line) == -1)
			return;
		infos->width = atoi(new_line);
		(*i)++;
	}
}

void update_height(grid_info_t *infos,
	const char *line, const char *new_line, int *i)
{
	unsigned int line_len = strlen(line);

	if (line_len != 2) {
		if (is_number(&line[2]) == -1)
			return;
		infos->height = atoi(&line[2]);
	} else {
		if (is_number(new_line) == -1)
			return;
		infos->height = atoi(new_line);
		(*i)++;
	}
}

void update_player_one(grid_info_t *infos,
	const char *line, const char *new_line, int *i)
{
	unsigned int line_len = strlen(line);
	unsigned int new_line_len = 0;

	if (line_len >= 5)
		return;
	if (line_len == 4) {
		infos->p1 = line[3];
		return;
	}
	new_line_len = strlen(new_line);
	if (new_line_len == 1 && line_len == 3) {
		infos->p1 = new_line[0];
		(*i)++;
	}
}

void update_player_two(grid_info_t *infos,
	const char *line, const char *new_line, int *i)
{
	unsigned int line_len = strlen(line);
	unsigned int new_line_len = 0;

	if (line_len >= 5)
		return;
	if (line_len == 4) {
		infos->p2 = line[3];
		return;
	}
	new_line_len = strlen(new_line);
	if (new_line_len == 1 && line_len == 3) {
		infos->p2 = new_line[0];
		(*i)++;
	}
}

void update_referee(grid_info_t *infos,
	const char *line, const char *new_line, int *i)
{
	unsigned int line_len = strlen(line);
	unsigned int new_line_len = 0;

	if (line_len >= 4)
		return;
	if (line_len == 3) {
		infos->ref = line[3];
		return;
	}
	new_line_len = strlen(new_line);
	if (new_line_len == 1 && line_len == 2) {
		infos->ref = new_line[0];
		(*i)++;
	}
}
