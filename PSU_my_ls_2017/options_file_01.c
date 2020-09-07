/*
** EPITECH PROJECT, 2017
** options_file_01.c
** File description:
** file with options for the my_ls program
*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "include/my.h"
#include "include/proto.h"

void disp_files(char *av, stock_t *stk)
{
	struct dirent *stream;
	DIR *dir;
	char *concat;

	if (av == NULL)
		dir = opendir("./");
	else
		dir = opendir(av);
	stream = readdir(dir);
	for (; stream != NULL; stream = readdir(dir)) {
		concat = concat_params(av, stream->d_name);
		if (stream->d_name[0] != '.' &&
		stk->options[0] == 49) {
			display_dash_l(concat, stream->d_name);
		} else if (stream->d_name[0] != '.' &&
			stk->options[0] == 48)
			my_printf("%s ", stream->d_name);
	}
	if (stk->options[0] != 49)
		my_putchar('\n');
}

void disp_files_advanced(char *av, stock_t *stk)
{
	struct dirent *stream;
	DIR *dir;
	char *concat = malloc(512);

	dir = opendir(av);
	stream = readdir(dir);
	if (stk->options[0] == 49)
		display_total(av);
	while (stream != NULL) {
		concat = concat_params(av, "/");
		if (stream->d_name[0] != '.' &&
		stk->options[0] == 49) {
			display_dash_l(concat, stream->d_name);
		} else if (stream->d_name[0] != '.' &&
			stk->options[0] == 48)
			my_printf("%s ", stream->d_name);
		stream = readdir(dir);
	}
	display_spaces_files(stk);
}

void display_total(char *av)
{
	struct stat file;
	struct dirent *stream;
	char *concat = malloc(512);
	DIR *dir;
	int total = 0;

	dir = opendir(av);
	stream = readdir(dir);
	concat = concat_params(av, "/");
	while (stream != NULL) {
		if (stream->d_name[0] != '.') {
			concat = concat_params(concat, stream->d_name);
			lstat(concat, &file);
			total += file.st_blocks;
			concat = concat_params(av, "/");
		}
		stream = readdir(dir);
	}
	my_printf("total %d\n", total / 2);
}

void display_spaces_files(stock_t *stk)
{
	if (stk->foldNbr == 1 && stk->options[0] == 48)
		my_putstr("\n");
	else if (stk->options[0] == 48)
		my_putstr("\n\n");
	else if (stk->foldNbr > 1 && stk->options[0] == 49)
		my_putstr("\n");
}
