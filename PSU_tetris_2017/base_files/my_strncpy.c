/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** my_strncpy
*/
#include "base.h"

char *my_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		exit(84);
	dest[n] = 0;
	while (i != n) {
		dest[i] = src[i];
		i++;
	}
	if (n > my_strlen(dest))
		dest[i] = '\0';
	return (dest);
}
