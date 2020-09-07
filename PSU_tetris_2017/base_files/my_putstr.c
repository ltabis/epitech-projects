/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** display a string
*/
#include <unistd.h>
#include "base.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
