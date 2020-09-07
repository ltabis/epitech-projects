/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for the solostumper number 2
*/
#include <unistd.h>
#include "proto.h"

int main(int ac, char **av)
{
	int output = 0;

	if (ac != 2) {
		write(2, "Error:  not enough arguments.\n", 30);
		return (84);
	}
	output = analyse_string(av[1]);
	if (output == 0)
		write(1, "not a palindrome.\n", 18);
	else if (output == 1)
		write(1, "palindrome!\n", 12);
	return (0);
}

int analyse_string(char *str)
{
	unsigned int i = 0;
	int output = 0;

	for (; str[i] != 0; i++);
	for (unsigned int k = i - 1, j = 0; j != i / 2; k--, j++) {
		output = check_conditions(str, k, j);
		if (output == 0)
			return (0);
	}
	return (1);
}

int check_conditions(char *str, unsigned int k, unsigned int j)
{
	if (str[k] == str[j])
		return (1);
	else if (str[k] + 32 == str[j])
		return (1);
	else if (str[k] == str[j] + 32)
		return (1);
	return (0);
}
