/*
** EPITECH PROJECT, 2019
** copy.c
** File description:
** copying
*/

#include <string.h>
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    unsigned int i = pos;
    unsigned int j = 0;
    size_t cpy = 0;

    if (!this || !this->str)
        return (0);
    if (strlen(this->str) < pos)
        return (0);
    for (; cpy < n &&
    this->str[i]; i++, cpy++, j++)
        s[j] = this->str[i];
    cpy += this->str[i] == 0 && n != i ? 1 : 0;
    s[j] = this->str[i] == 0 ? 0 : s[j];
    return (cpy);
}
