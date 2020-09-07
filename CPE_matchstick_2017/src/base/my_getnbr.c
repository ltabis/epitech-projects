/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** task05 Day04
*/

int my_getnbr(char *str)
{
	int i = 0;
	int result = 0;
	int multi = 1;

	for (; str[i] == '+' || str[i] == '-'; i++)
		if (str[i] == '-')
			multi = multi * -1;
	for (; str[i] != '\0'; i++) {
		if (result >= 2147000000 || result <= -2147000000)
			return (0);
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (i != 0)
			result = result * 10 + (str[i] - 48);
		else
			result = result + (str[i] - 48);
	}
	return (result * multi);
}
