/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** it's count the number of characters in a string
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		i++;
	}
	return (i);
}
