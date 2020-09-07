/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** task03 Day04
*/

int my_strlen(char const *str)
{
	int i = 0;
	
	while (str[i] != '\0') {
	        i++;
        }
	return (i);
}

