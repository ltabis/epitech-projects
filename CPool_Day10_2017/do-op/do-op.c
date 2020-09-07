/*
** EPITECH PROJECT, 2017
** do-op.c
** File description:
** task02 Day10
*/
#include <stdlib.h>
#include "my.h"

int calculate_basics(char *operator, int variable_a, int variable_b)
{
	if (operator[0] == '-')
		return (my_put_nbr(variable_a - variable_b));
	if (operator[0] == '+')
		return (my_put_nbr(variable_a + variable_b));
	if (operator[0] == '*')
		return (my_put_nbr(variable_a * variable_b));
}

int my_do_op(int ar, char **av)
{
	int variable_a = my_getnbr(av[1]);
	int variable_b = my_getnbr(av[3]);
	char *operator = av[2];
	int result = calculate_basics(operator, variable_a, variable_b);; 

	if (operator[0] == '/')
		if (variable_a == 0 || variable_b == 0)
			write(2, "Stop : division by zero", 23);
		else
			my_put_nbr(result = variable_a / variable_b);
	if (operator[0] == '%')
		if (variable_a == 0 || variable_b == 0)
			write(2, "Stop : modulo by zero", 23);
		else
			my_put_nbr(result = variable_a % variable_b);
	if (operator[0] != '-' && operator[0] != '+' && operator[0] != '*' && operator[0] != '/' && operator[0] != '%') {
		my_put_nbr(0);
		return (0);
	} else
		return (84);
}
