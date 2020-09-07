/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** string len
*/

unsigned int my_strlen(const char *str)
{
	unsigned int i = 0;

	for (; str[i]; i++);
	return (i);
}
