/*
** EPITECH PROJECT, 2019
** c_str.c
** File description:
** c_str
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (!this->str)
        return (NULL);
    return (this->str);
}
