/*
** EPITECH PROJECT, 2018
** unit_test_is_closer.c
** File description:
** unit test for function is closer
*/

#include "test.h"
#include "proto.h"

Test(parser, check_false)
{
	float new = 10;
	float old = 2;
	float referent = 4;
	int result = is_closer(old, new, referent);

	cr_assert_eq(result, 0);
}

Test(parser, check_true)
{
	float new = 2;
	float old = 6;
	float referent = 3;
	int result = is_closer(old, new, referent);

	cr_assert_eq(result, 0);
}
