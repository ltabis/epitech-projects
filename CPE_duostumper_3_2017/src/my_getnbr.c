/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** geting number from string
*/

#include "../include/proto.h"

int my_getnbr(const char *str, int decal)
{
	int nbr = 0;
	int mul = 1;
	unsigned int len = my_strlen(str);

	if (str[decal]) {
		for (unsigned int i = 0; i < (len - decal - 1); i++)
			mul *= 10;
		nbr = (str[decal] - 48) * mul;
		nbr += my_getnbr(str, decal + 1);
		return (nbr);
	}
	return (0);
}
