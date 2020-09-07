/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** funcitons that will display the map and the instructions
*/
#include <unistd.h>
#include "../include/proto.h"

void display_board(unsigned char *board, unsigned int ln)
{
	for (unsigned int i = 1; i < ln * 2 + 1; i++)
		my_putchar('*');
	write(1, "*\n*", 3);
	display_matches(board, ln);
	for (unsigned int i = 1; i < ln * 2 + 1; i++)
		my_putchar('*');
	my_putchar('\n');
}

void display_matches(unsigned char *board, unsigned int ln)
{
	unsigned int j = 0;
	unsigned int len = ln * 2;

	for (unsigned int i = 0, decal = ln - 1; i < ln; i++, decal--) {
		for (j = 0; j < decal; j++)
			my_putchar(' ');
		for (int k = 0; k < board[i]; k++, j++)
			my_putchar('|');
		for (; j < len - 1; j++)
			my_putchar(' ');
		write(1, "*\n*", 3);
	}
}

void display_info(unsigned int line, unsigned int matchs)
{
	write(1, "Player removed ", 15);
	my_put_nbr(matchs);
	write(1, " match(es) from line ", 21);
	my_put_nbr(line);
	my_putchar('\n');
}
