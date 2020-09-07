/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** task05 Day04
*/

int my_getnbr(char const *str)
{
	int i = 0;
	int result = 0;
	int multi = 1;

	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			multi = multi * -1;
		i++;
	}
	while (str[i] != '\0') {
		if (result >= 1000000000 || result <= -1000000000)
			return (0);
		if (str[i] < '0' || str[i] > '9')
			return (result * multi);
		if (i != 0) 
			result = result * 10 + (str[i] - 48);
		else
			result = result + (str[i] - 48);
		i++;
	}
	return (result * multi);
}
