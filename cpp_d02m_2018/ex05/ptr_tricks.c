/*
** EPITECH PROJECT, 2019
** ptr_tricks.c
** File description:
** ptr tricks
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int len = ptr1 - ptr2;

    return (len < 0 ? len * -1 : len);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    size_t offset = offsetof(whatever_t, member);

    return ((whatever_t *)((char *)member_ptr - offset));
}
