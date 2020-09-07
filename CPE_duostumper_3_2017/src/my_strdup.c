/*
** EPITECH PROJECT, 2018
** my_strdup;c
** File description:
** duplicate a string
*/

#include "../include/proto.h"
#include <stdlib.h>

char *my_strdup(const char *str)
{
	unsigned int len = my_strlen(str);
	char *copy = malloc(sizeof(char) * (len + 1));

	if (!copy)
		return (NULL);
	for (unsigned int i = 0; str[i]; i++)
		copy[i] = str[i];
	copy[len] = 0;
	return (copy);
}

char *my_strndup(const char *str, unsigned int n)
{
	unsigned int len = my_strlen(str);
	char *copy = malloc(sizeof(char) * (len + 1));

	if (!copy)
		return (NULL);
	for (unsigned int i = 0; str[i] && i < n; i++)
		copy[i] = str[i];
	if (n < len)
		copy[n] = 0;
	else
		copy[len] = 0;
	return (copy);
}
