/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** task03 Day06
*/

char *my_revstr(char *str)
{
	unsigned int i = 0;

	for (; str[i] != '\0'; i++);
	for (unsigned int count = 0; count != i / 2; count++) {
		char save = str[count];
		str[count] = str[i - count - 1];
		str[i - count - 1] = save;
	}
	return (str);
}
