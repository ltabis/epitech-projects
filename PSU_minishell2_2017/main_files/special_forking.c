/*
** EPITECH PROJECT, 2018
** special_forking.c
** File description:
** special forking for pipes
*/

#include "../include/proto.h"
#include "../include/parser.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void search_pipe_exec(char *command, char **path,
	env_t *env_lst, app_info_t *infos)
{
	char **args = build_args(command);
	char *filepath = my_strcpy(args[0]);
	int ret = access(filepath, F_OK);

	for (unsigned int i = 0; path[i] != 0 && ret != 0; i++) {
		filepath = my_strcat_2(path[i], args[0]);
		ret = access(filepath, F_OK);
	}
	if (ret == 0) {
		args[0] = my_strcpy(filepath);
		start_special_forking(args, env_lst, infos);
	} else {
		my_perror_command(args[0]);
		infos->ret = 1;
	}
	free_path_variable(args);
	for (char i = 0; i != 1; free(args), free(filepath), i = 1);
}

void start_special_forking(char **args, env_t *env_lst, app_info_t *infos)
{
	char **env = convert_list_into_board(env_lst);

	if (check_file_stat_exec(args[0], infos) == 0)
		exit(-84);
	else if (execve(args[0], args, env) == -1) {
		my_puterr(args[0]);
		my_puterr(": Exec format error. Wrong Architecture.\n");
		exit(-84);
	}
	free_path_variable(env);
}

void write_in_file(int fd, int *pipefd)
{
	char buff[256];
	int status = 0;

	wait(&status);
	close(pipefd[1]);
	pipefd[1] = read(pipefd[0], buff, 255);
	buff[pipefd[1]] = 0;
	write(fd, buff, pipefd[1]);
	close(pipefd[0]);
}

void create_old_path(env_t *env_lst)
{
	env_t *oldpwd = NULL;
	char name[256];
	char i = 0;

	for (env_lst = env_lst->next; env_lst->next && i == 0;) {
		i = my_strcmp(env_lst->env_name, "OLDPWD=") == 0 ? 1 : i;
		if (i != 1 && env_lst->next)
			env_lst = env_lst->next;
	}
	if (i != 1) {
		if ((oldpwd = malloc(sizeof(env_t))) == NULL)
			exit(84);
		getcwd(name, sizeof(name));
		env_lst->next = oldpwd;
		oldpwd->env_value = my_strcpy(name);
		oldpwd->env_name = my_strcpy("OLDPWD=");
		oldpwd->next = NULL;
		oldpwd->prev = env_lst;
	}
}