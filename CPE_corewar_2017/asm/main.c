/*
** EPITECH PROJECT, 2018
** main
** File description:
** main function
*/

#include "../include/asm.h"

int main(int ac, char **av)
{
	if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
		print_usage();
		return (0);
	}
	if (check_my_arg(ac, av) == 1)
		return (84);
	if (!my_asm(av[1]))
		return (84);
	return (0);
}
