/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** task05 Day04
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_getnbr(char *str)
{
	unsigned int i = 0;
	unsigned int b = 0;

	while (str[i] != 0) {
		if (str[i] >= '0' && str[i] <= '9')
			b = b * 10 + (str[i++] - 48);
		else
			i++;
	}
	b *= (str[0] == '-' ? -1 : 1);
	return (b);
}

int my_getnbr_no_char(char *str)
{
	unsigned int i = 0;
	unsigned int b = 0;

	while (str[i] != 0) {
		if (str[i] >= '0' && str[i] <= '9')
			b = b * 10 + (str[i++] - 48);
		else {
			write(2, "Invalid parameter\n", 18);
			return (-1);
		}
	}
	return (b);
}