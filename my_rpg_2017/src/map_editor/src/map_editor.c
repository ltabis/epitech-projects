/*
** EPITECH PROJECT, 2018
** map_editor.c
** File description:
** map editor
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"
#include "my.h"

char *my_concat(char *s1, char *s2)
{
	char *result = NULL;
	result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	my_strcpy(result, s1);
	my_strcat(result, s2);
	return (result);
}

char **init_tab(char *path)
{
	FILE *stream = NULL;
	char *str = NULL;
	char *result = malloc(sizeof(char));
	size_t ctr = 0;

	result[0] = '\0';
	stream = fopen(path, "r");
	if (stream == NULL) {
		write(2, "error getline\n", 13);
		return (NULL);
	}
	while (getline(&str, &ctr, stream) != -1) {
		result = my_concat(result, str);
		free(str);
		str = NULL;
	}
	fclose(stream);
	return (str_to_word_tab(result, '\n'));
}
