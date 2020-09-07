/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** strlen function
*/

int my_strlen(char *str)
{
	unsigned int i = 0;

	for (; str[i] != 0; i++);
	return (i);
}
