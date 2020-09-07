/*
** EPITECH PROJECT, 2018
** option_1.c
** File description:
** options 1
*/

#include <unistd.h>
#include "../include/base.h"
#include "../include/args.h"

void change_map_size(control_t *controls, char *optarg)
{
	if (!optarg[0]) {
		write(2, "You didn't gave any parameter"\
		"for the --map-size option\n", 55);
		exit(84);
	}
	controls->map_size = check_valid_map_size(optarg);
	if (controls->map_size.x < 1 || controls->map_size.y < 1) {
		write(2, "Invalid map size\n", 17);
		exit(84);
	}
}

void change_key_left(control_t *controls, char *optarg)
{
	if (!optarg[0]) {
		write(2, "You didn't gave any parameter"\
		"for the --key-left option\n", 55);
		exit(84);
	}
	free(controls->key_left2);
	if (my_strlen(optarg) > controls->len_max)
		controls->len_max = my_strlen(optarg);
	controls->key_left2 = my_strcpy(controls->key_left2, optarg);
}

void change_key_right(control_t *controls, char *optarg)
{
	if (!optarg[0]) {
		write(2, "You didn't gave any parameter"\
		"for the --key-right option\n", 56);
		exit(84);
	}
	free(controls->key_right2);
	if (my_strlen(optarg) > controls->len_max)
		controls->len_max = my_strlen(optarg);
	controls->key_right2 = my_strcpy(controls->key_right2, optarg);
}

void change_key_turn(control_t *controls, char *optarg)
{
	if (!optarg[0]) {
		write(2, "You didn't gave any parameter"\
		"for the --key-turn option\n", 55);
		exit(84);
	}
	free(controls->key_turn2);
	if (my_strlen(optarg) > controls->len_max)
		controls->len_max = my_strlen(optarg);
	controls->key_turn2 = my_strcpy(controls->key_turn2, optarg);
}

void change_key_drop(control_t *controls, char *optarg)
{
	if (!optarg[0]) {
		write(2, "You didn't gave any parameter"\
		"for the --key-drop option\n", 55);
		exit(84);
	}
	free(controls->key_drop2);
	if (my_strlen(optarg) > controls->len_max)
		controls->len_max = my_strlen(optarg);
	controls->key_drop2 = my_strcpy(controls->key_drop2, optarg);
}