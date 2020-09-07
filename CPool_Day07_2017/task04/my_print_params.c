/*
** EPITECH PROJECT, 2017
** my_print_params.c
** File description:
** task04 Day07
*/

int main(int argc, char **argv)
{
	int count = 0;
	
	while (count != argc) {
		my_putstr(argv[count]);
		my_putchar('\n');
		count++;
	}
	return (0);
}
