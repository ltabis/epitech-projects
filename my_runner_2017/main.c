/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** file where the main function is
*/
#include <stdlib.h>
#include "include/proto.h"

int main(int ac, char **av, char **envp)
{
	int error = 0;
	int y = find_y(av[1]);

	error = check_usage_and_params(av[1], ac, envp);
	if (error == 84)
		return (84);
	else if (error == 0)
		return (0);
	error = verify_file_stat(av[1], error);
	if (error == 84)
		return (84);
	error =
	launch_normal_mod(load_map_from_file(av[1]), y, av[1]);
	if (error == 84)
		return (84);
	return (0);
}
