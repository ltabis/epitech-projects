/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for task01 Day12
*/
#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int size = 0;
	int argument = 1;
	char buffer[30];

	if (argc == 1) {
		while (1) {
			size = read(argument, buffer, 29);
			write(1, buffer, size);
			while (size != 0) {
				size = read(argument, buffer, 29);
				write(1, buffer, size);
			}
			argument++;
		}
	} else 
		cat(argc, argv);
}
