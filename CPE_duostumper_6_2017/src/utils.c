/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utility functions
*/

int my_strlen(char const *str)
{
	int i = 0;

	for (; str && str[i] && str[i] != '\n'; i++);
	return (str ? i : -1);
}
