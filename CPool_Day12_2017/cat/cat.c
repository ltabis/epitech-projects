/*
** EPITECH PROJECT, 2017
** cat.c
** File description:
** task01 Day12
*/
#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int cat(int ac, char **av)
{
	int a;
	char buffer[30];
	char size;
	int argument = 1;

	while (argument != ac) {
		a = open(av[argument], O_RDONLY);
		if (a == -1) {
			write(2, "84 error code : invalid input\n", 30);
			return (0);
		}
		size = read(a, buffer, 29);
		write(1, buffer, size);
		while (size != 0) {
			size = read(a, buffer, 29);
			write(1, buffer, size);
		}
		close(a);
		argument++;
	}
}
