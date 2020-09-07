/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "../include/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *set_stat(char *stat, int fd)
{
	int file = 0;
	char *buffer = NULL;

	while (check_enter(stat, 0, fd) == 0) {
		buffer = malloc(sizeof(char) * (READ_SIZE + 1));
		if (!buffer)
			return (NULL);
		file = read(fd, buffer, READ_SIZE);
		if (file == 0)
			break;
		buffer[file] = '\0';
		stat = cpy_buffer(stat, buffer, fd);
	}
	return (stat);
}
