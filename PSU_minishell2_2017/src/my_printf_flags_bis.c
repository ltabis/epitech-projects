/*
** EPITECH PROJECT, 2017
** my_printf_flags_bis.c
** File description:
** other functions for my_printf
*/
#include "../include/proto.h"
#include <stdarg.h>
#include <stdlib.h>

void d_s_maj(va_list ap)
{
	char *arg = va_arg(ap, char *);
	unsigned int i = 0;
	char oct[] = "000";
	unsigned int j = 0;
	unsigned char res = 0;

	for (; arg[i] != '\0'; i++) {
		if (arg[i] >= 32 && arg[i] <= 126)
			my_putchar(arg[i]);
		else if (arg[i] < 32 || arg[i] >= 127) {
			my_putchar(92);
			res = arg[i];
			for (; j < 3; j++, res = (res / 8))
				oct[j] = (res % 8) + 48;
			my_revstr(oct);
			my_putstr(oct);
		}
		j = 0;
	}
}

void d_o(va_list ap)
{
	unsigned int arg = va_arg(ap, unsigned int);
	unsigned int rest = arg;
	unsigned int size = 0;
	char *disp;

	for (; arg > 0; arg /= 8, size++);
	disp = malloc(sizeof(char) * (size + 1));
	if (!disp)
		return;
	for (size = 0, arg = rest; arg > 0; arg /= 8, size++) {
		rest = (arg % 8) + 48;
		disp[size] = rest;
	}
	disp[size] = '\0';
	my_revstr(disp);
	for (size = 0; disp[size] != '\0'; size++)
		my_putchar(disp[size]);
	free(disp);
}

void d_none(va_list ap)
{
	if (ap)
		my_putchar('%');
}

void d_u(va_list ap)
{
	unsigned int nb = (va_arg(ap, unsigned int));

	if (nb >= 10)
		my_put_nbr(nb / 10);
	my_putchar(nb % 10 + 48);
}

void d_adr(va_list ap)
{
	long long int arg = va_arg(ap, long long int);
	long long int rest = arg;
	unsigned int size = 0;
	char *disp;

	for (; arg > 0; arg = (arg / 16), size++);
	disp = malloc(sizeof(char) * (size + 1));
	for (size = 0, arg = rest; arg > 0; arg = (arg / 16), size++) {
		rest = arg % 16;
		if (rest >= 10)
			rest += 87;
		else
			rest += 48;
		disp[size] = rest;
	}
	disp[size] = '\0';
	for (my_putstr("0x"), my_revstr(disp), size = 0;
	disp[size] != '\0'; size++)
		my_putchar(disp[size]);
}
