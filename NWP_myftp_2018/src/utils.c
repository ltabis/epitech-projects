/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** multi-purpose functions
*/

#include <string.h>
#include <ctype.h>
#include "stdio.h"
#include "utils.h"

/*
* cut_command -> char *
* Cuts command by placing a null terminating byte instead of the '\r'
*/

void cut_command(char **str, size_t incr)
{
    (*str) += incr;
    for (size_t i = 0; (*str)[i]; i++)
        if ((*str)[i] == '\r') {
            (*str)[i] = 0;
            break;
        }
}

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
* check_arguments -> int -> const char * const *
* check arguments given by the user
*/

int check_arguments(int ac, const char * const *av)
{
    if (ac < 2 || ac > 3)
        return puterr("Wrong set of arguments, try ./myftp -help\n");
    if (ac == 2 && !strcmp(av[1], "-help")) {
        return (print_usage());
    } else if (ac == 2 && strcmp(av[1], "-help") > 0)
        return puterr("Wrong set of arguments, try ./myftp -help\n");
    return (EXIT_SUCCESS);
}

/*
* print_usage -> void
* print usage to the screen on standard output
*/

int print_usage(void)
{
    printf("USAGE: ./myftp port path\n"\
    "       port"\
    "  is the port number on which the server socket listens\n"\
    "       path"
    "  is the path to the home directory for the Anonymous user\n");
    return (USAGE);
}

int is_string_number(const char *str)
{
    for (unsigned int i = 0; str[i]; i++)
        if (!isdigit(str[i]))
            return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}
