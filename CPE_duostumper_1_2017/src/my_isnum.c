/*
** EPITECH PROJECT, 2018
** my_isnum.c
** File description:
** checking if parameter 1 is number
*/

int my_isnum(char *str)
{
	unsigned int i = 0;

	for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++);
	return (str[i] && (str[i] < '0' || str[i] > '9') ? -1 : 0);
}