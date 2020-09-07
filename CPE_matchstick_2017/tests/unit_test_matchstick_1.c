/*
** EPITECH PROJECT, 2017
** unit_test_myprintf.c
** File description:
** unti tests for my_printf
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "../include/proto.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(matchstick_test, test_basic_error_handling)
{
	int error = check_params("42", "23");

	cr_assert_eq(error, 0);
	error = check_params("42", "23e");
	cr_assert_eq(error, -1);
}

Test(matchstick_test, test_game_board_creation)
{
	unsigned char *board = create_game_board(2);

	cr_assert_eq(board[0], 1);
	cr_assert_eq(board[1], 3);
}

Test(matchstick_test, test_basic_functions, .init = redirect_all_std)
{
	int nbr = my_getnbr("42");
	char *str = "test";

	my_putchar('a');
	cr_assert_eq(nbr, 42);
	my_put_nbr(45);
	cr_assert_stdout_eq_str("a45");
	cr_assert_eq(my_strlen(str), 4);
}

Test(matchstick_test, test_basics_error_handling)
{
	char *input = malloc(sizeof(char) * 2);
	int error = check_params("32", "2");

	input[0] = '4';
	input[1] = 0;
	cr_assert_eq(error, 0);
	error = check_params("e32", "2");
	cr_assert_eq(error, -1);
	error = check_params("32", "2e");
	cr_assert_eq(error, -1);
	error = check_prompt_content(3, input, 1, 2);
	cr_assert_eq(error, -1);
	input = malloc(sizeof(char) * 2);
	input[0] = '4';
	input[1] = 0;
	error = check_prompt_content(3, input, 2, 1);
	cr_assert_eq(error, -1);
}
