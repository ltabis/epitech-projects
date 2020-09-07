/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** insert a string (as phrase) in a tab
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

int char_is_alpha(char c)
{
	if (c != CST && c != '\0' && c != '\t')
		return (1);
	else
		return (0);
}

int count_words(char *str)
{
	int i = 0;
	int bool1 = 1;
	int count = 0;

	for (i = 0; str[i] == CST; str++);
	if (char_is_alpha(str[i]) == 1)
		count++;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == CST && bool1 == 1) {
			count++;
			bool1 = 0;
		} else if (char_is_alpha(str[i]))
			bool1 = 1;
	}
	if (str[i] == '\0' && str[i - 1] == CST)
		count -= 1;
	return (count);
}

void fill_cell(char **tab, int i, int size, char *str)
{
	tab[i] = malloc (sizeof(char) * (size + 1));
	if (tab[i] == NULL)
		my_put_err("invalid malloc for tab line\n");
	tab[i][size] = '\0';
	tab[i] = my_strncpy(tab[i], str, size);
}

int my_word_len(char *str)
{
	int i = 0;

	for (i = 0; str[i] != CST && str[i] != '\0'; i++);
	return (i);
}

char **my_str_to_word_array(char *str)
{
	char **tab = NULL;
	int size = 0;
	int line = count_words(str) - 1;

	tab = malloc(sizeof(char *) * (line + 1));
	if (tab == NULL)
		my_put_err("Invalid malloc for tab\n");
	tab[line] = NULL;
	for (int j = 0; str[j] == CST; str++);
	for (int i = 0; i < line; i++) {
		size = my_word_len(str);
		fill_cell(tab, i, size, str);
		str += size;
		for (int j = 0; str[j] == CST; str++);
		if (!tab[i])
			return (tab);
	}
	return (tab);
}
