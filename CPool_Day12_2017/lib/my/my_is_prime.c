/*
** EPITECH PROJECT, 2017
** my_is_prime.c
** File description:
** task06 Day05
*/

int my_is_prime(int nb)
{
	int square;
	int a = 0;
	
	if (nb <= 1)
		return (0);
	if (nb >= 0) {
		while (nb != square) {
			a++;
			square = a * a;
			if (a > nb)
				return (1);
		}
		return (0);
	}	     
}
