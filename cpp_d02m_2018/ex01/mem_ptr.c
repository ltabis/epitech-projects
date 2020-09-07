/*
** EPITECH PROJECT, 2019
** mem_ptr.c
** File description:
** ex01
*/

#include <string.h>
#include <stdlib.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    unsigned int len1 = 0;
    unsigned int len2 = 0;
    unsigned int j = 0;

    if (!res || !str1 || !str2)
        return;
    len1 = strlen(str1);
    len2 = strlen(str2);
    *res = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!(*res))
        return;
    for (unsigned int i = 0; str1[i]; i++, j++)
        (*res)[j] = str1[i];
    for (unsigned int i = 0; str2[i]; i++, j++)
        (*res)[j] = str2[i];
    (*res)[len2 + len1] = 0;
}

void add_str_struct(str_op_t *str_op)
{
    unsigned int len1 = 0;
    unsigned int len2 = 0;
    unsigned int j = 0;

    if (!str_op || !str_op->str1 || !str_op->str2)
        return;
    len1 = strlen(str_op->str1);
    len2 = strlen(str_op->str2);
    str_op->res = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!(str_op->res))
        return;
    for (unsigned int i = 0; str_op->str1[i]; i++, j++)
        str_op->res[j] = str_op->str1[i];
    for (unsigned int i = 0; str_op->str2[i]; i++, j++)
        str_op->res[j] = str_op->str2[i];
    str_op->res[len2 + len1] = 0;
}
