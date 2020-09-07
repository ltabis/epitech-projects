/*
** EPITECH PROJECT, 2019
** tab_to_2dtab.c
** File description:
** ex02
*/

#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    unsigned int ptr = 0;

    if (!res)
        return;
    *res = malloc(sizeof(int *) * length);
    if (!(*res))
        return;
    for (int i = 0; i < length; i++) {
        (*res)[i] = malloc(sizeof(int) * width);
        if (!(*res)[i])
            return;
        for (int j = 0; j < width; j++, ptr++) {
            (*res)[i][j] = tab[ptr];
        }
    }
}
