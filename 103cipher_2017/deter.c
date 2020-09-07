/*
** EPITECH PROJECT, 2017
** deter.c
** File description:
** calculs for the determinant
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/proto.h"
#include "include/my.h"

int main(int ac, char **av)
{
	error_handling(ac, av);
	if (atoi(av[3]) == 0)
		do_encryption(av[1], av[2]);
	else
		do_decipherment(av[1], av[2]);
	return (0);
}

void error_handling(int ac, char **av)
{
	if (ac != 4)
        	exit(84);
        if (strlen(av[1]) == 0 || strlen(av[2]) == 0)
	        exit(84);
        if (atoi(av[3]) != 1 && atoi(av[3]) != 0)
		exit(84);
}
