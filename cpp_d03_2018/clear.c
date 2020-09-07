/*
** EPITECH PROJECT, 2019
** clear.c
** File description:
** clearing
*/

#include "string.h"

void clear(string_t *this)
{
    if (!this || !this->str)
        return;
    free(this->str);
    this->str = malloc(sizeof(char));
    if (!this->str)
        return;
    this->str[0] = 0;
}
