/*
** EPITECH PROJECT, 2019
** fill_parameters.hpp
** File description:
** fill_parameters class
*/

#include <net/ethernet.h>
#include <netdb.h>
#include "spoof.h"
#include "utils.h"

void convert_to_array(unsigned char **ip)
{
    unsigned char *tmp_ip = (unsigned char *)strdup((char *)*ip);
    unsigned char *last = tmp_ip;
    size_t len = 0;

    free(*ip);
    *ip = malloc(sizeof(char) * 4);
    for (size_t i = 0, j = 0; tmp_ip[i]; i++) {
        if (tmp_ip[i] == '.' || tmp_ip[i] == ':') {
            unsigned char *tmp =(unsigned char *)strndup((char *)last, len);
            last = &tmp_ip[i] + 1;
            (*ip)[j] = atoi((char *)tmp);
            free(tmp);
            len = 0;
            j++;
        } else
            len++;
    }
    unsigned char *tmp = (unsigned char *)strndup((char *)last, len);
    (*ip)[3] = atoi((char *)tmp);
    free(tmp);
}

/*
* check_host -> parameters_t *
* Checking for an eventual host parameter.
*/

int check_hosts(parameters_t *parameters)
{
    struct sockaddr_in sin;

    if (inet_pton(AF_INET, (char *)parameters->src_ip, &sin.sin_addr) <= 0) {
        if (!gethostbyname((char *)parameters->src_ip)) {
            fprintf(stderr, "No such hostname: '%s'\n", parameters->src_ip);
            return (EXIT_FAIL);
        }
    }
    if (inet_pton(AF_INET, (char *)parameters->dest_ip, &sin.sin_addr) <= 0) {
        if (!gethostbyname((char *)parameters->dest_ip)) {
            fprintf(stderr, "No such hostname: '%s'\n", parameters->dest_ip);
            return (EXIT_FAIL);
        }
    }
    return (EXIT_SUCCESS);
}

/*
* check_optional_parameters -> parameters_t * -> int -> const char * const *
* Filling optional parameters
*/

int check_optional_parameters(parameters_t *p,
const int ac, const char * const *av)
{
    p->mode = 0;
    if (ac == 5) {
        if (!strcmp(av[4], "--printBroadcast")) {
            p->mode = 1;
        } else
            return (puterr("Wrong set of arguments.\n"));
    } else if (ac == 6) {
        if (!strcmp(av[4], "--printSpoof")) {
            p->mode = 2;
        } else
            return (puterr("Wrong set of arguments.\n"));
    }
    return (EXIT_SUCCESS);
}

/*
* fill_parameters -> int -> const char * const *
* Filling parameters_t struct (ip of victim/source)
*/

parameters_t *fill_parameters(const int ac, const char * const *av)
{
    parameters_t *p = malloc(sizeof(parameters_t));

    if (ac < 3 || ac > 6 || !p) {
        puterr("Wrong set of arguments.\n");
        return (NULL);
    }
    p->src_ip = (unsigned char *)strdup(av[1]);
    p->dest_ip = (unsigned char *)strdup(av[2]);
    p->sip = strdup(av[1]);
    p->dip = strdup(av[2]);
    p->iface = strdup(av[3]);
    p->dest_mac = malloc(sizeof(unsigned char) * ETH_ALEN);
    p->arp_type = 0;
    memset(p->dest_mac, 0xff, ETH_ALEN);
    if (get_mac_address(p) == EXIT_FAIL)
        return (NULL);
    if (ac >= 4 && check_optional_parameters(p, ac, av) == EXIT_FAIL)
        return (NULL);
    return (check_hosts(p) == EXIT_FAIL ? NULL : p);
}