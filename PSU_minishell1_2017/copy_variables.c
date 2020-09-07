/*
** EPITECH PROJECT, 2018
** copy_variables.c
** File description:
** files that will taker care of the copy of env and arg variable
*/
#include <stdlib.h>
#include "include/proto.h"

env_t *env_to_list(char **env)
{
	env_t *env_lst = malloc(sizeof(env_t));

	env_lst->next = 0;
	env_lst->prev = 0;
	env_lst->env_name = NULL;
	env_lst->env_value = NULL;
	for (int j = 0; env[j] != 0; j++)
		load_variable_in_list(&env_lst, env[j]);
	env_lst->next = 0;
	for (; env_lst->prev != 0; env_lst = env_lst->prev);
	return (env_lst);
}

void load_variable_in_list(env_t **env_lst, char *var)
{
	unsigned int i = 0;
	unsigned int j = 0;
	env_t *new_case = malloc(sizeof(env_t));

	if (!new_case)
		exit(84);
	for (; var[i] != '='; i++);
	allocate_memory_env_name(&new_case, i);
	for (i = 0; var[i] != '='; i++)
		new_case->env_name[i] = var[i];
	new_case->env_name[i++] = '=';
	new_case->env_name[i++] = 0;
	allocate_memory_env_value(&new_case, my_strlen(var) - i);
	for (i--; var[i] != 0; i++, j++)
		new_case->env_value[j] = var[i];
	new_case->env_value[j] = 0;
	(*env_lst)->next = new_case;
	new_case->prev = *env_lst;
	*env_lst = new_case;
}

char **create_path_board(env_t *env_lst)
{
	char **path_v;
	unsigned int size = 1;

	for (unsigned int i = 0; env_lst->next != 0 && i == 0;) {
		if (my_strcmp(env_lst->env_name, "PATH=") == 0)
			i = 1;
		else
			env_lst = env_lst->next;
	}
	for (unsigned int i = 0; env_lst->env_value[i] != 0; i++)
		if (env_lst->env_value[i] == ':')
			size++;
	path_v = malloc(sizeof(char *) * (size + 2));
	if (!path_v)
		exit(84);
	path_v = copy_paths_in_board(env_lst->env_value, path_v, size + 1);
	return (path_v);
}

char **copy_paths_in_board(char *PATH, char **path_v, unsigned int size)
{
	unsigned int index = 0;
	unsigned int i = 0;

	for (; i < size && PATH[index] != 0; i++)
		path_v[i] = copy_string_in_board(PATH, path_v[i], &index);
	path_v[i] = NULL;
	return (path_v);
}

char *copy_string_in_board(char *PATH, char *path_str, unsigned int *index)
{
	unsigned int i = 0;

	for (i = *index; PATH[i] != ':' && PATH[i] != 0; i++);
	path_str = malloc(sizeof(char) * (i - *index + 1));
	if (!path_str)
		exit(84);
	for (i = 0; PATH[*index] != ':' && PATH[*index] != 0; i++, (*index)++)
		path_str[i] = PATH[*index];
	if (PATH[*index] == ':')
		(*index)++;
	path_str[i] = 0;
	return (path_str);
}
