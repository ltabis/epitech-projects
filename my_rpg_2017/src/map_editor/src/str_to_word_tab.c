/*
** EPITECH PROJECT, 2018
** my_str_to_word_tab.c
** File description:
** transform a sentence in an array
*/

#include <unistd.h>
#include <stdlib.h>

int count_str(char *str, char a)
{
	int ctr = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == a)
			ctr++;
	}
	return (ctr + 1);
}

char *count_char(char *str, int *d, char a)
{
	for (;*str != a && *str != '\0';str++, (*d)++);
	if (*str == '\0')
		return (NULL);
	str++;
	return (str);
}

char *fill_tab(char *str, int d)
{
	char *result = malloc(sizeof(char) * (d + 1));
	int i = 0;
	for (i = 0; i != d; i++)
		result[i] = str[i];
	result[i] = '\0';
	return (result);
}

char **str_to_word_tab(char *str, char a)
{
	char **tab = malloc(sizeof(char *) * (count_str(str, a)));
	char *str_cp = str;
	int d = 0;

	tab[count_str(str, a) - 1] = NULL;
	for (int i = 0; str != NULL; i++) {
		str = count_char(str, &d, a);
		if (d != 0) {
			tab[i] = fill_tab(str_cp, d);
			str_cp = str_cp + d + 1;
			d = 0;
		}
	}
	return (tab);
}
