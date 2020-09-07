/*
** EPITECH PROJECT, 2018
** unit_test_mysh.c
** File description:
** unit tests for mysh
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/proto.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(mysh_test, test_env_and_exit)
{
	app_info_t *info = malloc(sizeof(app_info_t));
	int ret = 0;

	info->ret = 0;
	ret = check_processus_killed_or_env("exit", info);
	cr_assert_eq(ret, -1);
	ret = check_processus_killed_or_env("env", info);
	cr_assert_eq(ret, 0);
	ret = check_processus_killed_or_env("env test stop", info);
	cr_assert_eq(ret, 0);
	free(info);
}

Test(mysh_test, test_env_to_list)
{
	char **env = malloc(sizeof(char *) * 4);
	env_t *env_lst;

	env[0] = my_strcpy("DISPLAY=OK");
	env[1] = my_strcpy("TEST=");
	env[2] = my_strcpy("test=VAR");
	env[3] = NULL;
	env_lst = env_to_list(env);
	env_lst = env_lst->next;
	cr_assert_str_eq(env_lst->env_name, "DISPLAY=");
	cr_assert_str_eq(env_lst->env_value, "OK");
	env_lst = env_lst->next;
	cr_assert_str_eq(env_lst->env_name, "TEST=");
	cr_assert_str_eq(env_lst->env_value, "");
	env_lst = env_lst->next;
	cr_assert_str_eq(env_lst->env_name, "OLDPWD=");
	cr_assert_str_eq(env_lst->env_value, "VAR");
	free_env_variable(&env_lst);
	cr_assert_str_eq(env_lst->env_name, NULL);
	free(env_lst);
}

Test(mysh_test, args_to_board_test)
{
	char **args = build_args("ls -lR -t");

	cr_assert_str_eq(args[0], "ls");
	cr_assert_str_eq(args[1], "-lR");
	cr_assert_str_eq(args[2], "-t");
	for (unsigned int i = 0; i < 3; i++)
		free(args[i]);
	free(args);
}

Test(mysh_test, error_messages, .init = redirect_all_std)
{
	my_perror_command("test");
	cr_assert_stderr_eq_str("test: Command not found.\n");
}
