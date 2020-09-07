/*
** EPITECH PROJECT, 2019
** size.c
** File description:
** size
*/

#include <string.h>
#include "string.h"

int size(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (strlen(this->str));
}
