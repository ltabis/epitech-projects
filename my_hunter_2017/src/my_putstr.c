/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** task02 Day04
*/
#include "../include/proto.h"

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
