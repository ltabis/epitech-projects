/*
** EPITECH PROJECT, 2019
** split_string.c
** File description:
** split
*/

#include <string.h>
#include "string.h"

unsigned int count_word(char *tmp, char separator)
{
    unsigned int i = 0;

    for (; tmp[0] && tmp[0] != separator; i++, tmp++);
    return (i);
}

char allocate_space(string_t **elem, char **tmp, char separator)
{
    unsigned int len = 0;

    (*elem) = malloc(sizeof(string_t));
    if (!(*elem))
        return (-1);
    len = count_word(*tmp, separator) + 1;
    if (*tmp && (*tmp)[0] && (*tmp)[0] != separator)
        (*elem)->str = strndup(*tmp, len - 1);
    else
        (*elem)->str = strdup("");
    *tmp += *tmp && (*tmp)[0] ? len : 0;
    if (!(*elem)->str)
        return (-1);
    return (0);
}

char allocate_space_char(char **elem, char **tmp, char separator)
{
    unsigned int len = 0;

    len = count_word(*tmp, separator) + 1;
    if (*tmp && (*tmp)[0] && (*tmp)[0] != separator)
        *elem = strndup(*tmp, len - 1);
    else
        *elem = strdup("");
    *tmp += *tmp && (*tmp)[0] ? len : 0;
    if (!(*elem))
        return (-1);
    return (0);
}
