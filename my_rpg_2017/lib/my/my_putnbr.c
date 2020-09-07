/*
** EPITECH PROJECT, 2017
** my_putnbr
** File description:
** display a number
*/

#include "my.h"

int my_putnbr(int nb)
{
	if (nb < 0){
		my_putchar ('-');
		nb = nb*-1;
	}
	if (nb >= 10){
		my_putnbr(nb/10);
	}
	my_putchar((nb%10)+48);
	return (0);
}
