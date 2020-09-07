/*
** EPITECH PROJECT, 2019
** add.c
** File description:
** add file
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    a *= a < 0 ? -1 : 1;
    b *= b < 0 ? -1 : 1;

    return (a + b);
}

void exec_add(addition_t *operation)
{
    if (!operation)
        return;
    if (operation->add_type == NORMAL) {
        operation->add_op.res =
        normal_add(operation->add_op.a, operation->add_op.b);
    } else if (operation->add_type == ABSOLUTE) {
        operation->add_op.res =
        absolute_add(operation->add_op.a, operation->add_op.b);
    }
}
