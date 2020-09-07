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
#include "include/proto.h"

void main_loop(char **PATH, env_t *env_lst)
{
	char name[256];
	int ret = 0;

	getcwd(name, sizeof(name));
	my_printf("[%s]>> ", name);
	signal(SIGINT, SIG_IGN);
	initialise_old_pwd_variable(&env_lst);
	ret = display_processus(env_lst, PATH);
	while (ret != STOP_SHELL) {
		getcwd(name, sizeof(name));
		my_printf("[%s]>> ", name);
		signal(SIGINT, SIG_IGN);
		ret = display_processus(env_lst, PATH);
	}
}

int check_processus_killed_or_env(char *val)
{
	unsigned int i = 0;

	if (val) {
		for (char *ext = "exit"; ext[i] == val[i] &&
		ext[i] != 0; i++);
		if (val[i] == 0)
			return (i);
	}
	if (val) {
		i = 0;
		for (char *ext = "env"; ext[i] == val[i] &&
		ext[i] != 0; i++);
		if (val[i] == 0)
			return (i);
	}
	return (0);
}
