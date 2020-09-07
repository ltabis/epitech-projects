/*
** EPITECH PROJECT, 2018
** do_count
** File description:
** do count
*/

#include "tetris.h"

void do_count(struct dirent *file, int *count)
{
	char *tmp = NULL;
	char *tmp2 = NULL;

	tmp = my_strcpy(tmp, file->d_name);
	tmp2 = tmp;
	if (tmp == NULL) {
		write(2, "Error", 5);
		exit(84);
	}
	for (int i = 0; my_strcmp(tmp, ".tetrimino") && tmp[0]; i++)
		tmp += 1;
	(my_strlen(tmp) == 10 && tmp != NULL ? *count += 1 : 0);
	free(tmp2);
}
