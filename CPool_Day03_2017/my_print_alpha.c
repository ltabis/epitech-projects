/*
** EPITECH PROJECT, 2017
** my_print_alpha.c
** File description:
** task01 Day03
*/

int my_print_alpha(void)
{
	char alpha;

	alpha = 97;
	while (alpha != 123) {
		my_putchar(alpha);
		alpha++;
	}
}
