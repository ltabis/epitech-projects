/*
** EPITECH PROJECT, 2018
** read_next_char.c
** File description:
** first exercices od the getnextline's bootstrap
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char read_next_char(int fd)
{
	char buffer[1];
	int read_val = read(fd, buffer, sizeof(buffer));

	close(fd);
	return (buffer[0]);
}
