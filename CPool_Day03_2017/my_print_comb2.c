/*
** EPITECH PROJECT, 2017
** my_print_comb2.c
** File description:
** task06 Day03
*/

int my_print_comb2(void)
{
	int var1='0';
	int var2='0';
	int var3='0';
	int var4='0';
	int var11 = var1 + var2;
	int var22 = var3 + var4;

	while (var1 <= '9') {
		while (var2 <= '8') {
		        while (var3 <= '9') {
		        	my_affichage(var1, var2, var3, var4, var11, var22);
				var3++;
			}
			var3='0';
			var2++;
		}
		var2='0';
		var1++;
	}
}

int my_affichage(var1, var2, var3, var4, var11, var22)
{
	while (var4 <= '9') {
		if (!(var11 >= var22)) {
			my_putchar(var1);
			my_putchar(var2);
			my_putchar(' ');
			my_putchar(var3);
			my_putchar(var4);
			my_putchar(',');
			my_putchar(' ');
	        }
		var4++;
	}
	var4='0';
}
