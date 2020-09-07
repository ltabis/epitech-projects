/*
** EPITECH PROJECT, 2018
** handling_memory.c
** File description:
** file that will ocntain function that will handle the memory
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/proto.h"

void free_env_variable(env_t **env_lst)
{
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next) {
		free((*env_lst)->env_name);
		free((*env_lst)->env_value);
		free((*env_lst)->prev);
	}
	free((*env_lst)->env_name);
	free((*env_lst)->env_value);
	free((*env_lst)->prev);
	free((*env_lst)->next);
}

char **free_path_variable(char **path_v)
{
	for (unsigned int i = 0; path_v[i] != 0; i++)
		free(path_v[i]);
	return (path_v);
}

void allocate_memory_env_name(env_t **new_case, int i)
{
	(*new_case)->env_name = malloc(sizeof(char) * (i + 2));
	if (!(*new_case)->env_name)
		exit(84);
}

void allocate_memory_env_value(env_t **new_case, int i)
{
	(*new_case)->env_value = malloc(sizeof(char) * (i + 2));
	if (!(*new_case)->env_value)
		exit(84);
}

int check_file_stat(char *path)
{
	int ret = access(path, R_OK);
	struct stat file;

	stat(path, &file);
	if (ret == -1 && S_ISDIR(file.st_mode)) {
		write(2, path, my_strlen(path));
		write(2, ": Permission denied.\n", 21);
		return (0);
	}
	return (1);
}
