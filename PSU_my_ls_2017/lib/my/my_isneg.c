/*
** EPITECH PROJECT, 2017
** my_isneg.c
** File description:
** task04 Day03
*/
#include "../../include/my.h"

int my_isneg(int n)
{
	if (n < 0) {
		my_putchar('N');
	} else {
		my_putchar('P');
	}
}
