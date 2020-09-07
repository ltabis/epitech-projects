/*
** EPITECH PROJECT, 2017
** EvalXprB.c
** File description:
** boot strap for evalXpr
*/
#include "include/my.h"
#include <stdlib.h>

int number(char **str)
{
	int integer = 0;
	int i;

	for (i = 0; str[1][i] != '\0'; i++) {
		if (str[1][i] < '0' || str[1][i] > '9') {
			my_put_nbr(integer);
			return (84);
		}
		integer = (integer * 10) + (str[1][i] - 48);
	}
	my_put_nbr(integer);
}

//int number(char **str);
