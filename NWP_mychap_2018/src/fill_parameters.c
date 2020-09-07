/*
** EPITECH PROJECT, 2019
** fill_parameters.hpp
** File description:
** fill_parameters class
*/

#include "chap.h"

/*
* append_target -> parameters_t *, const char *
* Fill up the address
*/

int append_target(parameters_t *parameters, const char *param)
{
    if (parameters->target)
        return (EXIT_FAIL);
    parameters->target = strdup(param);
    return (EXIT_SUCCESS);
}

/*
* append_port -> parameters_t *, const char *
* Fill up the port
*/

int append_port(parameters_t *parameters, const char *param)
{
    if (parameters->port || is_string_number(param) == EXIT_FAIL)
        return (EXIT_FAIL);
    parameters->port = atoi(param);
    return (EXIT_SUCCESS);
}

/*
* append_password -> parameters_t *, const char *
* Fill up the password
*/

int append_password(parameters_t *parameters, const char *param)
{
    if (parameters->password)
        return (EXIT_FAIL);
    parameters->password = strdup(param);
    return (EXIT_SUCCESS);
}