/*
** EPITECH PROJECT, 2017
** my_printf_flags.c
** File description:
** operators for my_printf function
*/
#include "../../include/my.h"
#include "../../include/proto.h"
#include <stdarg.h>
#include <stdlib.h>

void d_i(char *str, va_list ap)
{
	int nbr = va_arg(ap, int);
	unsigned int verif = nbr;

	if (verif == 2147483648)
		my_putstr("-2147483648");
	else if (verif != 2147483648)
		my_put_nbr(nbr);
}

void d_c(char *str, va_list ap)
{
	char ch = (char)va_arg(ap, int);

	my_putchar(ch);
}

void d_s(char *str, va_list ap)
{
	my_putstr(va_arg(ap, char *));
}

void d_ex(char *str, va_list ap)
{
	unsigned int arg = va_arg(ap, unsigned int);
	unsigned int rest = arg;
	unsigned int size = 0;
	char *disp;

	for (; arg > 0; arg = (arg / 16), size++);
	disp = malloc(sizeof(char) * (size + 1));
	if (disp == NULL)
		exit(84);
	for (size = 0, arg = rest; arg > 0; arg = (arg / 16), size++) {
		rest = arg % 16;
		if (rest >= 10)
			rest += 87;
		else
			rest += 48;
		disp[size] = rest;
	}
	disp[size] = '\0';
	for (my_revstr(disp), size = 0; disp[size] != '\0'; size++)
		my_putchar(disp[size]);
}

void d_ex_up(char *str, va_list ap)
{
	unsigned int arg = va_arg(ap, unsigned int);
	unsigned int rest = arg;
	unsigned int size = 0;
	char *disp;

	for (; arg > 0; arg = (arg / 16), size++);
	disp = malloc(sizeof(char) * (size + 1));
	if (disp == NULL)
		exit(84);
	for (size = 0, arg = rest; arg > 0; arg = (arg / 16), size++) {
		rest = arg % 16;
		if (rest >= 10)
			rest += 55;
		else
			rest += 48;
		disp[size] = rest;
	}
	disp[size] = '\0';
	for (my_revstr(disp), size = 0; disp[size] != '\0'; size++)
		my_putchar(disp[size]);
}
