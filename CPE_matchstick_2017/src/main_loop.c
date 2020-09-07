/*
** EPITECH PROJECT, 2018
** main_loop.c
** File description:
** function for the begining of the program
*/
#include <stdlib.h>
#include <unistd.h>
#include "../include/proto.h"

int main_loop(unsigned char *board, unsigned int nb_m, unsigned int ln)
{
	unsigned int match_cnt = ln * ln;
	int error = 0;

	display_board(board, ln);
	write(1, "\nYour turn:\nLine: ", 18);
	error = display_prompt(nb_m, ln, &board);
	nb_m = nb_m;
	while (match_cnt != 0 && error != -2 && error != -3 && error != -4) {
		if (error == 0)
			write(1, "\nYour turn:\nLine: ", 18);
		else if (error == -1)
			write(1, "\nLine: ", 7);
		error = display_prompt(nb_m, ln, &board);
	}
	if (error == -3)
		return (2);
	if (error == -4)
		return (1);
	return (0);
}

int display_prompt(unsigned int nb_m, unsigned int ln, unsigned char **board)
{
	int line;
	int matchs;
	int error = 0;

	line = check_prompt_content(ln, get_next_line(0), 1, nb_m);
	if (line == -1 || line == -2)
		return (line);
	write(1, "Matches: ", 9);
	matchs = check_prompt_content(ln, get_next_line(0), 2, nb_m);
	if (matchs == -1 || matchs == -2)
		return (matchs);
	error = process_gameplay(board, line, matchs, ln);
	if (error != 0)
		return (error);
	if (process_ia_turn(board, nb_m, ln) == -4)
		return (-4);
	return (0);
}

int process_gameplay(unsigned char **board, int line, int matchs,
		unsigned int ln)
{
	if (matchs == 0) {
		write(1, "Error: you have to remove at least one match", 44);
		return (-1);
	}
	if ((unsigned int)matchs > (*board)[line - 1]) {
		write(1, "Error: not enough matches on this line", 38);
		return (-1);
	}
	(*board)[line - 1] -= matchs;
	display_info(line, matchs);
	display_board(*board, ln);
	if (check_if_win_or_lose(*board, ln, 1) == -1)
		return (-3);
	return (0);
}

matches_t retreive_one_match(unsigned char **board, unsigned int ln)
{
	matches_t matches = {0, 1};

	for (unsigned int i = 0; i < ln; i++)
		if ((*board)[i] >= 1) {
			(*board)[i]--;
			matches.line = i;
			return (matches);
		}
	return (matches);
}
