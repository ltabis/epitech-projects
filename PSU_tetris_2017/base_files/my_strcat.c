/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include "tetris.h"

char *my_strcat(char *s1, char *s2)
{
	int len_s1 = my_strlen(s1);
	int len_s2 = my_strlen(s2);
	char *str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	int i = 0;
	int j = 0;

	if (!str) {
		write(2, "Error", 5);
		exit(84);
	}
	str[len_s1 + len_s2] = 0;
	for (int i = 0; i < len_s1 + len_s2 + 1; i++)
		str[i] = '0';
	for (; i < len_s1; i++)
		str[i] = s1[i];
	for (; j < len_s2; j++)
		str[i + j] = s2[j];
	return (str);
}
