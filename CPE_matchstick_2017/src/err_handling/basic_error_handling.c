/*
** EPITECH PROJECT, 2018
** basic_error_handling.c
** File description:
** all the basic functions that will serve for error handling
*/
#include <unistd.h>
#include <stdlib.h>
#include "../../include/proto.h"

int check_params(char *arg_1, char *arg_2)
{
	for (unsigned int i = 0; arg_1[i] != 0; i++)
		if (arg_1[i] < '0' || arg_1[i] > '9')
			return (-1);
	for (unsigned int i = 0; arg_2[i] != 0; i++)
		if (arg_2[i] < '0' || arg_2[i] > '9')
			return (-1);
	return (0);
}

int check_prompt_content(unsigned int ln, char *prompt, int type,
			unsigned int nb_m)
{
	int result;

	if (!prompt)
		return (-2);
	result = my_getnbr(prompt);
	if (result == -1)
		write(1, "Error: invalid input (positive number expected)", 47);
	else if ((result < 1 || (unsigned int)result > ln) && type == 1) {
		write(1, "Error: this line is out of range", 32);
		result = -1;
	} else if (((unsigned int)result > nb_m || result < 1) &&
		type == 2 && result != 0) {
		write(1, "Error: you cannot remove more than ", 35);
		my_put_nbr(nb_m);
		write(1, " matches per turn", 17);
		result = -1;
	}
	free(prompt);
	return (result);
}
