/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file
*/

#include "ftp.h"

int main(int ac, const char * const *av, char * const *env)
{
    int args = check_arguments(ac, av);

    if (args == USAGE)
        return (EXIT_SUCCESS);
    else if (args == EXIT_FAIL)
        return (EXIT_FAIL);
    return (!setup_server(av, env) ? EXIT_SUCCESS : EXIT_FAIL);
}
