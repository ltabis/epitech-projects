/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for infinadd
*/
#include "../include/my.h"
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2) {
		my_put_nbr(yard(av[1]));
		my_putchar('\n');
		return (0);
	}
	return (84); 
}
