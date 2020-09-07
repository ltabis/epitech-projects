/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for n4s
*/

#include "../include/algorithm.h"
#include "../include/proto.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int ret = 0;

	printf("START_SIMULATION\n");
	fflush(stdout);
	usleep(5);
	if ((check_message_from_vrep(get_last_info())) == EXIT_FAIL) {
		fprintf(stderr, "Application couldn't load\n");
		return (84);
	}
	printf("CAR_FORWARD:1.0\n");
	fflush(stdout);
	usleep(5);
	if ((ret = execute_main_algoritm()) == EXIT_FAIL)
		return (84);
	else if (ret == STOP)
		if (stop_car() == EXIT_FAIL)
			return (84);
	fprintf(stderr, "\x1b[34mEnd of race\x1b[0m\n");
	printf("STOP_SIMULATION\n");
	return (EXIT_SUCCESS);
}

char *get_last_info(void)
{
	char *line = NULL;
	size_t len = 0;
	int ret = 0;

	ret = getline(&line, &len, stdin);
	return (ret != -1 ? line : NULL);
}
