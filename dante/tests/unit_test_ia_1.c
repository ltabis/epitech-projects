/*
** EPITECH PROJECT, 2017
** unit_test_ia_1.c
** File description:
** unti tests for ia
*/

#include <string.h>
#include "test.h"
#include "generator.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
}

Test(ia_generation, maze_display)
{
	char *maze = generate_maze(200, 400, "perfect");

	cr_assert_neq(maze, NULL);
	maze = generate_maze(200, 400, NULL);
	cr_assert_neq(maze, NULL);
}

Test(ia_generation, try_invalid_nbr_arg)
{
	int ret = check_paramters(2, NULL);
	char **av = malloc(sizeof(char *) * 4);

	av[0] = strdup("./generator");
	av[1] = strdup("102e");
	av[2] = strdup("10");
	av[3] = NULL;
	cr_assert_eq(ret, -1);
	ret = check_paramters(3, av);
	cr_assert_eq(ret, -1);
	free(av[1]);
	free(av[2]);
	av[1] = strdup("42");
	av[2] = strdup("e3");
	cr_assert_eq(ret, -1);
	free(av[2]);
	av[2] = strdup("10");
	cr_assert_eq(check_paramters(3, av), 0);
	for (unsigned int i = 0; i < 3; i++)
		free(av[i]);
}

Test(ia_generation, test_is_number)
{
	int ret = is_number("42");

	cr_assert_eq(ret, 0);
	ret = is_number("434e23");
	cr_assert_eq(ret, -1);
}

Test(ia_generation, test_negative_number)
{
	int ret = is_negative_number("-3", "23");

	cr_assert_eq(ret, -1);
	ret = is_negative_number("234", "873");
	cr_assert_eq(ret, 0);
}
