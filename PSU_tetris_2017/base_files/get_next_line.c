/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line function
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tetris.h"

char *get_next_line(int fd, int trigger)
{
	char *line = malloc(sizeof(char) * 1);
	static char *buff = NULL;
	static int rd = 0;

	(trigger == 1 ? free(buff) : 0);
	buff = allocate_memory_at_initialisation(buff, fd, &rd);
	if (!buff || !line || fd < 0 || rd == -2)
		return (NULL);
	line[0] = 0;
	for (int i = 0; buff[i] != '\n' && line && rd > -1; i++)
		for (; i != -1 && buff[i] == 0 && line && rd > -1; i = -1) {
			line = my_strcat(line, buff);
			buff = pass_to_next_buffer(fd, line, &rd);
			if (!buff)
				return (NULL);
		}
	line = my_strcat(line, buff);
	buff = adv_buff(buff);
	for (; rd == -1; rd = -2);
	return (line);
}

char *adv_buff(char *buff)
{
	for (; buff[0] != '\n' && buff[0] != 0; buff++);
	buff++;
	return (buff);
}

char *my_strcat(char *s1, char *s2)
{
	unsigned int g = 0;
	unsigned int k = 0;
	unsigned int i = 0;
	char *string;

	for (; s1[g] != 0; g++);
	i = g;
	for (g = 0; s2[g] != 0 && s2[g] != '\n'; g++);
	i = i + g;
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	for (unsigned int j = 0; s1[j] != 0; j++, k++)
		string[k] = s1[j];
	for (unsigned int j = 0; s2[j] != 0 && s2[j] != '\n'; j++, k++)
		string[k] = s2[j];
	string[i] = '\0';
	return (string);
}

char *allocate_memory_at_initialisation(char *buff, int fd, int *rd)
{
	if (!buff) {
		buff = malloc(sizeof(char) * (READ_SIZE + 1));
		if (!buff)
			return (NULL);
		*rd = read(fd, buff, READ_SIZE);
		if (*rd < 0)
			return (NULL);
		buff[*rd] = 0;
	}
	return (buff);
}

char *pass_to_next_buffer(int fd, char *line, int *rd)
{
	char *buff = NULL;

	if (*rd == -2)
		return (NULL);
	buff = malloc(sizeof(char) * (READ_SIZE + 1));
	*rd = read(fd, buff, READ_SIZE);
	if (*rd <= -1 || !buff)
		return (NULL);
	buff[*rd] = 0;
	if (*rd == 0 && line[0] != 0) {
		*rd = -1;
		return (buff);
	} else if (*rd == 0 && buff[0] == 0)
		return (NULL);
	return (buff);
}
