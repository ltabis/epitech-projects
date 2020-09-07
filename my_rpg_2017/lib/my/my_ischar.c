/*
** EPITECH PROJECT, 2018
** my_ischar.c
** File description:
** if charactere is a letter or not
*/

int my_ischar(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
