/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** file that contain error handling funciton
*/
#include <unistd.h>
#include <stdlib.h>
#include "../include/proto.h"

void my_perror_command(char *command)
{
	my_puterr(command);
	my_puterr(": Command not found.\n");
}

int check_alphanumeric_variable(char *str)
{
	for (; !(str[0] == ' ' && str[1] != ' ') && str[1] != 0; str++);
	str++;
	for (unsigned int i = 0; str[i] != 0 &&
		str[i] != ' ' && str[i] != '\t'; i++)
		if (str[i] != ' '  && str[i] != '\t' && (str[i] < 48 ||
		(str[i] > 57 && str[i] < 65) ||
		(str[i] > 90 && str[i] < 97) || str[i] > 122) &&
		str[i] != '_')
			return (i + 1);
	return (0);
}

char *transform_str(char *str)
{
	unsigned int size = 0;
	unsigned int words = 0;
	char *formated;

	if (!str)
		return (NULL);
	for (; str[0] == ' ' || str[0] == '\t'; str++);
	for (unsigned int i = 0; str[i] != 0; i++) {
		if (str[i] != ' ' && str[i] != '\t')
			size++;
		else if ((str[i] == ' ' &&
			str[i + 1] != ' ' && str[i + 1] != '\t') ||
			(str[i] == '\t' &&
			str[i + 1] != ' ' && str[i + 1] != '\t'))
			words++;
	}
	formated = organize_str(str, (size + words + 1));
	return (formated);
}

char *organize_str(char *str, int size)
{
	unsigned int j = 0;
	char *formated = malloc(sizeof(char) * size);

	if (!formated)
		exit(84);
	for (unsigned int i = 0; str[i] != 0; i++) {
		if (str[i] != ' ' && str[i] != '\t') {
			formated[j] = str[i];
			j++;
		}
		else if ((str[i] == ' ' &&
		str[i + 1] != ' ' && str[i + 1] != '\t') ||
		(str[i] == '\t' &&
		str[i + 1] != ' ' && str[i + 1] != '\t')) {
			formated[j] = ' ';
			j++;
		}
	}
	formated[j] = 0;
	return (formated);
}

void add_old_pwd(env_t **env_lst)
{
	char OLDPWD[256];
	int i = 0;

	getcwd(OLDPWD, sizeof(OLDPWD));
	for (; (*env_lst)->next != 0; *env_lst = (*env_lst)->next)
		if (my_strcmp((*env_lst)->env_name, "OLDPWD=") == 0) {
			i = 1;
			(*env_lst)->env_value = my_strcpy(OLDPWD);
		}
	if (i == 0)
		add_name_and_value_to_list(env_lst, "OLDPWD=", OLDPWD);
}
