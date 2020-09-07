/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** a function that concatenate two strings
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	char *tmp = dest;
	int size = my_strlen(tmp) + my_strlen(src);
	int i;

	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL) {
		my_put_err("Invalid malloc for result\n");
		return (NULL);
	}
	dest[size] = '\0';
	for (i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	for (int j = 0; tmp[j] != '\0'; j++, i++) {
		dest[i] = tmp[j];
	}
	return (dest);
}
