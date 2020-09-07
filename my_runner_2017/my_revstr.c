/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** task03 Day06
*/

char *my_revstr(char *str)
{
	int i = 0;
	int count = 0;
	char save;

	while (str[i] != '\0')
		i++;
	while (count != i / 2) {
		save = str[count];
		str[count] = str[i - count - 1];
		str[i - count - 1] = save;
		count++;
	}
	return (str);
}
