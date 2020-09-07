/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main functions
*/

#include "proto.h"

int main(int ac, char * const *av)
{
	grid_info_t *info = NULL;

	if (check_file_and_input_error(ac, av) == -1)
		return (84);
	info = parsing_file(av);
	if (!info || check_map_error(info) == -1)
		return (84);
	if (repeat_iteration(info, atoi(av[2])) == -1)
		return (84);
	free(info);
	return (0);
}
