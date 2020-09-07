/*
** EPITECH PROJECT, 2018
** compute_algorithm.c
** File description:
** main algorithm functions
*/

#include "../include/proto.h"
#include "../include/algorithm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int execute_main_algoritm(void)
{
	value_t direct = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	char *last_info = NULL;
	int ret = 0;

	if (!(last_info = get_last_info()))
		return (EXIT_FAIL);
	check_end_of_race(last_info, 1);
	for (free(last_info); ret == 0;) {
		printf("GET_INFO_LIDAR\n");
		fflush(stdout);
		usleep(5);
		if (!(last_info = get_last_info()))
			return (EXIT_FAIL);
		if ((ret = check_end_of_race(last_info, 1)) != CONTINUE)
			return (ret);
		line_parser(last_info, &direct);
		ret = select_way_to_go(&direct);
		free(last_info);
	}
	return (ret == 0 ? EXIT_SUCCESS : ret);
}

int check_end_of_race(char *lst_infos, int type)
{
	unsigned int types[4] = {3, 35, 4, 3};
	unsigned int i = 0;
	char *add_info = NULL;

	for (unsigned int separ = 0; lst_infos &&
	lst_infos[i] && separ < types[type]; i++)
		separ += lst_infos[i] == ':' ? 1 : 0;
	if (!lst_infos || !lst_infos[i])
		return (EXIT_FAIL);
	add_info = &lst_infos[i];
	if (strcmp(add_info, "No further info\n") != 0)
		fprintf(stderr, "\x1B[32m%s\x1B[0m", add_info);
	if (strncmp(add_info, "Track Cleared", 13) == 0)
		return (STOP);
	return (CONTINUE);
}

int select_way_to_go(value_t *direction)
{
	float forward = direction->middle / (MAX_FORWARD / 1.5);
	float turn_angle = (direction->left > direction->right) ?
	1 / direction->right : 1 / -direction->left;
	int ret = 0;

	if (turn_angle < -0.01)
		turn_angle = -0.01;
	else if (turn_angle > 0.01)
		turn_angle = 0.01;
	turn_angle = search_turn_angle_exeption(direction, turn_angle);
	if (direction->middle >= MAX_FORWARD / 2)
		turn_angle = 0;
	printf("WHEELS_DIR:%f\n", turn_angle * 90.0f);
	fflush(stdout);
	usleep(5);
	if ((ret = car_speed(forward)) != CONTINUE)
		return (ret);
	return (CONTINUE);
}

int car_speed(float forward)
{
	char *last_info = NULL;
	int ret = 0;

	if (!(last_info = get_last_info()))
		return (EXIT_FAIL);
	if ((ret = check_end_of_race(last_info, 0)) != CONTINUE)
		return (ret);
	free(last_info);
	printf("CAR_FORWARD:%f\n", forward);
	fflush(stdout);
	usleep(5);
	last_info = get_last_info();
	if ((ret = check_end_of_race(last_info, 0)) != CONTINUE)
		return (ret);
	free(last_info);
	return (CONTINUE);
}

float search_turn_angle_exeption(value_t *values, float turn_angle)
{
	char *ret = NULL;

	if (values->middle <= 100 && (values->right_max <= 100 ||
	values->left_max <= 100)) {
		if (values->left_max > values->right_max)
			printf("WHEELS_DIR:-0.2\n");
		else
			printf("WHEELS_DIR:0.2\n");
		fflush(stdout);
		usleep(5);
		if (!(ret = get_last_info()))
			return (0.0f);
		free(ret);
		start_backtracking();
	}
	return (turn_angle);
}
