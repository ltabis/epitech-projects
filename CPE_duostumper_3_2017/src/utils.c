/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utility functions
*/

#include "../include/proto.h"
#include <unistd.h>
#include <getopt.h>

int check_invalid_characters(int ret)
{
	char stop = 0;

	if (ret == 'c' || ret == 'f') {
		for (unsigned int i = 0; optarg[i] && stop != -1; i++) {
			stop = (optarg[i] < '0' || optarg[i] > '9') &&
			optarg[i] != '-' && optarg[i] != ',' ? -1 : 0;
		}
		if (stop == -1)
			return (-1);
	}
}

int check_invalid_string_argument(int ret)
{
	for (int i = 0; optarg[i]; i++) {
		if (i + 1 <= my_strlen(optarg) &&
		optarg[i] == ',' && !optarg[i + 1] ||
		optarg[0] == ',')
			return (-1);
		else if ((i - 1 >= 0 && optarg[i - 1] == ',' &&
		optarg[i] == ',') || (i + 1 < my_strlen(optarg) &&
		optarg[i + 1] == ',' && optarg[i] == ','))
			return (-1);
	}
	return (0);
}

void get_parameters(options_t *options, int ret)
{
	if (ret == 'd')
		options->d_arg = optarg[0];
	else if (ret == 'c')
		options->c_arg = my_strdup(optarg);
	else if (ret == 'f')
		options->f_arg = my_strdup(optarg);
}

char *get_input(void)
{
	char *input = NULL;
	char buffer[READ_SIZE];
	int rd = 0;

	if ((rd = read(0, buffer, READ_SIZE - 1)) == -1)
		return (NULL);
	input = my_strndup(buffer, rd);
	for (; (rd = read(0, buffer, READ_SIZE - 1)) > 0;) {
		if (rd == -1)
			return (NULL);
		input = my_strncat(input, buffer, rd);
	}
	return (input);
}
