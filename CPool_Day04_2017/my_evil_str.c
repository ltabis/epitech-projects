/*
** EPITECH PROJECT, 2017
** my_evil_str.c
** File description:
** task04 Day04
*/

char *my_evil_str(char *str)
{
	int i = 0;
	
	while (str[i] != '\0') {
		i++;
	}
	while (i > 0) {
		i--;
	}
	return (str);
}
