/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** task02 Day04
*/
#include <unistd.h>

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
