/*
** EPITECH PROJECT, 2018
** modify_env_variable_name.c
** File description:
** 
*/
#include "../include/proto.h"
#include <stdlib.h>

int change_name_and_variable_in_env(env_t **env_lst, char *prompt)
{
	char *name;
	char *value;

	for (; !(prompt[0] == ' ' && prompt[1] != ' '); prompt++);
	prompt++;
	name = my_strcat_3(prompt);
	for (; !(prompt[0] == ' ' && prompt[1] != ' '); prompt++);
	prompt++;
	value = my_strcat_4(prompt);
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next) {
		if (my_strcmp(((*env_lst)->env_name), name) == 0) {
			replace_name_and_value(env_lst, name, value);
			return (0);
		}
	}
	if (my_strcmp((*env_lst)->env_name, name) == 0)
		replace_name_and_value(env_lst, name, value);
	else
		add_name_and_value_to_list(env_lst, name, value);
	return (0);
}

void add_name_and_value_to_list(env_t **env_lst, char *name, char *value)
{
	env_t *new_case = malloc(sizeof(env_t));

	if (!new_case)
		exit(84);
	new_case->next = NULL;
	new_case->env_name = my_strcpy(name);
	new_case->env_value = my_strcpy(value);
	(*env_lst)->next = new_case;
	new_case->prev = *env_lst;
	*env_lst = new_case;
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
}

void replace_name_and_value(env_t **env_lst, char *name, char *value)
{
	(*env_lst)->env_name = my_strcpy(name);
	(*env_lst)->env_value = my_strcpy(value);
	for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
}
