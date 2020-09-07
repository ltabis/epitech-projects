/*
** EPITECH PROJECT, 2017
** parser.c
** File description:
** file that parse all options of my_ls
*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "include/my.h"
#include "include/proto.h"
#include "include/mystruct.h"

stock_t *parse_my_ls(char **av, stock_t *stk)
{
	if (stk->foldNbr == 0 && stk->options[0] == 48)
		disp_files("./", stk);
	else if (stk->foldNbr == 0 && stk->options[0] == 49) {
		display_total("./");
		disp_files("./", stk);
	}
	else
		stk = check_option_R(av, stk);
	return (stk);
}

stock_t *check_option_R(char **av, stock_t *stk)
{
	unsigned int i = 1;

	if (stk->options[1] == 48 && stk->foldNbr > 1)
		for (; av[i] != 0;) {
			i = verify_dash_l(i, av, stk);
			stk->foldNbr--;
		}
	else if (stk->options[1] == 48 && stk->foldNbr == 1) {
		if (av[i][0] != '-')
			verify_dash_l_one_folder(i, av, stk);
		else {
			i++;
			verify_dash_l_one_folder(i, av, stk);
		}
	}
	else if (stk->options[1] == 49)
		conditions_option_R(av, stk);
	return (stk);
}

void check_option_d(char **av, int ac, stock_t *stk)
{
	int i = 1;

	if (ac != 2 && stk->options[2] == 49) {
		for (; i != ac; i++)
			conditions_option_d(av[i], stk);
		if (stk->options[0] == 48)
			my_putchar('\n');
		exit(0);
	}
	else if (ac == 2 && stk->options[2] == 49) {
		if (stk->options[0] == 48)
			my_putstr(".\n");
		else
			display_dash_l("./", "./");
		exit(0);
	}
}

void conditions_option_d(char *av, stock_t *stk)
{
	if (av[0] != '-') {
		if (stk->options[0] == 49)
			display_dash_l(av, av);
		else
			my_printf("%s  ", av);
	}
}

void conditions_option_R(char **av, stock_t *stk)
{

}
