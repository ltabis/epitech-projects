/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** a function that copie a string given in argument
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
	char *dest;

	if (src == NULL)
		return (NULL);
	dest = malloc (sizeof(char) * (my_strlen (src) + 1));
	dest[my_strlen(src)] = '\0';
	my_strcpy (dest, src);
	return (dest);
}
