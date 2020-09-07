/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for infinadd
*/
#include "my.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		write(2, "84 error code : bad input\n", 26); 
		return (84);
	}
	if (argv[1][0] == '\0') {
		write(2, "84 error code : no digits were found\n", 37); 
		return (84);
        }
	number(argv);
	return (0); 
}
