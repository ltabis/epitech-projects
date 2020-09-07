/*
** EPITECH PROJECT, 2017
** my_print_comb.c
** File description:
** task05 Day03
*/

int my_print_comb(void)
{
	int var1=48;
	int var2=49;
	int var3=50;

	while (var1<=55) {
		while (var2<=56) {
			my_display(var1, var2, var3);
			var3=48;
			var2++;
		}
		var2=48;
		var1++;
	}	
}

int my_display(var1, var2, var3)
{
	while (var3<=57) {
		if (var1 == 55 && var2 == 56 && var3 == 57) {
			my_putchar(var1);
			my_putchar(var2);
			my_putchar(var3);
			break;
		}
		else if (var1 == var2 || var1 == var3 || var2 == var3 || var1 >= var2 || var2 >= var3) {
			var3++;
		} else {
			my_putchar(var1);
			my_putchar(var2);
			my_putchar(var3);
			my_putchar(',');
			my_putchar(' ');
			var3++;
		} 	
	}
}
