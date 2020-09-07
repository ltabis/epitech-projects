/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** error handling wih message get from VREP
*/

#include "../include/algorithm.h"
#include "../include/proto.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int check_message_from_vrep(char *line)
{
	int ret = -2;
	char *nbr_chr = NULL;

	if (!line)
		return (EXIT_FAIL);
	if (line[1] == ':') {
		nbr_chr = strndup(line, 1);
		ret = atoi(nbr_chr);
		free(nbr_chr);
	} else if (line[2] == ':') {
		nbr_chr = strndup(line, 2);
		ret = atoi(nbr_chr);
		free(nbr_chr);
	} else {
		fprintf(stderr, "bad formated return message\n");
		return (EXIT_FAIL);
	}
	return (ret < -1 || ret > 25 ? EXIT_FAIL : parse_error(ret));
}

int parse_error(int ret)
{
	if (ret == 0)
		fprintf(stderr, "Simulation has not been launched\n");
	else if (ret == 22)
		fprintf(stderr, "Scene must contain at least 3 checkpoints\n");
	return (ret == 1 ? 0 : ret);
}
