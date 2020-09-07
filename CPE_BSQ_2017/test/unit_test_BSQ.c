/*
** EPITECH PROJECT, 2017
** unit_test_myprintf.c
** File description:
** unti tests for my_printf
*/
#include <stdlib.h>
#include <criterion/criterion.h>
#include "../include/proto.h"
#include "../include/my.h"

Test(BSQ_test, check_row_and_column)
{
	bsq_t *sq = malloc(sizeof(bsq_t));

	verify_file_stat("./map4.txt");
	sq->x = 0;
	sq->y = 0;
	sq = find_widht_and_height(sq, "./map4.txt");
	cr_assert_eq(sq->y, 5);
	cr_assert_eq(sq->x, 5);
	free(sq);
}

Test(BSQ_test, check_easy_map_in_memory)
{
	bsq_t *sq = malloc(sizeof(bsq_t));

	verify_file_stat("./map4.txt");
	sq->x = 0;
	sq->y = 0;
	sq = find_widht_and_height(sq, "./map4.txt");
	sq = load_2d_arr_from_file("./map4.txt", sq);
	cr_assert_neq(sq->x_file[0], NULL);
	cr_assert_neq(sq->x_file[1], NULL);
	cr_assert_neq(sq->x_file[2], NULL);
	cr_assert_neq(sq->x_file[3], NULL);
	cr_assert_neq(sq->x_file[4], NULL);
	cr_assert_eq(sq->x_file[0][0], '.');
	cr_assert_eq(sq->x_file[0][3], 'o');
	cr_assert_eq(sq->x_file[1][2], 'o');
	cr_assert_eq(sq->x_file[4][4], '.');
	free(sq);
}

Test(BSQ_test, check_memory)
{
	bsq_t *sq = malloc(sizeof(bsq_t));

	verify_file_stat("./map4.txt");
	sq->x = 0;
	sq->y = 0;
	sq = find_widht_and_height(sq, "./map4.txt");
	sq = load_2d_arr_from_file("./map4.txt", sq);
	cr_assert_neq(sq->x_file, NULL);
	cr_assert_neq(sq->x_file[1], NULL);
	free(sq);
}

Test(BSQ_test, check_concat_string)
{
	char *c1 = "wow";
	char *c2 = "/test";
	char *cf = concat_params(c1, c2);

	cr_assert_neq(cf, NULL);
	free(cf);
}

Test(BSQ_test, check_biggest_square_easy_struct)
{
	bsq_t *sq = malloc(sizeof(bsq_t));

	sq->x = 0;
	sq->y = 0;
	sq = find_widht_and_height(sq, "./map4.txt");
	sq = load_2d_arr_from_file("./map4.txt", sq);
	sq->x_save = 0;
	sq->y_save = 0;
	sq->size_max = 0;
	for (int y_start = 0; y_start < sq->y;) {
		for (int x_start = 0; x_start < sq->x;) {
			sq = verify_square(sq, x_start, y_start, 1);
			x_start++;
		}
		y_start++;
	}
	cr_assert_eq(sq->x_save, 2);
	cr_assert_eq(sq->y_save, 2);
	cr_assert_eq(sq->size_max, 3);
	free(sq);
}
