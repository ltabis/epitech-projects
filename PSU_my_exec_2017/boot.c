/*
** EPITECH PROJECT, 2018
** boot.c
** File description:
** bootstrap for minishell1 project
*/
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *filepath;
	unsigned int i = 0;
	unsigned int j = 0;

	if (ac != 2)
		return (84);
	for (; av[1][i] != ' ' && av[1][i] != '\0'; i++);
	filepath = malloc(sizeof(char) * i + 1);
	for (; j < i; j++)
		filepath[j] = av[1][j];
	filepath[j] = '\0';
	return (0);
}
