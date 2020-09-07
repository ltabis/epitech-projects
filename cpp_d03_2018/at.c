/*
** EPITECH PROJECT, 2019
** at.c
** File description:
** at
*/

#include <string.h>
#include "string.h"

char at(const string_t *this, size_t pos)
{
    unsigned int len = 0;

    if (!this || !this->str)
        return (-1);
    len = strlen(this->str);
    if (len <= pos)
        return (-1);
    return (this->str[pos]);
}
