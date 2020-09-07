/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** task01 Day08
*/
#include <stdlib.h>

char *my_strdup(char const *src)
{
	char *string;
	int i = 0;
	int j = 0;
	
	while (src[i] != '\0')
		i++;
	string = malloc(sizeof(char) * i);
	i = 0;
	while (src[i] != '\0') {
		string[j] = src[i];
		j++;
		i++;
	}
	string[j] = '\0';
	return (string);
}
