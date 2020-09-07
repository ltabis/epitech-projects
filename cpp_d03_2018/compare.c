/*
** EPITECH PROJECT, 2019
** compare.c
** File description:
** compare function
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    unsigned int count = 0;

    if (!this || !this->str || !str || !str->str)
        return (-1);
    while (str->str[count] == this->str[count] &&
    this->str[count] != '\0' && str->str[count] != '\0')
        count++;
    return (this->str[count] - str->str[count]);
}

int compare_c(const string_t *this, const char *str)
{
    unsigned int count = 0;

    if (!this || !this->str || !str)
        return (-1);
    while (str[count] == this->str[count] &&
    this->str[count] != '\0' && str[count] != '\0')
        count++;
    return (this->str[count] - str[count]);
}
