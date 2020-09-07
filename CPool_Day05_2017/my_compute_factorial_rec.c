/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec.c
** File description:
** task02 Day05
*/

int my_compute_factorial_rec(int nb)
{
	if (nb == 0)
		return (1);
	if (nb > 0) {
	        if (nb >= 17) {
			return (0);
		} else {
			nb  = nb * my_compute_factorial_rec(nb - 1);
			return (nb);
		}
	}
}
