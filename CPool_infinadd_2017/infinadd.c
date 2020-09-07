/*
** EPITECH PROJECT, 2017
** infinadd.c
** File description:
** project 1 week04
*/
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int verify_len(int ac, char **av)
{
	int len1;
	int len2;
	int i = 0;

	len1 = my_strlen(av[1]);
	len2 = my_strlen(av[2]);
	if (len1 > len2)
		i = len1;
	else if (len1 < len2)
		i = len2;
	else {
		if (av[1][0] + av[2][0] >= 10)
			i = len1 + 1;
		else
			i = len1;
	}
	return (i + 1);
}

char *finish_number(char *add, char **argv, int retenue, int i)
{
	int i_save = i;
	
	if (argv[1][i] == '\0') {
		for (i; argv[2][i] != '\0'; i++) {
			if (((argv[2][i] - 48) + retenue) >= 10) {
				add[i] = (((argv[2][i] - 48) + retenue) % 10) + 48;
				retenue = 1;
			} else {
				add[i] = ((argv[2][i] - 48) + retenue) + 48;
				retenue = 0;
			}
		}
	} else if (argv[2][i] == '\0') {
		for (i; argv[1][i] != '\0'; i++) {
			if (((argv[1][i] - 48) + retenue) >= 10) {
				add[i] = (((argv[1][i] - 48) + retenue) % 10) + 48;
				retenue = 1;
			} else {
				add[i] = ((argv[1][i] - 48) + retenue) + 48;
				retenue = 0;
			}
		}
	}
	if (((argv[1][i_save] == '\0' && argv[2][i] == '\0') || (argv[1][i] == '\0' && argv[2][i_save] == '\0')) && retenue == 1)
		add[i] = '1';
        return (add);
}

int verify_all_cases(int argc, char **argv)
{
	int count = 0;
	
	if (!(argc == 3)) {
		write(2, "84 error code : bad input\n", 26);
		return (84);
	} else {
		for (count = 0; argv[1][count] != '\0'; count++) {
			if (argv[1][count] < '0' || argv[1][count] > '9') { 
				write(2, "84 error code : bad input\n", 26);
				return (84);
			}
		}
		for (count = 0; argv[2][count] != '\0'; count++) {
			if (argv[2][count] < '0' || argv[2][count] > '9') {
				write(2, "84 error code : bad input\n", 26);
				return (84);
			}
		}
	}
	return (0);
}

int infinadd(int argc, char **argv)
{
	int len_str;
	int i = 0;
	int retenue = 0;
	char *add;

	if (verify_all_cases(argc, argv) == 84)
		return (84);
	len_str = verify_len(argc, argv);
	my_revstr(argv[1]);
	my_revstr(argv[2]);
	add = malloc(sizeof(char) * (len_str + 1));
	while (argv[1][i] != '\0' && argv[2][i] != '\0') {
		if ((((argv[1][i] - 48) + (argv[2][i] - 48)) + retenue) >= 10) {
			add[i] = (((argv[1][i] - 48) + (argv[2][i] - 48) + retenue) % 10) + 48;
			retenue = 1;
		}
		if ((((argv[1][i] - 48) + (argv[2][i] - 48)) + retenue) < 10) {
			add[i] = ((argv[1][i] - 48) + (argv[2][i] - 48) + retenue) + 48; 
			retenue = 0;
		}
		i++;
	}
	if (my_strlen(argv[1]) == my_strlen(argv[2]) && retenue == 1)
		add[i] = '1';
	add = finish_number(add, argv, retenue, i);
	my_revstr(add);
	for (i = 0; add[i] == '0'; i++);
        my_putstr(&add[i]);
	my_putchar('\n');
	free(add);
	return (0);
}
