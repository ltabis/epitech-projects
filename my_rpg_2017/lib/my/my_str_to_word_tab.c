/*
** EPITECH PROJECT, 2018
** my_str_to_wordtab.c
** File description:
** insert a string (as phrase) in a tab
*/

#include <stdlib.h>
#include "my.h"

int char_is_alpha(char c)
{
	if (c != ' ' && c != '\0' && c != '\t')
		return (1);
	else
		return (0);
}

int count_words(char *str)
{
	int i = 0;
	int bool = 1;
	int count = 0;

	for (i = 0; str[i] == ' '; str++);
	if (char_is_alpha(str[i]))
		count++;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && bool == 1) {
			count++;
			bool = 0;
		} else if (char_is_alpha(str[i]))
			bool = 1;
	}
	if (str[i] == '\0' && str[i - 1] == ' ')
		count -= 1;
	return (count);
}

void fill_cell(char **tab, int i, int size, char *str)
{
	tab[i] = malloc (sizeof(char) * size + 1);
	if (tab[i] == NULL)
		my_put_err("invalid malloc for tab line\n");
	tab[i][size] = '\0';
	tab[i] = my_strncpy(tab[i], str, size);
}

int my_word_len(char *str)
{
	int i;

	for (i = 0; str[i] != ' ' && str[i] != '\0'; i++);
	return (i);
}

char **my_str_to_word_tab(char *str)
{
	int size = 0;
	int line = count_words(str);
	char *tmp = str;
	char **tab = NULL;

	tab = malloc(sizeof(char *) * (line + 1));
	if (tab == NULL)
		my_put_err("Invalid malloc for tab\n");
	tab[line] = NULL;
	for (int j = 0; tmp[j] == ' '; tmp++);
	for (int i = 0; i < line; i++) {
		if (tmp[0] == '\0')
			return (tab);
		size = my_word_len(tmp);
		fill_cell(tab, i, size, tmp);
		tmp += size;
		for (int j = 0; tmp[j] == ' '; tmp++);
	}
	return (tab);
}
