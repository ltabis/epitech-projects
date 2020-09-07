/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** error handling
*/

#include <stdio.h>
#include "generator.h"

int check_paramters(int ac, char **av)
{
	if (ac < 3 || ac > 5) {
		fprintf(stderr, "Wrong arguments give, please try "\
		"with this format : ./generator x y [perfect]\n");
		return (-1);
	} else if (is_number(av[1]) == -1) {
		fprintf(stderr, "The second parameter must be an integer\n");
		return (-1);
	} else if (is_number(av[2]) == -1) {
		fprintf(stderr, "The third parameter must be an integer\n");
		return (-1);
	}
	return (is_negative_number(av[1], av[2]));
}

int is_number(char *str)
{
	for (unsigned int i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	return (0);
}

int is_negative_number(char *str1, char *str2)
{
	int nbr1 = atoi(str1);
	int nbr2 = atoi(str2);

	return (nbr1 <= 0 || nbr2 <= 0 ? -1 : 0);
}
