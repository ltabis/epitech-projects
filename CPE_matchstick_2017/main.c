/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file
*/
#include "include/proto.h"

int main(int ac, char **av)
{
	int error = 0;

	if (ac != 3)
		return (84);
	if (check_params(av[1], av[2]) == -1)
		return (84);
	error = create_game_environnement(av[1], av[2]);
	if (error == -1)
		return (84);
	return (error);
}
