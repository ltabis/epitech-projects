/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01 Day06
*/

char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (dest[i] != '\n') {
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
