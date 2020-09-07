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

Test(mysh_basics, cd_error_msg, .init = redirect_all_std)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	launch_cd("cd test test", &env_lst);
	cr_assert_stderr_eq_str("cd: Too many arguments.\n");
	free(env_lst);
}

Test(mysh_basics, test_setenv_error_1, .init = redirect_all_std)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	add_or_remove_env_variable(&env_lst, "setenv =test");
	cr_assert_stderr_eq_str(
	"setenv: Variable name must begin with a letter.\n");
	free(env_lst);
}

Test(mysh_basics, test_setenv_error_2, .init = redirect_all_std)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	add_or_remove_env_variable(&env_lst, "setenv t=est");
	cr_assert_stderr_eq_str(
	"setenv: Variable name must contain alphanumeric characters.\n");
	free(env_lst);
}

Test(mysh_basics, display_env, .init = redirect_all_std)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	env_lst->env_name = my_strcpy("test=");
	env_lst->env_value = my_strcpy("1");
	add_variable(&env_lst, "setenv test 0");
	display_env_variables(env_lst);
	cr_assert_stdout_eq_str("test=0\n");
	free(env_lst);
}

Test(mysh_basics, display_env_and_remove, .init = redirect_all_std)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	env_lst->env_name = my_strcpy("test=");
	env_lst->env_value = my_strcpy("1");
	add_variable(&env_lst, "setenv test 0");
	add_variable(&env_lst, "setenv test2 0");
	display_env_variables(env_lst);
	remove_variable(&env_lst, "unsetenv test");
	cr_assert_str_eq(env_lst->env_name, "test2=");
	free(env_lst);
}
