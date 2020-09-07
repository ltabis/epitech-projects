/*
** EPITECH PROJECT, 2018
** my_strlen/c
** File description:
** len.c
*/

unsigned int my_strlen(char *str)
{
	unsigned int i = 0;

	for (; str[i]; i++);
	return (i);
}
