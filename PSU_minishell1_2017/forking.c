/*
** EPITECH PROJECT, 2018
** forking.c
** File description:
** file that will take care of the forking
*/
#include "include/proto.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void start_forking(char **args, env_t* env_lst)
{
	char **env = convert_list_into_board(env_lst);
	int status = 0;
	pid_t pid = fork();

	if (pid != 0) {
		wait(&status);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
			write(2, "Segmentation fault\n", 19);
		else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE)
			write(2, "Floating exception\n", 19);
	} else {
		if (execve(args[0], args, env) == -1) {
			write(2, args[0], my_strlen(args[0]));
			write(2, ": Exec format error. ", 21);
			write(2, "Wrong Architecture.\n", 20);
			exit(0);
		}
	}
	env = free_path_variable(env);
}

char **convert_list_into_board(env_t *env_lst)
{
	unsigned int i = 0;
	char **env = NULL;

	for (; env_lst->next != 0; env_lst = env_lst->next, i++);
	env = malloc(sizeof(char *) * (i + 1));
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
