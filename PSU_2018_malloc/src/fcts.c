/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** fcts
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

void put_ptr(uintptr_t p)
{
    char result[100];
    int i = 0;
    int tmp = 0;

    while (p != 0) {
        tmp = 0;
        tmp = p % 16;
        if (tmp < 10) {
            result[i] = tmp + 48;
            i++;
        } else {
            result[i] = tmp + 55;
            i++;
        }
        p = p / 16;
    }
    for (int j = i-1; j >= 0; j--)
        my_putchar(result[j]);
}