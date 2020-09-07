/*
** EPITECH PROJECT, 2017
** my_compute_square_root.c
** File description:
** task05 Day05
*/

int my_compute_square_root(int nb)
{
	int a = -1;
	int square;

	if (nb < 0) 
		return (0);
	if (nb >= 0) {
		while (nb != square) {
			a++;
			square = a * a;
			if (a > nb)
				return (0);
		}
		return (a);
	}
}
