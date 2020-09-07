/*
** EPITECH PROJECT, 2017
** my_memset.c
** File description:
** a function that replace a string with a given byte, on a given size
*/
#include "include/my.h"

char *my_memset(char *str, char cst , int size)
{
	int i = 0;

	while (i < size) {
		str[i] = cst;
		i++;
	}
	return (str);
}
