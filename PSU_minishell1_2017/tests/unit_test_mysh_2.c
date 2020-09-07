/*
** EPITECH PROJECT, 2018
** unit_test_mysh.c
** File description:
** unit tests for mysh
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/proto.h"

Test(mysh_basics, test_printf, .init = redirect_all_std)
{
	my_printf("%d, %s, %c, %4, %o\n", 1, "test", 't', 42, 76876);
	cr_assert_stdout_eq_str("1, test, t, 222, 226114\n");
}

Test(mysh_basics, test_my_strcat_2, .init = redirect_all_std)
{
	char *test;

	test = my_strcat_2("/bin", "ls");
	cr_assert_str_eq(test, "/bin/ls");
}

Test(mysh_basics, test_my_strcat_3, .init = redirect_all_std)
{
	char *test;

	test = my_strcat_3("VAR_NAME");
	cr_assert_str_eq(test, "VAR_NAME=");
}

Test(mysh_basics, test_my_strcat_4, .init = redirect_all_std)
{
	char *test;

	test = my_strcat_4("VAR_NAME");
	cr_assert_str_eq(test, "VAR_NAME");
}

Test(mysh_basics, test_convert_list_into_board, .init = redirect_all_std)
{
	char **board;
	env_t *env_lst = malloc(sizeof(env_t));
	env_t *new = malloc(sizeof(env_t));

	if (!env_lst)
		exit(84);
	env_lst->env_name = NULL;
	env_lst->env_value = NULL;
	new->env_name = my_strcpy("VAR=");
	new->env_value = my_strcpy("VALUE");
	env_lst->next = new;
	new->prev = env_lst;
	new->next = 0;
	env_lst->prev = 0;
	board = convert_list_into_board(env_lst);
	cr_assert_str_eq(board[0], "VAR=VALUE");
	free(env_lst);
	free(new);
}
