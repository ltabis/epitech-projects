/*
** EPITECH PROJECT, 2018
** modify_env_variable.c
** File description:
** modifying env variable
*/
#include "include/proto.h"
#include <stdlib.h>

int change_name_in_env(env_t **env_lst, char *prompt)
{
	for (; !(prompt[0] == ' ' && prompt[1] != ' '); prompt++);
	prompt++;
	prompt = my_strcat(prompt, "=");
	for (; (*env_lst)->next != 0 ; *env_lst = (*env_lst)->next) {
		if (my_strcmp(((*env_lst)->env_name), prompt) == 0) {
			replace_name(env_lst, prompt);
			return (0);
		}
	}
	if (my_strcmp((*env_lst)->env_name, prompt) == 0) {
		replace_name(env_lst, prompt);
		return (0);
	} else
		add_name_to_list(env_lst, prompt);
	return (0);
}

void add_name_to_list(env_t **env_lst, char *name)
{
	env_t *new_case = malloc(sizeof(env_t));

	if (!new_case)
		exit(84);
	new_case->next = NULL;
	new_case->env_name = my_strcpy(name);
	new_case->env_value = NULL;
	(*env_lst)->next = new_case;
	new_case->prev = *env_lst;
	*env_lst = new_case;
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
}

void replace_name(env_t **env_lst, char *name)
{
	(*env_lst)->env_name = my_strcpy(name);
	(*env_lst)->env_value = NULL;
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
}
