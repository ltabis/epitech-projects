/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** transform strings into numbers
*/

#include <stdio.h>

int my_getnbr(const char *str, const unsigned int len_str,
	unsigned int value_len, unsigned int ptr)
{
	int value = 0;
	int power = 1;

	for (unsigned int i = 1; i < value_len; i++)
		power *= 10;
	value = (str[ptr] - 48) * power;
	if (ptr < len_str) {
		value += my_getnbr(str, len_str, value_len - 1, ptr + 1);
		return (value);
	}
	return (0);
}
