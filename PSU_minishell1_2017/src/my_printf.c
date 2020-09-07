/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my_printf file for my_printf project
*/
#include <stdarg.h>
#include <stdlib.h>
#include "../include/proto.h"

void my_printf(char *str, ...)
{
	int b = 0;
	va_list ap;
	void (*chooseFlag[16])(va_list) = {d_i, d_i, d_c, d_s, d_8,
	d_ex_up, d_o, d_S, d_none, d_u, d_adr, d_b, d_4, d_6, d_8, d_ascii};
	va_start(ap, str);
	while (b < my_strlen(str)) {
		if (str[b] == '%') {
			b++;
			if (find_flag(str, b) == 84)
				my_putchar('%');
			else {
				(*chooseFlag[find_flag(str, b)])(ap);
				b++;
			}
		} else if (str[b] != '%') {
			my_putchar(str[b]);
			b++;
		}
	}
	va_end(ap);
}

int find_flag(char *str, int b)
{
	char flags_test[] = "idcsxXoS%upb468z";
	int i = 0;

	while (str[b] != flags_test[i] && flags_test[i] != '\0')
		i++;
	if (flags_test[i] == '\0')
		return (84);
	return (i);
}

void d_b(va_list ap)
{
	unsigned int arg = va_arg(ap, unsigned int);
	unsigned int rest = arg;
	unsigned int size = 0;
	char *disp;

	for (; arg > 0; arg /= 2, size++);
	disp = malloc(sizeof(char) * (size + 1));
	if (disp == NULL)
		exit(84);
	for (size = 0, arg = rest; arg > 0; arg /= 2, size++) {
		rest = (arg % 2) + 48;
		disp[size] = rest;
	}
	disp[size] = '\0';
	my_revstr(disp);
	for (size = 0; disp[size] != '\0'; size++)
		my_putchar(disp[size]);
	free(disp);
}
