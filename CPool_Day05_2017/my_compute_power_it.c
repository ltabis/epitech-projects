/*
** EPITECH PROJECT, 2017
** my_compute_power_it.c
** File description:
** task03 Day05
*/

int my_computer_power_it(int nb, int p)
{
	int saveNbr = nb;
	int savePui;
	
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	if (p > 0) {
		while (p != 1) {
			nb = nb * saveNbr;  
			p--;	
		}
	}
	return (nb);
}
