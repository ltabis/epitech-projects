/*
** EPITECH PROJECT, 2018
** read_and_display_read_line_n.c
** File description:
** reads the first line but n bytes 
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void read_and_display_read_line_n(int fd, int n)
{
	char buffer[n];
	int read_val = read(fd, buffer, sizeof(buffer));

	for (int i = 0; buffer[i] != '\n' && i != n; i++)
		putchar(buffer[i]);
	close(fd);
}
