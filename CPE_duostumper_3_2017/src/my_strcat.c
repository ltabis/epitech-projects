/*
** EPITECH PROJECT, 2018
** my_strcat;c
** File description:
** concat two strings
*/

#include "../include/proto.h"
#include <stdlib.h>

char *my_strcat(const char *str1, const char *str2)
{
	unsigned int decal = 0;
	unsigned int len = my_strlen(str1) + my_strlen(str2);
	char *new = malloc(sizeof(char) * (len + 1));

	if (!new)
		return (NULL);
	for (unsigned int i = 0; str1[i]; i++, decal++)
		new[decal] = str1[i];
	for (unsigned int i = 0; str2[i]; i++, decal++)
		new[decal] = str2[i];
	new[len] = 0;
	return (new);
}

char *my_strncat(const char *str1, const char *str2, unsigned int n)
{
	unsigned int decal = 0;
	unsigned int len = my_strlen(str1) + n;
	char *new = malloc(sizeof(char) * (len + 1));

	if (!new)
		return (NULL);
	for (unsigned int i = 0; str1[i]; i++, decal++)
		new[decal] = str1[i];
	for (unsigned int i = 0; str2[i] && i < n; i++, decal++)
		new[decal] = str2[i];
	new[len] = 0;
	return (new);
}
