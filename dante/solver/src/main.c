/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file for generator
*/

#include "solver.h"

int main(int ac, char **av)
{
	int error = check_paramters(ac, av);

	if (error == -1)
		return (84);
	else if (error == 1)
		return (0);
	choose_and_compute_algorithm(av);
	return (0);
}
