/*
** EPITECH PROJECT, 2018
** get_next_line back to the future
** File description:
** bttf
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

char *set_return(char *stat)
{
	int i = 0;
	char *new_str = NULL;

	for (; stat[i] != '\0' && stat[i] != '\n'; i++);
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	new_str[i] = '\0';
	for (i = 0; stat[i] != '\n' && stat[i] != '\0'; i++)
		new_str[i] = stat[i];
	return (new_str);
}

char *cut_enter(char *stat)
{
	int i = 0;
	char *new_str = NULL;
	int g = 0;

	for (; stat[i] != '\n' && stat[i] != '\0'; i++);
	if (stat[i] == '\0') {
		free(stat);
		return (new_str);
	}
	i++;
	for (; stat[i] != '\0'; i++, g++);
	new_str = malloc(sizeof(char) * (g + 1));
	new_str[g] = '\0';
	for (i = 0; stat[i] != '\n'; i++);
	i++;
	for (g = 0; stat[i] != '\0'; i++, g++)
		new_str[g] = stat[i];
	free(stat);
	return (new_str);
}

int check_enter(char *stat, int choice, int fd)
{
	int i = 0;

	if (choice == 1) {
		if (stat == NULL)
			return (0);
		for (; stat[i] != '\0'; i++);
		return (i);
	}
	if (fd < 0)
		return (1);
	if (stat == NULL)
		return (0);
	for (; stat[i] != '\0'; i++) {
		if (stat[i] == '\n')
			return (1);
	}
	return (0);
}

char *cpy_buffer(char *stat, char *buffer, int fd)
{
	char *new_str = NULL;
	int g = 0;
	int len_stat = check_enter(stat, 1, fd);
	int len_buffer = check_enter(buffer, 1, fd);

	new_str = malloc(sizeof(char) * (len_stat + len_buffer + 1));
	if (!new_str)
		return (NULL);
	new_str[len_stat + len_buffer] = '\0';
	for (int i = 0; i < len_stat; i++, g++)
		new_str[g] = stat[i];
	if (stat != NULL)
		free(stat);
	for (int i = 0; i < len_buffer; i++, g++)
		new_str[g] = buffer[i];
	free (buffer);
	return (new_str);
}

char *get_next_line(int fd)
{
	char *str = NULL;
	static char *stat = NULL;

	if (stat != NULL && my_strlen(stat) == 0) {
		free(stat);
		stat = NULL;
	}
	stat = set_stat(stat, fd);
	if (stat == NULL)
		return (NULL);
	str = set_return(stat);
	stat = cut_enter(stat);
	return (str);
}
