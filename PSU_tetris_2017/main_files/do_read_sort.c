/*
** EPITECH PROJECT, 2018
** do_read_sort
** File description:
** do_read_sort
*/

#include "tetris.h"

void do_read_sort(struct dirent *file, int *count, char **names)
{
        if (file->d_type == DT_REG) {
		names = do_sort_names(names, file->d_name, count);
		if (names[0] == NULL) {
			write(2, "Error", 5);
			exit(84);
		}
	}
}
