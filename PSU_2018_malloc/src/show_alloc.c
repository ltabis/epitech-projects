/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** show_alloc
*/

#include "my.h"

void show_alloc_mem(data_t data)
{
    uintptr_t p = (uintptr_t) data.brk;
    my_putstr("break : 0x");
    put_ptr(p);
    my_putchar('\n');
}