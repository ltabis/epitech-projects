/*
** EPITECH PROJECT, 2018
** move_in_files.c
** File description:
** file that will care of the cd builded in
*/
#include <unistd.h>
#include <stdlib.h>
#include "include/proto.h"

void launch_cd(char *str, env_t **env_lst)
{
	unsigned int args = 1;

	for (; str[0] == ' '; str++);
	for (unsigned int i = 0; str[i] != 0; i++)
		if (str[i] == ' ' && str[i + 1] != ' ')
			args++;
	if (args > 2) {
		write(2, "cd: Too many arguments.\n", 24);
		return;
	}
	for (; !(str[0] == ' ' && str[1] != ' ') && str[0]; str++);
	str++;
	if (str[0] && (str[0] == '~' && str[1] == 0))
		get_back_to_home(env_lst);
	else if (str[0] && (str[0] == '-' && str[1] == 0))
		get_back_to_previous_location(env_lst);
	else if (str[0] && str[0] != '-' && str[0] != '~')
		check_path(str, env_lst);
	else
		get_back_to_home(env_lst);
}

int check_path(char *path, env_t **env_lst)
{
	int ret = 0;
	char OLDPWD[256];

	getcwd(OLDPWD, sizeof(OLDPWD));
	ret = chdir(path);
	if (check_file_stat(path) == 0)
		return (0);
	if (ret == -1) {
		write(2, path, my_strlen(path));
		write(2, ": Not a directory.\n", 19);
		return (0);
	}
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "OLDPWD=") == 0)
			(*env_lst)->env_value = my_strcpy(OLDPWD);
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
	*env_lst = (*env_lst)->next;
	return (0);
}

void get_back_to_home(env_t **env_lst)
{
	int ret = 0;
	char OLDPWD[256];

	getcwd(OLDPWD, sizeof(OLDPWD));
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "HOME=") == 0)
			ret = chdir((*env_lst)->env_value);
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
	*env_lst = (*env_lst)->next;
	if (ret == -1) {
		write(2,
		(*env_lst)->env_name, my_strlen((*env_lst)->env_name));
		write(2, ": Not a directory.\n", 19);
		return;
	}
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "OLDPWD=") == 0)
			(*env_lst)->env_value = my_strcpy(OLDPWD);
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
	*env_lst = (*env_lst)->next;
}

void get_back_to_previous_location(env_t **env_lst)
{
	int ret = 0;
	char OLDPWD[256];

	getcwd(OLDPWD, sizeof(OLDPWD));
	for (; (*env_lst)->next != 0; (*env_lst) = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "OLDPWD=") == 0)
			ret = chdir((*env_lst)->env_value);
	for (; (*env_lst)->prev != 0; (*env_lst) = (*env_lst)->prev);
	*env_lst = (*env_lst)->next;
	if (ret == -1) {
		write(2,
		(*env_lst)->env_name, my_strlen((*env_lst)->env_name));
		write(2, ": Not a directory.\n", 19);
		return;
	}
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "OLDPWD=") == 0)
			(*env_lst)->env_value = my_strcpy(OLDPWD);
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
	*env_lst = (*env_lst)->next;
}

void initialise_old_pwd_variable(env_t **env_lst)
{
	char OLDPWD[256];

	getcwd(OLDPWD, sizeof(OLDPWD));
	for (; (*env_lst)->next != 0; (*env_lst) = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "OLDPWD=") == 0)
			(*env_lst)->env_value = my_strcpy(OLDPWD);
	for (; (*env_lst)->prev != 0; (*env_lst) = (*env_lst)->prev);
	*env_lst = (*env_lst)->next;
}
