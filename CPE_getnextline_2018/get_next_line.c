/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line function
*/
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line = malloc(sizeof(char) * READ_SIZE + 1);
	static int last_buff = 0;
	static char buffer[READ_SIZE];
	int read_val;
	int i = 0;
	int j = 0;

	if (fd == -1 || !line)
		return (NULL);
	if (last_buff < READ_SIZE)
		for (j = last_buff; buffer[j] != '\n' &&
			j < READ_SIZE; i++, j++)
			line[i] = buffer[last_buff];
	read_val = read(fd, buffer, sizeof(buffer));
	if (j >= READ_SIZE)
		last_buff = 0;
	for (i = 0; buffer[i] != '\n' && i < READ_SIZE; i++, last_buff++)
		line[i] = buffer[i];
	line[i] = '\0';
	if (read_val == 0)
		return (NULL);
	return (line);
}
