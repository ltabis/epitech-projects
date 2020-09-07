/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for editor
*/

#include <unistd.h>
#include "editor.h"
#include "my.h"

void disp_nbr_line(char **tab)
{
	int i = 0;
	int j = 0;
	int ctr = 0;

	for (;is_in(tab[i]) == 1; i++);
	for (;tab[i][j] != '\n' && tab[i][j] != '\0'; j++)
		if (tab[i][j] == ',')
			ctr++;
	my_putnbr(ctr);
	my_putchar(' ');
	ctr = 0;
	for (;is_in(tab[i]) == 0; i++, ctr++);
	my_putnbr(ctr);
	my_putchar('\n');
}

char **move_tab(char **tab)
{
	int i = 0;

	for (;is_in(tab[i]) == 1; i++);
	for (;is_in(tab[i]) == 0; i++);
	for (;is_in(tab[i]) == 1; i++);
	tab = tab + i;
	return (tab);
}

int main(int argc, char **argv)
{
	char **tab;
	char **tab2;

	if (argc != 3) {
		write(2, "./editor \"map\" number of ligne tilemap\n", 41);
		return (ERROR);
	}
	tab = init_tab(argv[1]);
	tab2 = move_tab(tab);
	disp_nbr_line(tab);
	editor(tab, my_getnbr(argv[2]), tab2);
}
