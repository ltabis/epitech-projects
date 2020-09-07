/*
** EPITECH PROJECT, 2017
** my_print_revalpha.c
** File description:
** task02 Day03
*/

int my_print_revalpha(void)
{
	char revalpha;

	revalpha = 122;
	while (revalpha != 96) {
		my_putchar(revalpha);
		revalpha--;
	}
}
