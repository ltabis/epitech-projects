/*
** EPITECH PROJECT, 2017
** unit_test_ia_1.c
** File description:
** unti tests for ia
*/

#include <string.h>
#include "test.h"
#include "solver.h"

Test(ia_solving, test_strcat)
{
	char *test1 = malloc(sizeof(char) * 3);
	char *test2 = "a test!";
	char *result = NULL;

	test1[0] = 'I';
	test1[1] = ' ';
	test1[2] = 0;
	result = my_strcat(test1, test2);
	cr_assert_str_eq(result, "I a test!");
	free(result);
}
