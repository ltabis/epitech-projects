/*
** EPITECH PROJECT, 2017
** my_rev_params.c
** File description:
** task05 Day07
*/

int main(int argc, char **argv)
{
	int count = argc - 1;
	
	while (count >= 0) {
		my_putstr(argv[count]);
		my_putchar('\n');
		count--;
	}
	return (0);
}
