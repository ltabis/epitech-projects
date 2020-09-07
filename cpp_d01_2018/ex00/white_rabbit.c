/*
** EPITECH PROJECT, 2019
** white_rabbit.c
** File description:
** ex00
*/

#include <stdlib.h>
#include <stdio.h>

int follow_the_white_rabbit(void)
{
    unsigned int sum = 0;

    for (unsigned int die = 0; sum < 397 && die != 37 && die != 1; sum += die) {
        die = (random() % 37) + 1;
        if ((die >= 17 && die <= 21) || (die >= 4 && die <= 6) || die == 28)
            printf("left\n");
        else if ((die >= 34 && die <= 36) || die == 13)
            printf("right\n");
        else if (die == 10 || die == 15 || die == 23)
            printf("forward\n");
        else if (die == 26 || (die % 8 == 0))
            printf("backward\n");
    }
    printf("RABBIT!!!\n");
    return (sum);
}
