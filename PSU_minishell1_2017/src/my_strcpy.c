/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01 Day06
*/
#include "../include/proto.h"
#include <stdlib.h>

char *my_strcpy(char *src)
{
	char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	unsigned int i = 0;

	if (!dest)
		exit(84);
	for (; src[i] != 0; i++)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char *my_strcpy_special(char *src)
{
	char *dest = NULL;
	unsigned int i = 0;

	for (; src[i] != 0 && src[i] != ' '; i++);
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		exit(84);
	for (i = 0; src[i] != 0 && src[i] != ' '; i++)
		dest[i] = src[i];
	dest[i] = '=';
	dest[i + 1] = 0;
	return (dest);
}
