/*
** EPITECH PROJECT, 2019
** add_mul.c
** File description:
** ex00
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int tmp = *first;

    *first = *first + *second;
    *second = tmp * *second;
}
