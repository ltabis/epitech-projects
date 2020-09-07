/*
** EPITECH PROJECT, 2018
** forking.c
** File description:
** file that will take care of the forking
*/
#include "../include/proto.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void start_forking(char **args, env_t *env_lst, app_info_t *infos)
{
	char **env = convert_list_into_board(env_lst);
	int status = 0;
	pid_t pid = fork();

	if (pid != 0) {
		wait(&status);
		check_signals(status, infos);
	} else {
		if (check_file_stat_exec(args[0], infos) == 0)
			exit(-84);
		else if (execve(args[0], args, env) == -1) {
			my_puterr(args[0]);
			my_puterr(": Exec format error. Wrong Architecture.\n");
			exit(-84);
		}
	}
	free_path_variable(env);
}

char **convert_list_into_board(env_t *env_lst)
{
	unsigned int i = 0;
	char **env = NULL;

	for (; env_lst->next != 0; env_lst = env_lst->next, i++);
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	for (; env_lst->prev != 0; env_lst = env_lst->prev);
	env_lst = env_lst->next;
	env = list_to_board(env_lst, env, i);
	return (env);
}

char **list_to_board(env_t *env_lst, char **env, unsigned int nb_var)
{
	unsigned int i = 0;

	for (; i < nb_var; env_lst = env_lst->next, i++) {
		if (env_lst->env_value != NULL)
			env[i] = my_strcat(
			env_lst->env_name, env_lst->env_value);
		else
			env[i] = my_strcpy(env_lst->env_name);
	}
	env[i] = NULL;
	return (env);
}

void check_signals(int status, app_info_t *infos)
{
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
		my_puterr("Segmentation fault\n");
		infos->ret = 139;
	} else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE) {
		my_puterr("Floating exception\n");
		infos->ret = 136;
	} else
		infos->ret = status == 44032 ? 1 : 0;
}

int check_file_stat_exec(char *path, app_info_t *infos)
{
	struct stat file;

	stat(path, &file);
	if (S_ISDIR(file.st_mode)) {
		my_puterr(path);
		my_puterr(": Permission denied.\n");
		infos->ret = 1;
		return (0);
	}
	return (1);
}