/*
** EPITECH PROJECT, 2017
** my_show_word_array.c
** File description:
** task03 Day08
*/

int my_show_word_array(char * const *tab)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int lim;
	
	while (tab[lim] != '\0')
		lim++;
	while (i != lim) {
		j = 0;
		while (tab[i][j] != '\0' && i != lim) {
			my_putchar(tab[i][j]);
			j++;
		}
		if (i != lim)
			my_putchar('\n');
		i++;
	}
}
