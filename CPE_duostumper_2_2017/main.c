/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file
*/

#include "include/proto.h"

int main(int ac, char * const *av)
{
	grid_info_t infos = {7, 6, 'X', 'O', '#'};

	parse_input(ac, av, &infos);
	if (checking_parameter(&infos) == 84)
		return (84);
	generate_game_env(infos);
	return (0);
}
