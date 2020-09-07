/*
** EPITECH PROJECT, 2019
** argument_parsing.hpp
** File description:
** argument_parsing class
*/

#include <netdb.h>
#include "chap.h"

const char *s_parameter[] = {"-t", "-p", "-P"};
const char *l_parameter[] = {"-target", "-port", "-password"};

/*
* check_host -> parameters_t *
* Checking for an eventual host parameter.
*/

int check_host(parameters_t *parameters)
{
    struct sockaddr_in sin;
    struct hostent *he = NULL;
    struct in_addr **addr_list = NULL;

    if (inet_pton(AF_INET, parameters->target, &sin.sin_addr) <= 0) {
        if (!(he = gethostbyname(parameters->target))) {
            printf("No such hostname: '%s'\n", parameters->target);
            return (EXIT_FAIL);
        }
        addr_list = (struct in_addr **) he->h_addr_list;
        if (addr_list[0]) {
            free(parameters->target);
            parameters->target = strdup(inet_ntoa(*addr_list[0]));
        } else
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

/*
* check_parameter -> parameters_t * -> const char * const * -> size_t -> int
* Call the right function to fill up parameters.
*/

int check_parameter(parameters_t *parameters, const char * const *av,
size_t idx, int ac)
{
    int (*func[3])(parameters_t *, const char *) = {append_target,
    append_port, append_password};

    for (size_t i = 0; s_parameter[i]; i++)
        if ((int)idx + 1 >= ac)
            return (EXIT_FAIL);
        else if (!strcmp(av[idx], s_parameter[i]))
            return ((*func[i])(parameters, av[idx + 1]));
    for (size_t i = 0; l_parameter[i]; i++)
        if ((int)idx + 1 >= ac)
            return (EXIT_FAIL);
        else if (!strcmp(av[idx], l_parameter[i]))
            return ((*func[i])(parameters, av[idx + 1]));
    return (EXIT_FAIL);
}

/*
* check_args -> int -> const char * const *
* Check if the user as given correct parameters.
*/

parameters_t *check_args(int ac, const char * const *av)
{
    parameters_t *parameters = malloc(sizeof(parameters_t));

    if (!parameters || ac != 7)
        return (NULL);
    parameters->password = NULL;
    parameters->port = 0;
    parameters->target = NULL;
    for (size_t i = 1; av[i]; i += 2)
        if (check_parameter(parameters, av, i, ac) == EXIT_FAIL) {
            cleanup_parameter(parameters);
            return (NULL);
        }
    if (check_host(parameters) == EXIT_FAIL) {
        cleanup_parameter(parameters);
        return (NULL);
    }
    return (parameters);
}