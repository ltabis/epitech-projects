/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for the 101pong project
*/
#include "include/my.h"
#include "include/proto.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(int argc, char **argv)
{
	int c = 0;
	
	if (argc != 8) {
		write(2, "wrong input\n", 12);
		return (84);
	} else {
		c = do_101pong(argv);
		if (c == 84)
			return (84);
		else if (c != 84)
			return (0);
	}
}

int do_101pong(char **av)
{
	int match = count_matches(av);
	int a = 0;
	int b = 0;
	int size = 0;

	for (; av[a] != 0; a++) {
		for (b = 0; av[a][b] != '\0'; b++)
			size++;
		size--;
	}
	size--;
	if (match != size) {
		write(2, "invalid expression\n", 19);
		return (84);
	} else {
		display_vector_speed(av);
		display_time_shift(av);
		verify_bat(av);
		return (0);
	}
}

int count_matches(char **av)
{
	int a = 1;
	int b = 0;
	int match = 0;

	for (; av[a] != 0; a++) {
		for (b = 0; av[a][b] != '\0'; b++) {
			if (av[a][b] >= '0' && av[a][b] <= '9')
				match++;
			else if (av[a][b] == '.' || av[a][b] == '-')
				match++;
		}
	}
	return (match);
}

void verify_bat(char **av)
{
	double n = string_to_float(av[7]) + 1;
	double i = string_to_float(av[3]);
	double j = string_to_float(av[6]);
	int a = 1;

	if ((((j - i) * n + i) > 0 && j > 0) || (((j - i) * n + i) < 0 && j < 0))
		printf("The ball won't reach the bat.\n");
	else if ((((j - i) * n + i) < 0 && j > 0) || (((j - i) * n + i) > 0 && j < 0)) {
		n = (string_to_float(av[a + 3]) - 48) - (string_to_float(av[a]) - 48);
		a++;
		i = (string_to_float(av[a + 3]) - 48) - (string_to_float(av[a]) - 48);
		a++;
		j = (string_to_float(av[a + 3]) - 48) - (string_to_float(av[a]) - 48);
		n = sqrt(n * n + i * i + j * j);
		i = 90 - (acos(-(string_to_float(av[6]) - string_to_float(av[3])) / n)) * 180 / PI;
		if (i < 0)
			i *= -1;
		else if (i == 0)
			printf("The ball won't reach the bat.\n");
		else if (i > 0){
			printf("The incidence angle is :\n");
			printf("%0.2f degrees\n", i);
		}
	}
}
