/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include "../include/base.h"
#include <stdlib.h>

char *my_strcat(char const *s1, char const *s2)
{
	unsigned int len_s1 = my_strlen((char *)s1);
	unsigned int len_s2 = my_strlen((char *)s2);
	unsigned int index = 0;
	char *str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));

	if (!str)
		return (NULL);
	str[len_s1 + len_s2] = 0;
	for (unsigned int i = 0; s1[i]; i++, index++)
		str[index] = s1[i];
	for (unsigned int i = 0; s2[i]; i++, index++)
		str[index] = s2[i];
	str[index] = 0;
	return (str);
}
