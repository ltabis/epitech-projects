/*
** EPITECH PROJECT, 2018
** unit_test_mysh.c
** File description:
** unit tests for mysh
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "../include/proto.h"

Test(mysh_basics, replace_var_name)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	replace_name(&env_lst, "VAL_NAME=");
	cr_assert_str_eq(env_lst->env_name, "VAL_NAME=");
	free(env_lst);
}

Test(mysh_basics, add_var_name)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	add_name_to_list(&env_lst, "VAL_NAME=");
	env_lst = env_lst->next;
	cr_assert_str_eq(env_lst->env_name, "VAL_NAME=");
	free(env_lst);
}

Test(mysh_basics, test_free_env_variable)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	env_lst->env_name = my_strcpy("TEST=");
	env_lst->env_value = my_strcpy("VALUE");
	free_env_variable(&env_lst);
	cr_assert_str_eq(env_lst->env_name, "");
	free(env_lst);
}

Test(mysh_basics, initiate_env_name_and_value)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	allocate_memory_env_name(&env_lst, 3);
	allocate_memory_env_value(&env_lst, 2);
	env_lst->env_name = my_strcpy("i=");
	env_lst->env_value = my_strcpy("2");
	cr_assert_str_eq(env_lst->env_name, "i=");
	cr_assert_str_eq(env_lst->env_value, "2");
	free(env_lst);
}

Test(mysh_basics, delete_board)
{
	char **test = malloc(sizeof(char *) * 4);

	test[0] = malloc(sizeof(char) * 3);
	test[1] = malloc(sizeof(char) * 3);
	test[2] = malloc(sizeof(char) * 3);
	test[3] = NULL;
	free_path_variable(test);
	cr_assert_str_eq(test[0], "");
}
