/*
** EPITECH PROJECT, 2017
** my_isdigit.c
** File description:
** return 1 if the character given in argument is a digit
*/

int my_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
