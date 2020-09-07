/*
** EPITECH PROJECT, 2017
** tree.c
** File description:
** Project Semaine01
*/

void tree(int size)
{
	int premiere_etoile = size * (4 + size) / 2;
	int count = 0;
	int feuilles = 1;
	int feuilles_base = 4;
	int a = 1;
	int count_paliers = size - 2;
	int b = 2;
	int c = 2;
	int size_save = size;
	
	while(size > 0) {
		for (feuilles; feuilles <= feuilles_base; feuilles++) {
			while (count != premiere_etoile) {
				my_putchar(' ');
				count++;
			}
			count = 0;
			premiere_etoile--;
			while (count != a) {
				my_putchar('*');
				count++;
			}
			my_putchar('\n');
			count = 0;
			a = a + 2;
		}
		if (size == count_paliers) {
			b++;
			premiere_etoile = premiere_etoile + b;
			feuilles = 1;
			feuilles_base++;
			size--;
			c++;
			a = a - (b + c);
			count_paliers = count_paliers - 2;
		} else {
			premiere_etoile = premiere_etoile + b;
			feuilles = 1;
			feuilles_base++;
			size--;
			a = a - (b + c);
		}
	}
	build_trunk(size_save);
}

int build_trunk(int size_save)
{
	int count = 0;
	int count_total = 0;
	int premier_tronc = (size_save * (4 + size_save) / 2) - size_save / 2;;
	int barres = 0;
        
	while (count_total != size_save) {
		
		while (count != premier_tronc) {
			my_putchar(' ');
			count++;
		}
		while (barres != size_save) {
			my_putchar('|');
			barres++;
		}
		barres = 0;
		count = 0;
		count_total++;
		my_putchar('\n');
	}
}
