/*
** EPITECH PROJECT, 2017
** my_stdarg.c
** File description:
** stargc for boostrap of my_printf
*/
#include <stdarg.h>
#include <stdio.h>

int sum_stdarg(int i, int nb, ...)
{
	int a = 0;
	int b = 0;
	int c = 0;
	va_list ap;

	va_start(ap, nb);
	if (i == 0) {
		for (; a >= 0 && c != nb + 1; a = va_arg(ap, int), c++)
			b = b + a;
		va_end(ap);
	} else if (i == 1) {
		for (c = 1; a >= 0 && c != nb + 1; a = va_arg(ap, int)) {
			while (c < a) {
				c *= 10;
				b++;
			}
			c = 1;
		}
		va_end(ap);
		return (0);
	} else {
		va_end(ap);
		return (84);
	}
	return (0);
}

int main(void)
{
	sum_stdarg(1, 3, 2, 1, 16);
	return (0);
}
