/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** file that will contain display functions
*/
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "../include/proto.h"
#include "../include/parser.h"

int display_processus(env_t *env_lst, char **path, app_info_t *infos)
{
	char *s = transform_str(get_next_line(0));
	int ret = 0;

	if (!s)
		return (-1);
	ret = check_processus_killed_or_env(s, infos);
	if (ret == STOP_SHELL) {
		my_putstr("exit\n");
		return (STOP_SHELL);
	} else if (ret == DISP_PATH)
		display_env_variables(env_lst);
	else if (my_strcmp_env(s, "setenv") == 0 ||
		my_strcmp_env(s, "unsetenv") == 0 ||
		my_strcmp_env(s, "cd") == 0)
		add_or_remove_env_variable(&env_lst, s, infos);
	else if (s[0])
		check_redirections(s, path, env_lst, infos);
	return (0);
}

void add_or_remove_env_variable(env_t **env_lst, char *prompt,
	app_info_t *infos)
{
	if (my_strcmp_env(prompt, "setenv") == 0) {
		if (check_alphanumeric_variable(prompt) == 0) {
			add_variable(env_lst, prompt, infos);
			infos->ret = 0;
		} else if (check_alphanumeric_variable(prompt) == 1) {
			my_puterr("setenv: Variable name ");
			my_puterr("must begin with a letter.\n");
			infos->ret = 1;
		} else {
			my_puterr("setenv: Variable name must ");
			my_puterr("contain alphanumeric characters.\n");
			infos->ret = 1;
		}
	} else if ((my_strcmp_env(prompt, "unsetenv") == 0))
		remove_variable(env_lst, prompt, infos);
	else
		launch_cd(prompt, env_lst, infos);
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

void add_variable(env_t **env_lst, char *prompt, app_info_t *infos)
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
	else if (args > 3) {
		infos->ret = 1;
		my_puterr("setenv: Too many arguments.\n");
	}
}

void remove_variable(env_t **env_lst, char *prompt, app_info_t *infos)
{
	unsigned int args = 1;

	for (; prompt[0] == ' '; prompt++);
	for (unsigned int i = 0; prompt[i] != 0; i++)
		if (prompt[i] == ' ' && prompt[i + 1] != ' ')
			args++;
	if (args <= 1) {
		my_puterr("unsetenv: Too few arguments.\n");
		infos->ret = 1;
	} else
		delete_env_variables(env_lst, prompt);
}
