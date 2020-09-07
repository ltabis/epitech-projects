/*
** EPITECH PROJECT, 2019
** insert.c
** File description:
** insert
*/

#include <string.h>
#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    unsigned int index = 0;
    unsigned int next = 0;
    char *new_str = NULL;

    if (!this || !this->str || !str)
        return;
    if (strlen(this->str) < pos) {
        append_c(this, str);
        return;
    }
    new_str = malloc(sizeof(char) * (strlen(this->str) + strlen(str) + 1));
    for (; next < pos && this->str[next]; next++, index++)
        new_str[index] = this->str[next];
    for (unsigned int i = 0; str[i]; i++, index++)
        new_str[index] = str[i];
    for (; this->str[next]; next++, index++)
        new_str[index] = this->str[next];
    new_str[index] = 0;
    free(this->str);
    this->str = new_str;
}

void insert_s(string_t *this, size_t pos, string_t *str)
{
    unsigned int index = 0;
    unsigned int next = 0;
    char *n = NULL;

    if (!this || !this->str || !str || !str->str)
        return;
    if (strlen(this->str) < pos) {
        append_c(this, str->str);
        return;
    }
    n = malloc(sizeof(char) * (strlen(this->str) + strlen(str->str) + 1));
    for (; next < pos && this->str[next]; next++, index++)
        n[index] = this->str[next];
    for (unsigned int i = 0; str->str[i]; i++, index++)
        n[index] = str->str[i];
    for (; this->str[next]; next++, index++)
        n[index] = this->str[next];
    n[index] = 0;
    free(this->str);
    this->str = n;
}
