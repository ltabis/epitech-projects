/*
** EPITECH PROJECT, 2019
** packet.hpp
** File description:
** packet class
*/

#ifndef packet_H
#define packet_H

#include "spoof.h"
#include <net/ethernet.h>
#include <net/if_arp.h>

typedef struct arp_header_s
{
    unsigned short int ar_hrd;
    unsigned short int ar_pro;
    unsigned char ar_hln;
    unsigned char ar_pln;
    unsigned short int ar_op;
    unsigned char __ar_sha[ETH_ALEN];
    unsigned char __ar_sip[4];
    unsigned char __ar_tha[ETH_ALEN];
    unsigned char __ar_tip[4];
} arp_header_t;

arp_header_t *build_arp_packet(void);
int print_broadcast(char *packet);
int ask_network(parameters_t *p);
void *create_packet(parameters_t *p);
int send_broadcast_packet(parameters_t *p, char *packet);
int receiving(parameters_t *p);

#endif /* !NWP_MYARPSPOOF_2018_PACKET_H */
