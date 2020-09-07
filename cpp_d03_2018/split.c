/*
** EPITECH PROJECT, 2019
** split.c
** File description:
** split
*/

#include <string.h>
#include "string.h"

string_t **split_s(const string_t *this, char separator)
{
    unsigned int len = 0;
    string_t **array = NULL;
    char *tmp = NULL;

    if (!this || !this->str)
        return (NULL);
    tmp = this->str;
    for (unsigned int i = 0; this->str[i]; i++)
        len += this->str[i] == separator ? 1 : 0;
    array = malloc(sizeof(string_t *) * (len + 2));
    if (!array)
        return (NULL);
    for (unsigned int i = 0; i < len + 1; i++)
        if (allocate_space(&array[i], &tmp, separator) == -1)
            return (NULL);
    array[len + 1] = NULL;
    return (array);
}

char **split_c(const string_t *this, char separator)
{
    unsigned int len = 0;
    char **array = NULL;
    char *tmp = NULL;

    if (!this || !this->str)
        return (NULL);
    tmp = this->str;
    for (unsigned int i = 0; this->str[i]; i++)
        len += this->str[i] == separator ? 1 : 0;
    array = malloc(sizeof(char *) * (len + 2));
    if (!array)
        return (NULL);
    for (unsigned int i = 0; i < len + 2; i++)
        if (allocate_space_char(&array[i], &tmp, separator) == -1)
            return (NULL);
    array[len + 1] = NULL;
    return (array);
}
