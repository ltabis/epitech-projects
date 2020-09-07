/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** return a number given as string
*/

int my_getnbr(char const *str)
{
	int i = 0;
	int result = 0;
	int counter = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') {
			counter++;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + (str[i] - '0');
		if (result * 10 > 2147000000 || result * 10 < -2147000000)
			return (0);
		i++;
	}
	if (counter % 2 != 0)
		result = result * -1;
	return (result);
}
