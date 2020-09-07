/*
** EPITECH PROJECT, 2018
** main_loop.c
** File description:
** main loop for the minishell
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include "../include/proto.h"

int main_loop(char **path, env_t *env_lst)
{
	char name[256];
	int ret = 0;
	app_info_t infos = {0};

	getcwd(name, sizeof(name));
	my_printf("\033[31m[\033[32m%s\033[31m]\033[34m>>\033[0m ", name);
	signal(SIGINT, SIG_IGN);
	initialise_old_pwd_variable(&env_lst, &infos);
	ret = display_processus(env_lst, path, &infos);
	while (ret != STOP_SHELL) {
		getcwd(name, sizeof(name));
		my_printf("\033[31m[\033[32m%s\033[31m]\033[34m>>\033[0m ",
		name);
		signal(SIGINT, SIG_IGN);
		ret = display_processus(env_lst, path, &infos);
	}
	return (infos.ret == -1 ? 0 : infos.ret);
}

int check_processus_killed_or_env(char *val, app_info_t *infos)
{
	unsigned int i = 0;

	if (val) {
		for (char *ext = "exit"; ext[i] == val[i] &&
		ext[i] != 0; i++);
		if (val[i] == 0 && i == 4) {
			infos->ret = 0;
			return (-1);
		}
	} else if (val) {
		i = 0;
		for (char *ext = "env"; ext[i] == val[i] &&
		ext[i] != 0; i++);
		if (val[i] == 0 && i == 3)
			return (i);
	}
	return (0);
}
