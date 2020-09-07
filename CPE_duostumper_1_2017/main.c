/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file
*/

#include "include/proto.h"
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int value_len = 0;
	strings_t paterns = {NULL, NULL};
	buff_t buff = {0, 0, 0, NULL};

	if (ac != 4 || my_isnum(av[1]) == -1)
		return (84);
	value_len = my_strlen(av[1]);
	for (unsigned int i = 0; av[2][i] && av[3][i]; i++) {
		av[2][i] = av[2][i] == '@' ? '\n' : av[2][i];
		av[3][i] = av[3][i] == '@' ? '\n' : av[3][i];
	}
	paterns = (strings_t){av[2], av[3]};
	buff = create_buffer(av[1]);
	if (my_getnbr(av[1], value_len, value_len, 0) == 0)
		write(1, "#\n", 2);
	else
		compute_fractal_algorithm(my_getnbr(av[1],
		value_len, value_len, 0),
		paterns, &buff, my_strdup(av[2]));
	free(buff.buffer);
	return (0);
}