/*
** EPITECH PROJECT, 2018
** debug_mode.c
** File description:
** function that will display debug mode
*/

#include <ncurses.h>
#include "../include/debug.h"
#include "../include/tetris.h"
#include "../include/base.h"

info_t check_tetriminos(char *filepath)
{
	info_t tetr = {0, 0, 0, {0, 0}};
	char *line = NULL;
	int y = -1;
	FILE *strm  = fopen(filepath, "r");
	char trig = 0;

	if (!strm)
		exit(84);
	for (size_t len = 0; getline(&line, &len, strm) != -1; trig = 1, y++) {
		if (trig != 0 && tetr.state != -1)
			tetr = analyse_piece(line, tetr);
		else if (tetr.state != -1)
			analyse_characteristics(line, &tetr);
	}
	tetr.state = (y > tetr.size.y || trig == 0 ? -1 : tetr.state);
	free(line);
	free(filepath);
	fclose(strm);
	return (tetr);
}

void analyse_characteristics(char *line, info_t *info)
{
	int count = 0;
	char *number = NULL;

	count = (line[0] != ' ' && line[0] != '\t' ? 1 : 0);
	for (unsigned int i = 0; line[i + 1] != '\n' && line[i + 1] != 0; i++)
		count += ((line[i] == ' ' && line[i + 1] != '\t' &&
		line[i + 1] != ' ') || (line[i] == '\t' &&
		line[i + 1] != '\t' && line[i + 1] != ' ' ) ? 1 : 0);
	info->state = (count != 3 ? -1 : 0);
	for (unsigned int i = 0, j = 0; line[0] != '\n' && line[0] != 0 &&
	info->state != -1; line++, j++, i = 0) {
		for (; line[i] != ' ' && line[i] != '\n' && line[i] != 0; i++);
		number = my_strndup(line, i);
		for (unsigned int j = 0; j < i && line[j + 1] &&
		line[j + 1] != '\n'; j++, line++);
		count = my_getnbr_no_char(number);
		free(number);
		info->state = (count == -1 || info->state == -1 ? -1 : 0);
		*info = update_infos(*info, count, j);
	}
}

info_t analyse_piece(char *line, info_t tetriminos)
{
	unsigned int i = 0;

	for (i = 0; line[i] != 0 && tetriminos.state != -1; i++) {
		tetriminos.piece_size++;
		if (line[i] != ' ' && line[i] != '\t' &&
		line[i] != '*' && line[i] != '\n')
			tetriminos.state = -1;
	}
	return (tetriminos);
}

info_t update_infos(info_t info, int nbr, unsigned int j)
{
	info.size.x = (j == 0 ? nbr : info.size.x);
	info.size.y = (j == 1 ? nbr : info.size.y);
	info.color = (j == 2 ? nbr : info.color);
	return (info);
}

void check_tetriminos_lenght_and_width(tetrimino_t *te)
{
	int y = 0;
	int x = 0;
	char md = 0;

	for (unsigned int i = 0, j = 0; te->piece[i] && md == 0; i++) {
		for (j = 0; te->piece[i][j] && te->piece[i][j] != ' ' &&
		te->piece[i][j] != '\t' && te->piece[i][j] != '\n'; j++)
		md = (te->piece[i][j] ? te->piece[i][j] : 0);
	}
	for (unsigned int i = 0, j = 0;
	te->info.state != -1 && te->piece[i]; i++) {
		for (j = my_strlen(te->piece[i]); te->piece[i][j] != md; j--);
		te->piece[i][j + 1] = '\n';
		te->piece[i][j + 2] = 0;
	}
	for (int i = 0; te->info.state != -1 && te->piece[y]; y++) {
		for (i = 0; te->piece[y][i] != '\n'; i++);
		x = (i > x ? i : x);
	}
	te->info.state = (y != te->info.size.y ? -1 : te->info.state);
	te->info.state = (x != te->info.size.x ? -1 : te->info.state);
}