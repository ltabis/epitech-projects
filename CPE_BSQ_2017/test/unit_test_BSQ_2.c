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

Test(BSQ_test, check_free_memory)
{
	bsq_t *sq = malloc(sizeof(bsq_t));

	verify_file_stat("./map4.txt");
	sq->x = 0;
	sq->y = 0;
	sq = find_widht_and_height(sq, "./map4.txt");
	sq = load_2d_arr_from_file("./map4.txt", sq);
	free_memory(sq);
	cr_assert_neq(sq->x_file, NULL);
	cr_assert_neq(sq, NULL);
}

Test(sokoban_test, check_concat_params)
{
	char *concat;

	concat = concat_params("test", "42");
	cr_assert_neq(concat, "test42");
	free(concat);
}
