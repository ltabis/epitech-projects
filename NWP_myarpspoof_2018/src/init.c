/*
** EPITECH PROJECT, 2019
** init.hpp
** File description:
** init class
*/

#include "spoof.h"
#include "socket.h"
#include "utils.h"
#include "packet.h"

/*
* init_spoof_attack -> parameters_t *p
* initialising spoofing attack
*/

int init_spoof_attack(parameters_t *p)
{
    void *packet = create_packet(p);

    if (!packet)
        return (EXIT_FAIL);
    if (p->mode)
        return (print_broadcast(packet));
    send_broadcast_packet(p, packet);
    if (receiving(p) == EXIT_FAIL)
        return (EXIT_FAIL);
    free(packet);
    packet = create_packet(p);
    go_spoof(p, packet);
    return (EXIT_SUCCESS);
}