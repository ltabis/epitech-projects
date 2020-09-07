/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** task02 Day04
*/

#include <unistd.h>
#include "../include/proto.h"

void my_puterr(char const *str)
{
	write(2, str, my_strlen(str));
}
