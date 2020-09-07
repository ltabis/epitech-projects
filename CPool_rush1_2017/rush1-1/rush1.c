/*
** EPITECH PROJECT, 2017
** rush1.c
** File description:
** rush01 week01
*/

void rush(int x, int y)
{
        int count = 1;

	if (x <= 0 || y <= 0) {
		write(2, "Invalid size\n", 13);
	} else {	
		my_create_x(x, count);
		my_putchar('\n');
		while (y > 2) {
			my_create_y(x, count);
			y--;
		}
		if (y == 2) {
			my_create_x(x, count);
			my_putchar('\n');
		}
	}
}

int my_create_x(int x, int count)
{
        if (x > 0) {
                while (count != x) {
                        if (count == 1)
                                my_putchar('o');
			else
				my_putchar('-');
                        count++;
                }
		my_putchar('o');
        }
        count = 0;
}

int my_create_y(int x, int count)
{
        while (count != x) {
                if (count == 1) 
                        my_putchar('|');
		else 
			my_putchar(' ');
		count++;
	}
	if (count == x) {
		my_putchar('|');
		my_putchar('\n');
		count = 1;
	}
}

int my_display_error(void)
{
	char str[14] = "Invalid size";
        int i = 0;

	while (i != 13) {
		my_putchar(str[i]);
		i++;
	}
	my_putchar('\n');
	return (0);
}
