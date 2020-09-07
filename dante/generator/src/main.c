/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file for generator
*/

#include "generator.h"

int main(int ac, char **av)
{
	char *maze = NULL;

	if (check_paramters(ac, av) == -1)
		return (84);
	if ((maze = generate_maze(atoi(av[1]), atoi(av[2]), av[3])) == NULL)
		return (84);
	display_maze(maze);
	free(maze);
	return (0);
}
