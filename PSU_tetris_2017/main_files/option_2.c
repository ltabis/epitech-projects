/*
** EPITECH PROJECT, 2018
** option_2.c
** File description:
** option 2
*/

#include "../include/base.h"
#include "../include/args.h"

void change_key_quit(control_t *controls, char *optarg)
{
	if (!optarg[0]) {
		write(2, "You didn't gave any parameter"\
		"for the --key-quit option\n", 55);
		exit(84);
	}
	free(controls->key_quit2);
	if (my_strlen(optarg) > controls->len_max)
		controls->len_max = my_strlen(optarg);
	controls->key_quit2 = my_strcpy(controls->key_quit2, optarg);
}

void change_key_pause(control_t *controls, char *optarg)
{
	if (!optarg[0]) {
		write(2, "You didn't gave any parameter"\
		"for the --key-pause option\n", 56);
		exit(84);
	}
	free(controls->key_pause2);
	if (my_strlen(optarg) > controls->len_max)
		controls->len_max = my_strlen(optarg);
	controls->key_pause2 = my_strcpy(controls->key_pause2, optarg);
}

void change_level(control_t *controls, char *optarg)
{
	if (!optarg[0]) {
		write(2, "You didn't gave any parameter"\
		"for the --level option\n", 52);
		exit(84);
	}
	if (my_strlen(optarg) > controls->len_max)
		controls->len_max = my_strlen(optarg);
	controls->level = my_getnbr_no_char(optarg);
	if (controls->level == -1)
		exit(84);
}

void change_debug(control_t *controls, __attribute__ ((unused)) char *optarg)
{
	controls->debug = 1;
}

void change_next(control_t *controls, __attribute__ ((unused)) char *optarg)
{
	controls->act_next_tetr = 1;
}