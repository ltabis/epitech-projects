/*
** EPITECH PROJECT, 2018
** backup.c
** File description:
** make the car drive backwards when hitting a wall
*/

#include "proto.h"
#include "algorithm.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void start_backtracking(void)
{
	char *last_info = NULL;
	float start = 0.0f;
	float end = 0.0f;

	get_time();
	if (!(last_info = get_last_info()))
		return;
	start = get_time_value(last_info);
	printf("CAR_BACKWARDS:0.5\n");
	fflush(stdout);
	usleep(5);
	if (!(last_info = get_last_info()))
		return;
	free(last_info);
	while (end - start <= 1) {
		get_time();
		if (!(last_info = get_last_info()))
			return;
		end = get_time_value(last_info);
	}
}

void get_time(void)
{
	printf("GET_INFO_SIMTIME\n");
	fflush(stdout);
	usleep(5);
}

float get_time_value(char *last_info)
{
	char *unprocessed = NULL;
	float value = 0.0f;
	unsigned int start = 0;
	unsigned int end = 0;

	if (!last_info)
		return (-1.0f);
	for (unsigned int i = 0; last_info[start] && i != 3; start++)
		i += last_info[start] == CST ? 1 : 0;
	start += last_info[start] ? 1 : 0;
	if (!last_info[start])
		return (-1.0f);
	for (end = start; last_info[end] && last_info[end] != 's'; end++);
	unprocessed = strndup(&last_info[start], end - start);
	value = strtof(unprocessed, NULL);
	free(last_info);
	return (value);
}

int stop_car(void)
{
	char *last_info = NULL;
	float start = 0.0f;
	float end = 0.0f;

	if (reset_directions() != CONTINUE)
		return (EXIT_FAILURE);
	get_time();
	if (!(last_info = get_last_info()))
		return (EXIT_FAILURE);
	start = get_time_value(last_info);
	fprintf(stderr, "\x1b[34mStoping the car ...\n\x1b[0m");
	while (end - start <= 2) {
		get_time();
		if (!(last_info = get_last_info()))
			return (EXIT_FAILURE);
		end = get_time_value(last_info);
	}
	return (CONTINUE);
}

int reset_directions(void)
{
	char *last_info = NULL;

	printf("CAR_FORWARD:0.0\n");
	fflush(stdout);
	usleep(5);
	if (!(last_info = get_last_info()))
		return (EXIT_FAILURE);
	free(last_info);
	printf("WHEELS_DIR:0.0\n");
	fflush(stdout);
	usleep(5);
	if (!(last_info = get_last_info()))
		return (EXIT_FAILURE);
	free(last_info);
	return (CONTINUE);
}
