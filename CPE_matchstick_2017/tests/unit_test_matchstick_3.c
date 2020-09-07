/*
** EPITECH PROJECT, 2018
** unit_test_gnl.c
** File description:
** unit testing for the gnl project
*/
#include <criterion/criterion.h>
#include "../include/proto.h"

Test(get_next_line, concat_params_function)
{
	char *s3 = my_strcat("je suis ", "un test !");
	char *s4 = "je suis un test !";

	cr_assert_str_eq(s3, s4);
}

Test(get_next_line, ia_general)
{
	int a = 1;
	unsigned char *board = malloc(sizeof(unsigned char) * 3);

	board[0] = 1;
	board[1] = 3;
	board[2] = 5;
	a = process_ia_turn(&board, 2, 3);
	cr_assert_eq(a, 0);
}
