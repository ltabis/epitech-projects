/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** task02 Day07
*/
#include <stdlib.h>
#include "../include/proto.h"

char *my_strcat_2(char *s1, char *s2)
{
	unsigned int k = 0;
	unsigned int i = my_strlen(s1) + my_strlen(s2);
	char *string = malloc(sizeof(char) * (i + 2));

	if (!string)
		exit(84);
	for (unsigned int j = 0; s1[j] != 0; j++, k++)
		string[k] = s1[j];
	string[k] = '/';
	k++;
	for (unsigned int j = 0; s2[j] != 0; j++, k++)
		string[k] = s2[j];
	string[k] = '\0';
	return (string);
}

char *my_strcat_3(char *s1)
{
	unsigned int k = 0;
	unsigned int i = 0;
	char *string = NULL;

	for (; s1[k] != ' '; k++);
	string = malloc(sizeof(char) * (k + 2));
	if (!string)
		exit(84);
	for (k = 0; s1[k] != ' ' && s1[k] != 0; k++)
		string[k] = s1[k];
	if (i == 1)
		string[k] = '=';
	string[k] = '=';
	string[k + 1] = 0;
	return (string);
}

char *my_strcat_4(char *s1)
{
	unsigned int k = 0;
	char *string = NULL;

	for (; s1[k] != 0; k++);
	string = malloc(sizeof(char) * (k + 1));
	if (!string)
		exit(84);
	for (k = 0; s1[k] != ' ' && s1[k] != 0; k++)
		string[k] = s1[k];
	string[k] = 0;
	return (string);
}
