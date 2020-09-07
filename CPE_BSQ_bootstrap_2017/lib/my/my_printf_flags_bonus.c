/*
** EPITECH PROJECT, 2017
** my_printf_flags_bonus.c
** File description:
** bonuses for the my_printf project
*/
#include <stdarg.h>
#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/proto.h"

void d_4(char *str, va_list ap)
{
	unsigned int arg = va_arg(ap, unsigned int);
	unsigned int rest = arg;
	unsigned int size = 0;
	char *disp;

	for (; arg > 0; arg /= 4, size++);
	disp = malloc(sizeof(char) * (size + 1));
	if (disp == NULL)
		exit(84);
	for (size = 0, arg = rest; arg > 0; arg /= 4, size++) {
		rest = (arg % 4) + 48;
		disp[size] = rest;
	}
	disp[size] = '\0';
	my_revstr(disp);
	for (size = 0; disp[size] != '\0'; size++)
		my_putchar(disp[size]);
	free(disp);
}

void d_6(char *str, va_list ap)
{
	unsigned int arg = va_arg(ap, unsigned int);
	unsigned int rest = arg;
	unsigned int size = 0;
	char *disp;

	for (; arg > 0; arg /= 6, size++);
	disp = malloc(sizeof(char) * (size + 1));
	if (disp == NULL)
		exit(84);
	for (size = 0, arg = rest; arg > 0; arg /= 6, size++) {
		rest = (arg % 6) + 48;
		disp[size] = rest;
	}
	disp[size] = '\0';
	my_revstr(disp);
	for (size = 0; disp[size] != '\0'; size++)
		my_putchar(disp[size]);
	free(disp);
}

void d_8(char *str, va_list ap)
{
	unsigned int arg = va_arg(ap, unsigned int);
	unsigned int rest = arg;
	unsigned int size = 0;
	char *disp;

	for (; arg > 0; arg /= 8, size++);
	disp = malloc(sizeof(char) * (size + 1));
	if (disp == NULL)
		exit(84);
	for (size = 0, arg = rest; arg > 0; arg /= 8, size++) {
		rest = (arg % 8) + 48;
		disp[size] = rest;
	}
	disp[size] = '\0';
	my_revstr(disp);
	for (size = 0; disp[size] != '\0'; size++)
		my_putchar(disp[size]);
}

void d_ascii(char *str, va_list ap)
{
	unsigned int i = 33;

	my_printf("char          decimal           hex               oct\n");
	my_printf("-----------------------------------------------------\n");
	for (; i != 127; i++) {
		if (i >= 100) {
			my_printf("%c             %i                %X                %o\n",
				(char)i, i, i, i);
		} else {
			my_printf("%c             %i                 %X                %o\n",
				(char)i, i, i, i);
		}
	}
}
