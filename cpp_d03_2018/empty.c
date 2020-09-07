/*
** EPITECH PROJECT, 2019
** empty.c
** File description:
** empty
*/

#include "string.h"

int empty(const string_t *this)
{
    if (!this || !this->str || !this->str[0])
        return (1);
    return (0);
}
