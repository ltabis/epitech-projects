/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** print
*/
#include <unistd.h>

int my_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
