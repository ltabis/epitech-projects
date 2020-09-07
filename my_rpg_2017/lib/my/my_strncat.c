/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** a function that concatenats two strings at the n character.
*/

#include <stdlib.h>

char *my_strncat(char *dest, char const *src, int n)
{
	int i = 0;
	int j = 0;

	if (src == NULL || n < 0)
		return (NULL);
	for (; dest[i] != '\0'; i++);
	for (; j != n; i++, j++) {
		dest[i] = src [j];
	}
	dest[i] = '\0';
	return (dest);
}
