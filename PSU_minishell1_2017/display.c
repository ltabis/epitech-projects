/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** file that will contain display functions
*/
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "include/proto.h"

int display_processus(env_t *env_lst, char **PATH)
{
	char *s = transform_str(get_next_line(0));
	int ret;

	if (!s) {
		free_env_variable(&env_lst);
		exit(0);
	}
	ret = check_processus_killed_or_env(s);
	if (ret == STOP_SHELL) {
		write(1, "exit\n", 5);
		return (STOP_SHELL);
	} else if (ret == DISP_PATH)
		display_env_variables(env_lst);
	else if (my_strcmp_env(s, "setenv") == 0 ||
		my_strcmp_env(s, "unsetenv") == 0 ||
		my_strcmp_env(s, "cd") == 0)
		add_or_remove_env_variable(&env_lst, s);
	else if (s[0])
		search_exec(s, PATH, env_lst);
	return (0);
}

void add_or_remove_env_variable(env_t **env_lst, char *prompt)
{
	if (my_strcmp_env(prompt, "setenv") == 0) {
		if (check_alphanumeric_variable(prompt) == 0)
			add_variable(env_lst, prompt);
		else if (check_alphanumeric_variable(prompt) == 1) {
			write(2, "setenv: Variable name ", 22);
			write(2, "must begin with a letter.\n", 26);
		} else {
			write(2, "setenv: Variable name must ", 27);
			write(2, "contain alphanumeric characters.\n", 33);
		}
	} else if ((my_strcmp_env(prompt, "unsetenv") == 0))
		remove_variable(env_lst, prompt);
	else
		launch_cd(prompt, env_lst);
}

void display_env_variables(env_t *env_lst)
{
	for (; env_lst->next != 0; env_lst = env_lst->next) {
		if (env_lst->env_value) {
			my_printf("%s", env_lst->env_name);
			my_printf("%s\n", env_lst->env_value);
		} else
			my_printf("%s\n", env_lst->env_name);
	}
	if (env_lst->env_value) {
		my_printf("%s", env_lst->env_name);
		my_printf("%s\n", env_lst->env_value);
	} else
		my_printf("%s\n", env_lst->env_name);
}

void add_variable(env_t **env_lst, char *prompt)
{
	unsigned int args = 1;

	for (; prompt[0] == ' '; prompt++);
	for (unsigned int i = 0; prompt[i] != 0; i++)
		if (prompt[i] == ' ' && prompt[i + 1] != ' ')
			args++;
	if (args == 1)
		display_env_variables(*env_lst);
	else if (args == 2)
		change_name_in_env(env_lst, prompt);
	else if (args == 3)
		change_name_and_variable_in_env(env_lst, prompt);
	else if (args > 3)
		write(2, "setenv: Too many arguments.\n", 28);
}

void remove_variable(env_t **env_lst, char *prompt)
{
	unsigned int args = 1;

	for (; prompt[0] == ' '; prompt++);
	for (unsigned int i = 0; prompt[i] != 0; i++)
		if (prompt[i] == ' ' && prompt[i + 1] != ' ')
			args++;
	if (args <= 1)
		write(2, "unsetenv: Too few arguments.\n", 29);
	else
		delete_env_variables(env_lst, prompt);
}
