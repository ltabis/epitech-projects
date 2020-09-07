/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** error handling for user input
*/

#include "proto.h"

int check_parameters(int ac, char * const *av)
{
	if (ac != 4 || (strcmp(av[1], "-f") != 0 &&
	strcmp(av[1], "-s") != 0)) {
		fprintf(stderr, "Wrong set of arguments, retry with"\
			": ./cesar -f/-s file/'string' key\n");
		return (-1);
	}
	if (my_isnum(av[3]) == -1) {
		fprintf(stderr, "The key must be a number, retry with"\
			": ./cesar -f/-s file/'string' key\n");
		return (-1);
	}
	return (0);
}

int my_isnum(const char *key)
{
	for (unsigned int i = 0; key[i]; i++) {
		i = i == 0 && key[0] == '-' ? 1 : i;
		if (key[i] < '0' || key[i] > '9')
			return (-1);
	}
	return (0);
}
