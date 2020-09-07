/*
** EPITECH PROJECT, 2017
** unit_test_tetris_1.c
** File description:
** unit tests for the PSU's tetris project
*/
#include <criterion/criterion.h>
#include "../include/tetris.h"
#include "../include/base.h"

Test(testris, change_key_left)
{
	control_t controls = {{10, 20}, NULL, NULL, NULL, NULL,
	NULL, NULL, 1, FALSE, FALSE, 0, 3, 1, 0, 0};

	change_key_quit(&controls, "test");
	cr_assert_str_eq(controls.key_quit2, "test");
}

Test(testris, change_key_pause)
{
	control_t controls = {{10, 20}, NULL, NULL, NULL, NULL,
	NULL, NULL, 1, FALSE, FALSE, 0, 3, 1, 0, 0};

	change_key_pause(&controls, "pause");
	cr_assert_str_eq(controls.key_pause2, "pause");
}

Test(testris, change_level)
{
	control_t controls = {{10, 20}, NULL, NULL, NULL, NULL,
	NULL, NULL, 1, FALSE, FALSE, 0, 3, 1, 0, 0};

	change_level(&controls, "223");
	cr_assert_eq(controls.level, 223);
}

Test(testris, change_debug)
{
	control_t controls = {{10, 20}, NULL, NULL, NULL, NULL,
	NULL, NULL, 1, FALSE, FALSE, 0, 3, 1, 0, 0};

	change_debug(&controls, NULL);
	cr_assert_eq(controls.debug, 1);
}

Test(testris, test_option_left)
{
	control_t controls = {{10, 20}, NULL, NULL, NULL, NULL,
	NULL, NULL, 1, FALSE, FALSE, 0, 3, 1, 0, 0};

	change_next(&controls, NULL);
	cr_assert_eq(controls.act_next_tetr, 1);
}