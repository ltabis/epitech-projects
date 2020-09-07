/*
** EPITECH PROJECT, 2018
** unit_test_basics.c
** File description:
** unit test for function is closer
*/

#include "test.h"
#include "proto.h"

Test(parser, test_my_put_err, .init = redirect_all_std)
{
	my_put_err("error message\n");
	cr_assert_stderr_eq_str("error message\n");
}

Test(parser, test_strlen)
{
	int len = my_strlen("Test string");

	cr_assert_eq(len, 11);
}

Test(parser, test_ncpy)
{
	char original[] = "lets test";
	char cpy[] = "nice tests";
	char *ret = NULL;

	ret = my_strncpy(cpy, original, 4);
	cr_assert_str_eq(ret, "lets tests");
}

Test(parser, test_str_to_word_array)
{
	char **word_array = my_str_to_word_array("123:efsfeqaefp:213R");

	cr_assert_str_eq(word_array[0], "123");
	cr_assert_str_eq(word_array[1], "efsfeqaefp");
}
