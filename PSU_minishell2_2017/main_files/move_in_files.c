/*
** EPITECH PROJECT, 2018
** move_in_files.c
** File description:
** file that will care of the cd builded in
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/proto.h"

void launch_cd(char *str, env_t **env_lst, app_info_t *infos)
{
	unsigned int args = 1;

	create_old_path(*env_lst);
	for (; str[0] == ' '; str++);
	for (unsigned int i = 0; str[i] != 0; i++)
		args += str[i] == ' ' && str[i + 1] != ' ' ? 1 : 0;
	if (args > 2) {
		infos->ret = 1;
		my_puterr("cd: Too many arguments.\n");
		return;
	}
	for (; !(str[0] == ' ' && str[1] != ' ') && str[0]; str++);
	str++;
	if (str[0] && (str[0] == '~' && str[1] == 0))
		get_back_to_home(env_lst, infos);
	else if (str[0] && (str[0] == '-' && str[1] == 0))
		get_back_to_previous_location(env_lst, infos);
	else if (str[0] && str[0] != '-' && str[0] != '~')
		check_path(str, env_lst, infos);
	else
		get_back_to_home(env_lst, infos);
}

int check_path(char *path, env_t **env_lst, app_info_t *infos)
{
	int ret = 0;
	char OLDPWD[256];

	getcwd(OLDPWD, sizeof(OLDPWD));
	if (check_file_stat(path, infos) == 0)
		return (0);
	if ((ret = chdir(path)) == -1) {
		my_puterr(path);
		my_puterr(": Not a directory.\n");
		infos->ret = 1;
		return (0);
	}
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "OLDPWD=") == 0)
			(*env_lst)->env_value = my_strcpy(OLDPWD);
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
	*env_lst = (*env_lst)->next;
	infos->ret = 0;
	return (0);
}

void get_back_to_home(env_t **lst, app_info_t *infos)
{
	int ret = 0;
	char OLDPWD[256];

	getcwd(OLDPWD, sizeof(OLDPWD));
	for (; (*lst)->next != 0; *lst = (*lst)->next)
		if (my_strcmp((*lst)->env_name, "HOME=") == 0)
			ret = chdir((*lst)->env_value);
	for (; (*lst)->prev != 0; *lst = (*lst)->prev);
	if (ret == -1) {
		my_puterr((*lst)->env_name);
		my_puterr(": Not a directory.\n");
		infos->ret = 1;
		return;
	}
	for (*lst = (*lst)->next; (*lst)->next != 0; *lst = (*lst)->next)
		if (my_strcmp((*lst)->env_name, "OLDPWD=") == 0)
			(*lst)->env_value = my_strcpy(OLDPWD);
	for (; (*lst)->prev != 0; *lst = (*lst)->prev);
	*lst = (*lst)->next;
	infos->ret = 0;
}

void get_back_to_previous_location(env_t **lst, app_info_t *infos)
{
	int ret = 0;
	char OLDPWD[256];

	getcwd(OLDPWD, sizeof(OLDPWD));
	for (; (*lst)->next != 0; (*lst) = (*lst)->next) {
		if (my_strcmp((*lst)->env_name, "OLDPWD=") == 0)
			ret = chdir((*lst)->env_value);
	}
	for (; (*lst)->prev != 0; (*lst) = (*lst)->prev);
	if (ret == -1) {
		my_puterr((*lst)->env_name);
		my_puterr(": Not a directory.\n");
		infos->ret = 1;
		return;
	}
	for (*lst = (*lst)->next; (*lst)->next != 0; *lst = (*lst)->next)
		if (my_strcmp((*lst)->env_name, "OLDPWD=") == 0)
			(*lst)->env_value = my_strcpy(OLDPWD);
	for (; (*lst)->prev != 0; *lst = (*lst)->prev);
	*lst = (*lst)->next;
	infos->ret = 0;
}

void initialise_old_pwd_variable(env_t **env_lst, app_info_t *infos)
{
	char OLDPWD[256];

	getcwd(OLDPWD, sizeof(OLDPWD));
	for (; (*env_lst)->next != 0; (*env_lst) = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "OLDPWD=") == 0)
			(*env_lst)->env_value = my_strcpy(OLDPWD);
	for (; (*env_lst)->prev != 0; (*env_lst) = (*env_lst)->prev);
	*env_lst = (*env_lst)->next;
	infos->ret = 0;
}
