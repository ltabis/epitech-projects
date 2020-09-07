/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file
*/

#include "chap.h"

/*
* main -> int -> int, const char * const *
* main function
*/

int main(int ac, const char * const *av)
{
    parameters_t *parameters = NULL;

    if (!(parameters = check_args(ac, av)))
        return (EXIT_FAIL);
    run_client(parameters);
    cleanup_parameter(parameters);
    return (0);
}