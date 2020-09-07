/*
** EPITECH PROJECT, 2018
** read_and_display_read_line_1.c
** File description:
** read only the first line of a file
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void read_and_display_read_line_1(int fd)
{
        char buffer[1];
	int read_val = read(fd, buffer, sizeof(buffer));

	while (read_val != 0 && buffer[0] != '\n') {
		putchar(buffer[0]);
		read_val = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
}
