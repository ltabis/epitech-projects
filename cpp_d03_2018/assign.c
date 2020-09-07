/*
** EPITECH PROJECT, 2019
** assign.c
** File description:
** assign
*/

#include <string.h>
#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this && this->str)
        this->string_destroy(this);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (this && this->str)
        this->string_destroy(this);
    this->str = strdup(s);
}
