/*
** EPITECH PROJECT, 2018
** editor.c
** File description:
** function for editor
*/

#include <unistd.h>
#include "editor.h"
#include "my.h"

int is_in( char *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] == '<' || str[i] == '>')
			return (1);
	}
	return (0);
}

void disp_zero(int nbr)
{
	if (nbr != 0)
		my_putstr("00");
}

char *move(char *str)
{
	for (; *str != ',' && *str != '\0'; str++) {
		if (*str == '\0')
			return (NULL);
	}
	if (*str == '\0')
		return (NULL);
	str++;
	if (*str == '\n' || *str == '\r')
		return (NULL);
	return(str);
}

char *disp_option(char *str)
{
	my_putnbr(my_getnbr(str));
	str = move(str);
	return (str);
}

void editor(char **tab, int num, char **tab2)
{
	int i = 0;
	int nbr = 0;

	for (;is_in(tab[i]) == 1; i++);
	for (int y = 0; is_in(tab[i]) == 0; i++, y++) {
		for (; tab[i] != NULL;) {
			nbr = my_getnbr(tab[i]) - 1;
			my_putnbr(nbr % num);
			disp_zero(nbr);
			my_putstr(",");
			my_putnbr((nbr + 1) /num);
			disp_zero(nbr + 1);
			my_putstr(",");
			tab2[y] = disp_option(tab2[y]);
			my_putstr(" ");
			tab[i] = move(tab[i]);
		}
		my_putchar('\n');
	}
}
