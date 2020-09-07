/*
** EPITECH PROJECT, 2018
** my swap str
** File description:
** swap 2 str
*/
#include "tetris.h"

char *my_realloc_and_fill_str(char *str, int size)
{
	char *s2 = malloc(sizeof(char) * (size + 1));

	if (s2 == NULL)
		return (NULL);
	s2[size] = 0;
	for (int i = 0; str[i]; i++)
		s2[i] = str[i];
	return (s2);
}

int my_swap_str(char **s1, char **s2)
{
	int len1 = my_strlen(*s1);
	int len2 = my_strlen(*s2);
	char *s3 = NULL;

	s3 = my_strcpy(s3, *s1);
	if (s3 == NULL)
		return (84);
	if (len1 != len2) {
		if ((*s1 = my_realloc_and_fill_str(*s2, len2)) == NULL ||
		(!(*s2 = my_realloc_and_fill_str(s3, my_strlen(s3)))))
			return (84);
	} else {
		for (int i = 0; (*s2)[i]; i++) {
			(*s1)[i] = (*s2)[i];
		}
		for (int i = 0; s3[i]; i++)
			(*s2)[i] = s3[i];
	}
	free(s3);
	return (0);
}