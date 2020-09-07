/*
** EPITECH PROJECT, 2017
** bistro_matic.c
** File description:
** project bistr-matic
*/
#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

int i = 0;

int evaluate_number(char *str)
{
	int nbr = 0;

	for (; str[i] == ' '; i++);
	for (; str[i] >= '0' && str[i] <= '9'; i++) {
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
	}
	return (nbr);
}

int do_summands(char *str)
{
	int pro1 = do_product(str);
	int pro2 = 0;

	for (; str[i] == ' '; i++);
	while (str[i] == '-') {
		i++;
		pro2 = do_product(str);
		pro1 -= pro2;
	}
	while (str[i] == '+') {
		i++;
		pro2 = do_product(str);
	        pro1 += pro2;
	}
        return (pro1);
}

int do_factors(char *str)
{
	int sum = 0;
	
	for (; str[i] == ' '; i++);
	if (str[i] >= '0' && str[i] <= '9')
		return (evaluate_number(str));
	else if (str[i] == '(') {
		i++;
		sum = do_summands(str);
		i++;
		return (sum);
	}
}

int do_product(char *str)
{
	int fact1 = do_factors(str);
	int fact2 = 0;
	
	for (; str[i] == ' '; i++);
	if (str[i] == '*') {
		i++;
		fact2 = do_factors(str);
		fact1 *= fact2;
	}
	if (str[i] == '/') {
		i++;
		fact2 = do_factors(str);
		fact1 /= fact2;
	}
	if (str[i] == '%') {
		i++;
		fact2 = do_factors(str);
		fact1 %= fact2;
	}
	return (fact1);
}

int eval_expr(char *str)
{
	int result = do_summands(str);
	
	if (str[i] == '\0')
		return (result);
	else {
		write(2, "84 error code : bad input\n", 26);
		return (0);
	}
}
