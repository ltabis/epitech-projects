/*
** EPITECH PROJECT, 2019
** to_int.c
** File description:
** convert
*/

#include "string.h"

int to_int(const string_t *this)
{
    for (unsigned int i = 0; this->str[i]; i++)
        if (this->str[i] != '-' && (this->str[i] < '0' || this->str[i] > '9'))
            return (0);
    return (atoi(this->str));
}
