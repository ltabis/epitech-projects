/*
** EPITECH PROJECT, 2017
** parser_bis.c
** File description:
** 2nd part of the parser
*/
#include <pwd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "include/my.h"
#include "include/proto.h"

unsigned int verify_dash_l_one_folder(unsigned int i, char **av, stock_t *stk)
{
	struct stat file;
	char *concat = concat_params("./", av[i]);

	lstat(concat, &file);
	if (av[i][0] == '-')
		i++;
	if (av[i][0] != '-' && S_ISDIR(file.st_mode)) {
	        disp_files_advanced(av[i], stk);
		i++;
	}
	else if (av[i][0] != '-' && S_ISREG(file.st_mode)) {
		if (stk->options[0] == 48)
			my_printf("%s", av[i]);
		else
			display_dash_l(concat, av[i]);
		i++;
	}
	return (i);
}
