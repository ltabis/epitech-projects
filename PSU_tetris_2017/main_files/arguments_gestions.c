/*
** EPITECH PROJECT, 2018
** arguments_gestions.c
** File description:
** error handling and gestion of arguments
*/
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "../include/option.c"
#include "../include/args.h"
#include "../include/base.h"

control_t handle_arguments(int ac, char **av, char **env)
{
	int op_index = 0;
	control_t controls = assign_default_controls(env);
	int opt = getopt_long(ac, av, "l:r:t:d:q:p:L:wD", op_tab, &op_index);

	check_valid_arguments(ac, av);
	check_other_valid_arguments(ac, av);
	while (opt != -1) {
		if (opt == 63 || opt == 58) {
			write(2, "Bad input : unknown option\n", 27);
			exit(84);
		} else if (op_index == 10) {
			display_help(av[0]);
			exit(0);
		}
		change_defaut_setting(&controls, op_index, opt, optarg);
		op_index = 0;
		opt =
		getopt_long(ac, av, "l:r:t:d:q:p:L:wD", op_tab, &op_index);
	}
	return (controls);
}

control_t assign_default_controls(char **env)
{
	control_t controls = {{10, 20}, NULL, NULL, NULL, NULL,
	NULL, NULL, 1, FALSE, FALSE, 0, 3, 1, 0, 0};

	controls.key_quit2 = my_strcpy(controls.key_quit2, "q");
	controls.key_pause2 = my_strcpy(controls.key_pause2, "(space)");
	set_up_terminal(&controls, env);
	return (controls);
}

sz_t check_valid_map_size(char *opt)
{
	unsigned int i = 0;
	char *arg1 = NULL;
	sz_t size = {0, 0};

	for (; opt[i] != ',' && opt[i] >= '0' && opt[i] <= '9' ; i++);
	if (opt[i] == 0 || opt[i] != ',') {
		write(2, "invalid map size argument\n", 26);
		exit(84);
	}
	arg1 = malloc(sizeof(char) * (i + 1));
	if (!arg1)
		exit(84);
	for (unsigned int j = 0; j <= i; j++)
		arg1[j] = opt[j];
	arg1[i] = 0;
	size.y = my_getnbr_no_char(arg1);
	for (; opt[0] != ','; opt++);
	size.x = my_getnbr_no_char(++opt);
	free(arg1);
	return (size);
}

void change_defaut_setting(control_t *controls, int op_index,
	int opt, char *optarg)
{
	char const small_opt[] = "zlrtdqpLDw";
	void (*choose_option[10])(control_t *, char *) =
		{
			change_map_size, change_key_left,
			change_key_right, change_key_turn,
			change_key_drop, change_key_quit,
			change_key_pause, change_level,
			change_debug, change_next
		};

	if (opt != 0 && op_index == 0)
		for (unsigned int i = 0; i < 10 && op_index == 0; i++)
			(opt == small_opt[i] ? op_index = i : 0);
	if (opt != 0 && op_index == 0  && opt != 110 && opt != 119)
		(*choose_option[opt])(controls, optarg);
	else
		(*choose_option[op_index])(controls, optarg);
}

void display_help(char *av)
{
	my_putstr("Usage:  ");
	my_putstr(av);
	my_putstr(" [options]\n\nOptions:\n --help               Display "\
	"this help\n -L --level={num}     Start Tetris at level"\
	" num (def: 1)\n -l --key-left={K}    Move the tetrimino "\
	"LEFT using the K key (def: left arrow)\n"\
	" -r --key-right={K}   Move the tetrimino "\
	"RIGHT using the K key (def: right arrow)\n"\
	" -t --key-turn={K}    TURN the tetrimino "\
	"clockwise 90d using the K key (def: top arrow)\n"\
	" -d --key-drop={K}    DROP the tetrimino "\
	"using the K key (def: down arrow)\n"\
	" -q --key-quit={K}    QUIT the game using "\
	"the K key (def: `q' key)\n"\
	" -p --key-pause={K}   PAUSE/RESTART the game using "\
	"the K key (def: space bar)\n"\
	" --map-size={row,col} Set the numbers of rows "\
	"and columns of the map (def: 20,10)\n"\
	" -w --without-next    Hide next tetrimino (def: false)"\
	"\n -D --debug           Debug mode (def: false)\n");
}