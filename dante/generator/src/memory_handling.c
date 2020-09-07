/*
** EPITECH PROJECT, 2018
** memory_handling.c
** File description:
** memory handling file
*/

#include "generator.h"

void free_tree(cell_t *cells)
{
	cell_t *cells_tmp = cells;

	for (; cells->prev;) {
		cells = cells->prev;
		free(cells_tmp);
		cells_tmp = cells;
	}
	free(cells);
}
