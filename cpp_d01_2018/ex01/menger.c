/*
** EPITECH PROJECT, 2019
** menger.c
** File description:
** manger recursive function
*/

#include <stdio.h>
#include "menger.h"


void reiterate_squares(unsigned int size, unsigned int level,
                    unsigned int x, unsigned int y)
{
    unsigned start_y = y;
    if (level == 0)
        return;
    for (char lim_x = 0; lim_x < 3; lim_x++, x += (size * 3)) {
        y = start_y;
        for (char lim_y = 0; lim_y < 3; lim_y++, y += (size * 3)) {
            if (!(lim_x == 1 && lim_y == 1))
                printf("%d, %d, %d\n", size, x, y);
            reiterate_squares(size / 3,
            level - 1, x - (size - (size / 3)), y - (size - (size / 3)));
        }
    }
}
