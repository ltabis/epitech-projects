/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** duplicate a string
*/

#include "../include/proto.h"
#include <stdlib.h>

char *my_strdup(const char *str)
{
	unsigned int len_str = my_strlen(str);
	char *cpy = malloc(sizeof(char) * (len_str + 1));

	if (!cpy)
		return (NULL);
	for (unsigned int i = 0; i < len_str; i++)
		cpy[i] = str[i];
	cpy[len_str] = 0;
	return (cpy);
}