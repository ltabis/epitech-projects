/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** task07 Day03
*/
#include "base.h"

void my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		my_put_nbr(nb / 10);
	my_putchar(nb % 10 + 48);
}
