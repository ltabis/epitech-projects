/*
** EPITECH PROJECT, 2017
** unit_test_my_sokoban_3.c
** File description:
** units tesint part3
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "../include/proto.h"
#include "../include/my.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(sokoban_test, check_putstr, .init = redirect_all_std)
{
	my_putstr("test unitaire");
	cr_assert_stdout_eq_str("test unitaire");
}

Test(sokoban_test, check_strcpy)
{
	char c1[] = "test\n";
	char c2[] = "wow\n";
	char *cf = my_strcpy(c1, c2);

	cr_assert_neq(cf, NULL);
}
