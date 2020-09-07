/*
** EPITECH PROJECT, 2018
** unit_test_gnl_2.c
** File description:
** unit_testing part 2
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "../include/proto.h"

Test(get_next_line_2, error_handling)
{
	char *s;
	int file_descriptor = -1;

	s = get_next_line(file_descriptor);
	cr_assert_eq(s, NULL);
}

Test(matchstick_tests, display_1, .init = redirect_all_std)
{
	display_info(1, 1);
	cr_assert_stdout_eq_str("Player removed 1 match(es) from line 1\n");
}

Test(matchstick_tests, display_2, .init = redirect_all_std)
{
	unsigned char *board = malloc(sizeof(unsigned char) * 3);

	board[0] = 1;
	board[1] = 3;
	board[2] = 5;
	display_matches(board, 3);
	cr_assert_stdout_eq_str("  |  *\n* ||| *\n*|||||*\n*");
	free(board);
}

Test(matchstick_tests, display_3, .init = redirect_all_std)
{
	unsigned char *board = malloc(sizeof(unsigned char) * 3);

	board[0] = 1;
	board[1] = 3;
	board[2] = 5;
	display_board(board, 3);
	cr_assert_stdout_eq_str(
	"*******\n*  |  *\n* ||| *\n*|||||*\n*******\n");
	free(board);
}

Test(matchstick_tests, my_strcpy)
{
	unsigned char *test = "len";
	unsigned char *cpy = my_strcpy(test, 3);

	cr_assert_str_eq((char *)cpy, test);
}