/*
** EPITECH PROJECT, 2017
** memory_handling.c
** File description:
** functions to handle memory
*/
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/proto.h"

void free_memory(bsq_t *sq)
{
	for (int y = 0; y < sq->y; y++)
		free(sq->x_file[y]);
	free(sq->x_file);
	free(sq);
}

bsq_t *add_custom_malloc_file_row(bsq_t *sq)
{
	sq->x_file = malloc(sizeof(char *) * sq->y + 1);
	if (!sq->x_file)
		exit(84);
	return (sq);
}

bsq_t *add_custom_malloc_file_col(bsq_t *sq, int i)
{
	sq->x_file[i] = malloc(sizeof(char) * sq->x);
	if (!sq->x_file[i])
		exit(84);
	return (sq);
}
