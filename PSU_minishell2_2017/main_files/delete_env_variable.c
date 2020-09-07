/*
** EPITECH PROJECT, 2018
** delete_env_variable.c
** File description:
** delete env variable
*/
#include <stdlib.h>
#include "../include/proto.h"

void delete_env_variables(env_t **env_lst, char *prompt)
{
	for (char *s = NULL ; prompt[0] != 0; prompt++) {
		if (prompt[0] == ' ' && prompt[1] != ' ') {
			prompt++;
			s = my_strcpy_special(prompt);
			delete_variable(env_lst, s);
			free(s);
		}
		for (; (*env_lst)->prev != 0; *env_lst = (*env_lst)->prev);
		*env_lst = (*env_lst)->next;
	}
}

void delete_variable(env_t **env_lst, char *name)
{
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next) {
		if (my_strcmp_env((*env_lst)->env_name, name) == 0)
			found_variable_to_delete(env_lst);
	}
	if (my_strcmp_env((*env_lst)->env_name, name) == 0)
		found_variable_to_delete(env_lst);
}

void found_variable_to_delete(env_t **env_lst)
{
	free((*env_lst)->env_name);
	free((*env_lst)->env_value);
	if ((*env_lst)->next == 0 && (*env_lst)->prev != 0) {
		*env_lst = (*env_lst)->prev;
		free((*env_lst)->next);
		(*env_lst)->next = 0;
	} else if ((*env_lst)->prev == 0 && (*env_lst)->next != 0) {
		*env_lst = (*env_lst)->next;
		free((*env_lst)->prev);
		(*env_lst)->prev = 0;
	} else if ((*env_lst)->prev != 0 && (*env_lst)->next != 0)
		variable_in_middle_of_list(env_lst);
}

void variable_in_middle_of_list(env_t **env_lst)
{
	env_t *tmp = malloc(sizeof(env_t));

	if (!tmp)
		exit(84);
	tmp = (*env_lst)->next;
	*env_lst = (*env_lst)->prev;
	(*env_lst)->next = tmp;
	tmp->prev = *env_lst;
}
