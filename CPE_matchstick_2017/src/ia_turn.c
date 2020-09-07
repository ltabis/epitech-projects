/*
** EPITECH PROJECT, 2018
** ia_turn.c
** File description:
** ia turn
*/
#include "../include/proto.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int process_ia_turn(unsigned char **board, unsigned int nb_m, unsigned int ln)
{
	matches_t matches_removed = {0, 0};

	matches_removed = compute_algorithme(board, nb_m, ln, matches_removed);
	if (matches_removed.line == -1)
		return (-1);
	write(1, "\nAI's turn...\nAI removed ", 25);
	my_put_nbr(matches_removed.matches);
	write(1, " match(es) from line ", 21);
	my_put_nbr(matches_removed.line + 1);
	my_putchar('\n');
	display_board(*board, ln);
	if (check_if_win_or_lose(*board, ln, 2) == -1)
		return (-4);
	return (0);
}

int check_if_win_or_lose(unsigned char *board, unsigned int ln, int player)
{
	unsigned int count = 0;

	for (unsigned int i = 0; i < ln; i++)
		if (board[i] == 0)
			count++;
	if (count == ln && player == 1) {
		write(1, "You lost, too bad...\n", 21);
		return (-1);
	} else if (count == ln && player == 2) {
		write(1,
		"I lost... snif... but I'll get you next time!!\n", 47);
		return (-1);
	}
	return (0);
}

matches_t compute_algorithme(unsigned char **board,
	unsigned int nb_m, unsigned int ln, matches_t mtch)
{
	int nim_sum = 0;
	int xor = 0;
	int one_match_remaining = count_matchs_remaining(board, ln);

	for (unsigned int i = 0; i < ln - 1; i++, xor ^= (*board)[i]);
	for (unsigned int i = 0; i < ln && one_match_remaining != -1; i++) {
		nim_sum = xor ^ (*board)[i];
		mtch.matches = (*board)[i] - nim_sum;
		mtch.matches = (mtch.matches > nb_m ? nb_m : mtch.matches);
		if (nim_sum < (*board)[i]) {
			mtch.line = i;
			(*board)[i] -= mtch.matches;
			return (mtch);
		}
	}
	if (one_match_remaining == -1)
		mtch = trap_player(board, ln, nb_m);
	else
		mtch = retreive_one_match(board, ln);
	return (mtch);
}

int count_matchs_remaining(unsigned char **board, unsigned int ln)
{
	int lim = 0;
	int one_match_remaining = 0;

	for (unsigned int i = 0; i < ln; i++)
		if ((*board)[i] != 0)
			lim++;
	for (unsigned int i = 0; i < ln; i++)
		if ((*board)[i] == 1)
			one_match_remaining++;
	if (one_match_remaining == lim - 1)
		return (-1);
	return (one_match_remaining);
}

matches_t trap_player(unsigned char **board, unsigned int ln, unsigned int nb_m)
{
	matches_t matches = {0, 0};
	int lim = 0;
	int one_match_remaining = 0;
	unsigned int decal = 0;
	int retreive = 0;

	for (unsigned int i = 0; i < ln; i++)
		if ((*board)[i] == 1)
			one_match_remaining++;
	if (one_match_remaining % 2 == 0)
		retreive = 1;
	for (decal = 0; (*board)[decal] <= 1; decal++);
	matches.matches = (*board)[decal] - retreive;
	matches.matches = (matches.matches > nb_m ? nb_m : matches.matches);
	(*board)[decal] -= matches.matches;
	matches.line = decal;
	return (matches);
}
