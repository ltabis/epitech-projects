/*
** EPITECH PROJECT, 2017
** 101pong.c
** File description:
** C file for 101pong project
*/
#include "include/my.h"
#include "include/proto.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void display_vector_speed(char **av)
{
        int a = 1;

	printf("The speed vector coordinates are :\n(");
	while (a != 4) {
		printf("%.2f", string_to_float(av[a + 3]) - string_to_float(av[a]));
		a++;
		if (a != 4)
			printf(";");
	}
	printf(")\n");
}

void display_time_shift(char **shift)
{
	int n = string_to_float(shift[7]) + 1;
	double i = 0;
	int a = 1;
        
	printf("At time t+%i, ball coordinates will be :\n(", n - 1);
	while (a != 4) {
		i = string_to_float(shift[a]);
		printf("%.2f", (string_to_float(shift[a + 3]) - string_to_float(shift[a])) * n + i);
		a++;
		if (a != 4)
			printf(";");
	}
	printf(")\n");
}

double string_to_float(char *av1)
{
	int b = 0;
	double nbr = 0;
	double coma = 1;
	double res;

	if (av1[0] == '-')
		b++;
	for (; av1[b] != '\0' && (av1[b] >= '0' && av1[b] <= '9'); b++) {
		nbr *= 10;
		nbr = nbr + (av1[b] - 48);
	}
	if (av1[b] == '.') {
		for (b++; av1[b] != '\0'; b++) {
			coma /= 10;
			res = (av1[b] - 48) * coma;
			nbr += res;
		}
	}
	if (av1[0] == '-')
		nbr = nbr * -1;
	return (nbr);
}
