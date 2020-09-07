/*
** EPITECH PROJECT, 2019
** find.c
** File description:
** find
*/

#include <string.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (!this || !str || !this->str || !str->str || strlen(this->str) < pos)
        return (-1);
    for (unsigned int i = pos; this->str[i]; i++)
        if (this->compare_c(str, &this->str[i]) == 0)
            return (i);
    return (-1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    string_t *tmp = malloc(sizeof(string_t));
    char *mem = NULL;

    if (!tmp || !this || !str || !this->str || strlen(this->str) < pos)
        return (-1);
    tmp->str = strdup(this->str);
    if (!tmp->str)
        return (-1);
    mem = tmp->str;
    tmp->str += pos;
    for (unsigned int i = pos; this->str[i]; i++, tmp->str++)
        if (this->compare_c(tmp, str) == 0) {
            free(mem);
            free(tmp);
            return (i);
        }
    free(mem);
    free(tmp);
    return (-1);
}
