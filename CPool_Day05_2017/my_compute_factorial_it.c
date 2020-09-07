/*
** EPITECH PROJECT, 2017
** my_compute_factorial_it.c
** File description:
** task01 Day05
*/

int my_compute_factorial_it(int nb)
{
	int count = nb - 1;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb > 0) {
		while (count != 0) {
			if (count == 16)
				return (0);
			nb = nb * count;
			count--;
	        }
		return (nb);
	}
}
