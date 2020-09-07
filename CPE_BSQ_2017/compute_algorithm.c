/*
** EPITECH PROJECT, 2017
** algorithm.c
** File description:
** algorithm for the BSQ project
*/
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "include/my.h"
#include "include/proto.h"

bsq_t *find_biggest_square(bsq_t *sq)
{
	int x_start = 0;
	int y_start = 0;

	sq->x_save = 0;
	sq->y_save = 0;
	sq->size_max = 0;
	while (y_start < sq->y) {
		x_start = 0;
		while (x_start < sq->x) {
			sq = verify_square(sq, x_start, y_start, 1);
			x_start++;
		}
		y_start++;
	}
	if (sq->size_max != 0)
		sq = draw_x_and_stock(sq);
	display_biggest_square(sq);
	return (sq);
}

bsq_t *verify_square(bsq_t *sq, int x_start, int y_start, int size)
{
	int sq_x = x_start;
	int sq_y = y_start;
	int size_x = x_start + size;
	int size_y = y_start + size;

	if (size_x > sq->x || size_y > sq->y)
		return (sq);
	for (; sq_y < size_y; sq_y++) {
		for (sq_x = x_start; sq_x < size_x; sq_x++)
			if (sq->x_file[sq_y][sq_x] == 'o')
				return (sq);
	}
	if ((sq_x == size_x && sq_y == size_y) && size > sq->size_max) {
		sq->size_max = size;
		sq->x_save = x_start;
		sq->y_save = y_start;
		sq = verify_square(sq, x_start, y_start, size + 1);
	}
	sq = verify_square(sq, x_start, y_start, size + 1);
	return (sq);
}

bsq_t *draw_x_and_stock(bsq_t *sq)
{
	int x = sq->x_save;
	int y = sq->y_save;
	int x_max = sq->x_save + sq->size_max;
	int y_max = sq->y_save + sq->size_max;

	for (; y < y_max; y++)
		for (x = sq->x_save; x < x_max; x++)
			sq->x_file[y][x] = 'x';
	return (sq);
}

void display_biggest_square(bsq_t *sq)
{
	int x = 0;
	int y = 0;

	for (y = 0; y < sq->y; y++) {
		for (x = 0; x < sq->x; x++)
			my_putchar(sq->x_file[y][x]);
		my_putchar('\n');
	}
}
