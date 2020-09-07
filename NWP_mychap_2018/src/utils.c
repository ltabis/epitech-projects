/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** multi-purpose functions
*/

#include <string.h>
#include <ctype.h>
#include "stdio.h"
#include "chap.h"

/*
* puterr -> const char *
* display message on error output
*/

int puterr(const char *str)
{
    fprintf(stderr, str);
    return (EXIT_FAIL);
}

/*
* is_string_number -> const char *
* check if a number
*/

int is_string_number(const char *str)
{
    for (unsigned int i = 0; str[i]; i++)
        if (!isdigit(str[i]))
            return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}

/*
* cleanup_parameter -> parameters_t *
* delete parameters structure
*/

void cleanup_parameter(parameters_t *parameters)
{
    if (!parameters)
        return;
    if (parameters->target)
        free(parameters->target);
    if (parameters->password)
        free(parameters->password);
    free(parameters);
}
