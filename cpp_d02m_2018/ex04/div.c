/*
** EPITECH PROJECT, 2019
** div.c
** File description:
** div file
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a / b);
}

float decimale_div(int a, int b)
{
    float c = (float)a;
    float d = (float)b;

    if (b == 0)
        return (0);
    return (c / d);
}

void exec_div(division_t *operation)
{
    integer_op_t *int_op;
    decimale_op_t *dec_op;

    if (!operation)
        return;
    if (operation->div_type == INTEGER) {
        int_op = (integer_op_t *)operation->div_op;
        int_op->res = integer_div(int_op->a, int_op->b);
    } else if (operation->div_type == DECIMALE) {
        dec_op = (decimale_op_t *)operation->div_op;
        dec_op->res = decimale_div(dec_op->a, dec_op->b);
    }
}
