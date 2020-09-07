/*
** EPITECH PROJECT, 2019
** debug.hpp
** File description:
** debug class
*/

#include "chap.h"

/*
* print_parameters_content -> parameters_t *
* print parameters
*/

void print_parameters_content(parameters_t *parameters)
{
    printf("Parameters content-----\n");
    printf("target ip : [%s]\n", parameters->target);
    printf("target port : [%u]\n", parameters->port);
    printf("target password : [%s]\n", parameters->password);
}

/*
* display_result -> char *
* display the result of the hand shake
*/

void display_result(char *response)
{
    if (!strcmp(response, "KO"))
        printf("KO\n");
    else
        printf("Secret: '%s'\n", response);
    free(response);
}