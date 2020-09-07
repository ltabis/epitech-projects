/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file
*/

#include "spoof.h"
#include "utils.h"

int main(const int ac, const char * const *av)
{
    parameters_t *p = fill_parameters(ac, av);

    if (!p)
        return (EXIT_FAIL);
    convert_to_array(&p->dest_ip);
    convert_to_array(&p->src_ip);
    if (ac == 6) {
        p->arp_type = 1;
        mac_to_unsigned(p, av[5]);
        if (!p->dest_mac)
            return (EXIT_FAIL);
    }
    return (init_spoof_attack(p));
}
