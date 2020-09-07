/*
** EPITECH PROJECT, 2018
** input_parsing.c
** File description:
** parsing the input from the players
*/

#include <string.h>
#include "../include/proto.h"

void parse_input(int ac, char * const *av, grid_info_t *infos)
{
	unsigned int lenght = 0;
	char *opt[] = {"-w", "-h", "-p1", "-p2", "-a"};
	void (*update_grid_info[5])
	(grid_info_t *, const char *, const char *, int *) =
	{
		update_widht, update_height, update_player_one,
		update_player_two, update_referee
	};

	for (int i = 1; av[i]; i++) {
		for (unsigned int idx = 0, ret = 0;
		idx < NBR_OPT && ret != 1; idx++) {
			lenght = strlen(opt[idx]);
			if (strncmp(av[i], opt[idx], lenght) == 0 && i < ac) {
				(*update_grid_info[idx])
				(infos, av[i], av[i + 1], &i);
				ret = 1;
			}
		}
	}
}

int is_number(const char *str)
{
	for (unsigned int i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	return (0);
}
