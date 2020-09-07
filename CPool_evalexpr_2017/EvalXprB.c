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
			return (integer);
		}
		integer = (integer * 10) + (str[1][i] - 48);
	}
	my_put_nbr(integer);
	return (integer);
}

int summands(char **str)
{
	int sum = 0;
	int summand1;
	int summand2;
	int j = 0;

	summand1 = number(str);
	my_revstr(str[1]);
	summand2 = number(str);
	my_revstr(str[1]);
	for (j = 0; str[1][j] == '\0'; j++) {
		if (str[1][j] == '+' )
			sum = summand1 + summand2;
		if (str[1][j] == '-')
			sum = summand1 - summand2;
	}
	my_putchar('\n');
	my_put_nbr(sum);
	return (sum);
}
