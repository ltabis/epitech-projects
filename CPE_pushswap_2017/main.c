/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for the pushswap project
*/
#include "include/my.h"
#include "include/proto.h"

int main(int argc, char **argv)
{
	unsigned int a = 1;
	unsigned int b = 0;
	unsigned int option = 0;

	if (argv[1][0] == '-' && argv[1][1] == 'v') {
		a++;
		option = 1;
	}
	for (; argv[a] != 0; a++, b = 0) {
		if (argv[a][0] == '-')
			b++;
		for (; argv[a][b] != '\0' &&
		(argv[a][b] >= '0' && argv[a][b] <= '9'); b++);
		if (argv[a][b] != '\0')
			return (84);
	}
	push_swap(argc, argv, option);
	return (0);
}
