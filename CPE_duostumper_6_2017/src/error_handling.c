/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** error handling
*/

#include <stdio.h>
#include "proto.h"

int check_file_and_input_error(int ac, char * const *av)
{
	if (ac != 3) {
		fprintf(stderr, "Wrong set of arguments, retry with"\
		" ./gameoflife filename number_of_iteration\n");
		return (-1);
	}
	if (my_is_number(av[2]) == -1) {
		fprintf(stderr, "The third argument must be a number, "\
		"retry with ./gameoflife filename number_of_iteration\n");
		return (-1);
	}
	return (0);
}

int my_is_number(char *str)
{
	for (unsigned int i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	return (0);
}
