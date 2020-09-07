/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** task01 Day04
*/

void my_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
