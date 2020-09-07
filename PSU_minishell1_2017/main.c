/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for the minishell project
*/
#include "include/get_next_line.h"
#include "include/proto.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	env_t *env_lst = env_to_list(env);
	char **path_v;

	if (!env[0])
		return (84);
	av = av;
	env_lst = env_lst->next;
	path_v = create_path_board(env_lst);
	if (ac != 1)
		return (84);
	main_loop(path_v, env_lst);
	free_env_variable(&env_lst);
	free(env_lst);
	free(path_v);
	return (0);
}
