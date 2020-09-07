/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for the my_ls program
*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "include/my.h"
#include "include/proto.h"
#include "include/mystruct.h"

int main(int argc, char **argv)
{
	unsigned int i = 0;
	struct stat file;
	char *concat = concat_params("./", argv[argc - 1]);
	stock_t *stk = malloc(sizeof(stock_t));

	if (stk == NULL)
		exit(84);
	stk->foldNbr = 0;
	for (; i != 5; i++)
		stk->options[i] = '0';
	stk->options[5] = '\0';
	stk = search_options(argv, stk);
	check_option_d(argv, argc, stk);
	stk = parse_my_ls(argv, stk);
	lstat(concat, &file);
	if (S_ISREG(file.st_mode) && argc > 1 && stk->options[0] == 48)
		my_putchar('\n');
	stk = free_ressources(stk);
	return (0);
}

stock_t *search_options(char **av, stock_t *stk)
{
	unsigned int count = 1;

	for (; av[count] != 0; count++) {
		if (av[count][0] == '-')
			stk = choose_options(av[count], stk);
		else
			stk->foldNbr++;
	}
	return (stk);
}

stock_t *choose_options(char *av, stock_t *stk)
{
	unsigned int i = 1;
	unsigned int j = 0;
	char allOptions[] = "lRdrt";

	for (; av[i] != '\0'; i++)
		for (j = 0; allOptions[j] != '\0'; j++)
			stk = put_options(av[i], stk, allOptions, j);
	return (stk);
}

stock_t *put_options(char av, stock_t *stk, char *allOptions, unsigned int j)
{
	if (av == allOptions[j])
		stk->options[j] = '1';
	return (stk);
}

stock_t *free_ressources(stock_t *stk)
{
	free(stk);
	return (stk);
}
