/*
** EPITECH PROJECT, 2019
** calloc.c
** File description:
** calloc function
*/

#include "my.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t idx = 0;
    char **array = NULL;

    if (nmemb && size) {
        if (!(array = malloc(sizeof(char *) * nmemb)))
            return (NULL);
        for (; idx < nmemb && array[idx]; idx++) {
            array[idx] = malloc(sizeof(char) * size);
            *(array[idx]) = 0;
        }
        if (!array[idx])
            return (NULL);
    }
    return (NULL);
}
