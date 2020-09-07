/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** multi-purpose functions
*/

#include <netinet/ether.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "utils.h"

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
    for (size_t i = 0; str[i]; ++i)
        if (!isdigit(str[i]))
            return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}

int mac_to_unsigned(parameters_t *p, const char *address)
{
    struct ether_addr *hdr = ether_aton(address);

    if (!hdr)
        return (EXIT_FAIL);
    memcpy(p->dest_mac, hdr->ether_addr_octet, ETH_ALEN);
    return (EXIT_SUCCESS);
}