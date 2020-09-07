/*
** EPITECH PROJECT, 2018
** unit_test_mysh.c
** File description:
** unit tests for mysh
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/proto.h"

Test(mysh_basics, test_strcmp_1)
{
	int ret = my_strcmp("test", "test");
	cr_assert_eq(ret, 0);
}

Test(mysh_basics, test_strcmp_2)
{
	int ret = my_strcmp("test", "test test");
	cr_assert_neq(ret, 0);
}

Test(mysh_basics, test_strcmp_3)
{
	int ret = my_strcmp_env("setenv", "setenv test");
	cr_assert_eq(ret, 0);
}

Test(mysh_basics, test_strcmp_4)
{
	int ret = my_strcmp_env("unsetenv", "unsetes");
	cr_assert_neq(ret, 0);
}

Test(mysh_basics, test_printf_final, .init = redirect_all_std)
{
	my_printf("%i, %x, X, %, %u, %6, %8", 4, 10, 555, 4294967295, 42, 42);
	cr_assert_stdout_eq_str("4, 12, X, %, 555, 1550104015503, 52");
}
