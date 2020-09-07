/*
** EPITECH PROJECT, 2017
** unit_test_tetris_1.c
** File description:
** unit tests for the PSU's tetris project
*/
#include <criterion/criterion.h>
#include "../include/tetris.h"
#include "../include/base.h"

Test(testris, test_basic_debug_mode)
{
	char *filepath1 = NULL;
	char *filepath2 = NULL;
	info_t info;

	filepath1 = my_strcpy(filepath1, "tetriminos/4.tetrimino");
	filepath2 = my_strcpy(filepath2, "tetriminos/6.tetrimino");
	info = check_tetriminos(filepath1);
	cr_assert_eq(info.state, -1);
	info = check_tetriminos(filepath2);
	cr_assert_eq(info.size.x, 2);
	cr_assert_eq(info.size.y, 3);
	cr_assert_eq(info.color, 6);
	cr_assert_eq(info.state, 0);
}

Test(testris, check_sort_test)
{
	char **names = malloc(sizeof(char *) * 4);
	int res = 0;

	for (unsigned int i = 0; i < 4; i++) {
		names[i] = malloc(sizeof(char) * 4);
		for (unsigned int j = 0; j < 4; j++)
			names[i][j] = 'n';
		names[i][3] = 0;
	}
	names[3] = NULL;
	res = check_sort(names);
	cr_assert_eq(res, 0);
}

Test(testris, check_strndup)
{
	char *test = my_strndup("TEST", 4);

	cr_assert_str_eq(test, "TEST");
}

Test(testris, my_getnbr)
{
	int test = my_getnbr("4242");
	int test2 = my_getnbr("42e42");
	int test3 = my_getnbr("-50");
	int test4 = my_getnbr_no_char("4242");
	int test5 = my_getnbr_no_char("42e42");
	int test6 = my_getnbr_no_char("-50");

	cr_assert_eq(test, 4242);
	cr_assert_eq(test2, 4242);
	cr_assert_eq(test3, -50);
	cr_assert_eq(test4, 4242);
	cr_assert_eq(test5, -1);
	cr_assert_eq(test6, -1);
}