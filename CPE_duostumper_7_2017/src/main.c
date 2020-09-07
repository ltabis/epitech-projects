/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/

#include "proto.h"

int main(int ac, char * const *av)
{
	char *filepath = NULL;
	int key = 0;

	if (check_parameters(ac, av) == -1 || !(filepath = strdup(av[2])))
		return (84);
	key = atoi(av[3]);
	if (strcmp(av[1], "-s") == 0) {
		if (write_ciphered_string_into_file(filepath, key) == -1)
			return (84);
	} else if (strcmp(av[1], "-f") == 0)
		if (parse_file(filepath, key) == -1)
			return (84);
	return (0);
}
