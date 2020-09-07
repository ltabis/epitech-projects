/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** parsing fucntions
*/

#include "../include/proto.h"
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

options_t *execute_parsing(int ac, char * const *av)
{
	options_t *options = create_options_struct();
	int ret = 0;
	int stop = 0;
	int optindex = 0;
	struct option longopts[] = {
	{"characters", 1, 0, 'c'},
	{"delimiter", 1, 0, 'd'},
	{"fields", 1, 0, 'f'},
	{0, 0, 0, 0}};

	if (!options)
		return (NULL);
	while ((ret = getopt_long(ac, av, "c:d:f:", longopts, &optindex))
	!= -1 && stop != -1) {
		stop = check_params(ret);
		get_parameters(options, ret);
	}
	return (stop == -1 ? NULL : options);
}

int check_params(int ret)
{
	unsigned int range = 0;

	if (ret == 'd' && my_strlen(optarg) > 1)
		return (-1);
	for (unsigned int i = 0; optarg[i] && range < 2; i++) {
		range = optarg[i] == ',' ? 0 : range;
		range += optarg[i] == '-' ? 1 : 0;
	}
	if (check_invalid_characters(ret) == -1 ||
	check_invalid_string_argument(ret) == -1)
		return (-1);
	return (range >= 2 ? -1 : 0);
}

options_t *create_options_struct(void)
{
	options_t *options = malloc(sizeof(options_t));

	if (!options)
		return (NULL);
	options->c_arg = NULL;
	options->f_arg = NULL;
	options->d_arg = -1;
	return (options);
}
