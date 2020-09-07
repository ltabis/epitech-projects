/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** handling errors with env variables
*/

#include "my.h"

int check_env_variable(char **env)
{
	if (!env[0])
		return (-1);
	for (unsigned int i = 0; env[i]; i++)
		if (my_strncmp(env[i], "DISPLAY=:0",
		my_strlen("DISPLAY=:0")) == 0)
			return (0);
	return (-1);
}

void check_sprite_path(char *path)
{
	for (int i = 0; path[i] != '\0'; i++) {
		if (path[i] == '\n')
			path[i] = '\0';
	}
}
