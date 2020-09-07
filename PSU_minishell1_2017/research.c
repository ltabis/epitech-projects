/*
** EPITECH PROJECT, 2018
** research.c
** File description:
** file that will taker care of the progam research
*/
#include "include/proto.h"
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

void search_exec(char *command, char **PATH, env_t *env_lst)
{
	char **args = build_args(command);
	char *filepath;
	unsigned int i = 0;
	int ret;

	if (!args)
		return;
	filepath = my_strcpy(args[0]);
	ret = access(filepath, F_OK);
	for (; PATH[i] != 0 && ret != 0; i++) {
		filepath = my_strcat_2(PATH[i], args[0]);
		ret = access(filepath, F_OK);
	}
	if (ret == 0) {
		args[0] = my_strcpy(filepath);
		start_forking(args, env_lst);
	} else
		my_perror_command(args[0]);
	args = free_path_variable(args);
	for(int i = 0; i != 1; free(args), free(filepath), i = 1);
}

char **build_args(char *command)
{
	char **args;
	unsigned int nb_args = 1;

	for (unsigned int i = 0; command[i] != 0; i++)
		if (command[i] != ' ' && command[i] != ' ' && i != 0)
			nb_args++;
	args = malloc(sizeof(char *) * (nb_args + 1));
	if (!args)
		exit(84);
	args = copy_args(command, args, nb_args);
	return (args);
}

char **copy_args(char *command, char **args, unsigned int nb_args)
{
	unsigned int index = 0;
	unsigned int i = 0;

	for (; i < nb_args && command[index] != 0; i++)
		args[i] = copy_string_args(command, args[i], &index);
	args[i] = NULL;
	return (args);
}

char *copy_string_args(char *command, char *args, unsigned int *index)
{
	unsigned int i = 0;

	for (i = *index; command[i] != ' ' && command[i] != 0; i++);
	args = malloc(sizeof(char) * (i - *index + 1));
	if (!args)
		exit(84);
	for (i = 0; command[*index] != ' ' &&
	command[*index] != 0; i++, (*index)++)
		args[i] = command[*index];
	while (command[*index] == ' ')
		(*index)++;
	args[i] = 0;
	return (args);
}
