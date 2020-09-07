/*
** EPITECH PROJECT, 2018
** my_put_score
** File description:
** my_put_score
*/

#include "tetris.h"

int count_len(int nb)
{
	int count = 0;
	int tmp = nb;

	if (nb < 0) {
		count++;
		nb *= -1;
		tmp *= -1;
	}
	while (tmp > 10) {
		tmp /= 10;
		count++;
	}
	if (tmp == 10)
		count++;
	count++;
	return (count);
}

char *fill_str(char *str, int i, int nb, int tmp)
{
	int tmp2 = nb;

	if (tmp2 < 0)
		tmp2 *= -1;
	for (; tmp2 > 10; i--) {
		tmp = tmp2;
		str[i] = tmp % 10 + '0';
		tmp2 /= 10;
	}
	if (tmp == 100 || tmp == 0) {
		if (nb < 0)
			str[1] = '1';
		else if (nb != 0) {
			str[0] = '1';
		}
	}
	else
		str[i] = tmp2 % 10 + '0';
	return (str);
}


char *my_put_score(int nb)
{
	int i = 0;
	int tmp = 0;
	int len = count_len(nb);
	char *str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (NULL);
	str[len] = 0;
	for (int j = 0; j < len; j++)
		str[j] = '0';
	i = my_strlen(str) - 1;
	if (nb < 0) {
		str[0] = '-';
		//nb *= -1;
	}
	str = fill_str(str, i, nb, tmp);
	return (str);
}
