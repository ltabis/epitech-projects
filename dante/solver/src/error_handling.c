/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** error handling
*/

#include <stdio.h>

int check_paramters(int ac, char **av)
{
	if (ac >= 3) {
		fprintf(stderr, "Wrong arguments give, please try "\
		"with this format : ./solver [method] < maze_file\n");
		return (-1);
	} else if (ac >= 2 && av[1][0] == '-' &&
	av[1][1] == 'h' && av[1][2] == 0) {
		printf("USAGE\n 	-h 	display usage\n"\
		"	wall-follower		"\
		"use the wall follower agorithm\n"\
		"	best-first	use the best-first method"\
		"	A*		use the A star algorithm\n");
		return (1);
	} else if (ac != 2)
		return (-1);
	return (0);
}
