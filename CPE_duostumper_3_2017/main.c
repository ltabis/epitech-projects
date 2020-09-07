/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main fucntion
*/

#include "include/proto.h"
#include <stdlib.h>

int main(int ac, char * const *av)
{
	options_t *options = execute_parsing(ac, av);
	char *input = get_input();

	if (!options || (options->f_arg && options->c_arg) ||
	(options->d_arg != -1 && options->c_arg))
		return (84);
	if (options->f_arg)
		compute_fields(options, input);
	free(options);
	free(input);
	return (0);
}
