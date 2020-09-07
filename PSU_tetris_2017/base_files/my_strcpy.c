/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** my_strcpy
*/
#include "../include/tetris.h"
#include <stdlib.h>
#include <unistd.h>

char *my_strcpy(char *dest, char *src)
{
	if (src == (char *) - 1) {
		write(2, "Error : missing termcap on your terminal\n", 41);
		exit(84);
	}
	dest = malloc(sizeof(char) * my_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	dest[my_strlen(src)] = 0;
	for (int i = 0; src[i]; i++) {
		dest[i] = src[i];
	}
	return (dest);
}
