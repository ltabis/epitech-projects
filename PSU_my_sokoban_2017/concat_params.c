/*
** EPITECH PROJECT, 2017
** concat_params.c
** File description:
** task02 Day08
*/
#include <stdlib.h>
#include "include/proto.h"
#include "include/my.h"

char *concat_params(char *s1, char *s2)
{
	unsigned int j = 0;
	unsigned int k = 0;
	unsigned int i = my_strlen(s1) + my_strlen(s2);
	char *string = malloc(sizeof(char) * (i + 1));

	if (string == NULL)
		exit(84);
	for (; s1[j] != '\0'; j++, k++)
		string[k] = s1[j];
	for (j = 0; s2[j] != '\0'; j++, k++)
		string[k] = s2[j];
	string[k] = '\0';
	return (string);
}
