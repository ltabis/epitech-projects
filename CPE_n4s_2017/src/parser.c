/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** functions for parse return infomrations
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

int set_point(char *line)
{
	int pos = 0;
	int count = 0;

	for (; line[pos] != '\0' && count != 3; pos++) {
		if (line[pos] == ':')
			count++;
	}
	return (pos);
}

int is_closer(float old, float new, float referent)
{
	float dif_n = referent - new;
	float dif_o = referent - old;

	if (dif_n < 0)
		dif_n = dif_n * -1;
	if (dif_o < 0)
		dif_n *= -1;
	if (dif_n < dif_o)
		return (1);
	else
		return (0);
}

void fill_values(char **line, value_t *value)
{
	int i = 0;

	for (; i < NBR_DIRECT_VALUE / 2 - 1; i++) {
		value->left += strtof(line[i], NULL);
	}
	value->left /= (NBR_DIRECT_VALUE / 2 - 1);
	value->middle = (strtof(line[i], NULL) + strtof(line[i + 1], NULL)) / 2;
	i += 2;
	for (; i < NBR_DIRECT_VALUE; i++) {
		value->right += strtof(line[i], NULL);
	}
	value->right /= NBR_DIRECT_VALUE / 2 - 1;
	value->left_max = strtof(line[0], NULL);
	value->right_max = strtof(line[31], NULL);
}

void line_parser(char *line, value_t *values)
{
	char *tmp = line;
	char **dup = NULL;

	tmp += set_point(tmp);
	dup = my_str_to_word_array(tmp);
	fill_values(dup, values);
}
