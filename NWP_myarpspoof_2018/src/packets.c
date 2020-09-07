/*
** EPITECH PROJECT, 2019
** packets.hpp
** File description:
** packets class
*/

#include <netinet/ip.h>
#include <netinet/udp.h>
#include <stdlib.h>
#include "spoof.h"
#include "utils.h"
#include "packet.h"

/*
* build_packet -> void
* creating the packet to send to the victim
*/

void build_arp_header(void *buffer, parameters_t *p)
{
    arp_header_t *hdr = (arp_header_t *)(buffer + 14);

    hdr->ar_hrd = htons(1);
    hdr->ar_pro = htons(ETH_P_IP);
    hdr->ar_hln = 6;
    hdr->ar_pln = 4;
    memcpy((char *)hdr->__ar_sha, p->src_mac, ETH_ALEN);
    memcpy((char *)hdr->__ar_sip, (char *)p->src_ip, 4);
    memcpy((char *)hdr->__ar_tha, (char *)p->dest_mac, ETH_ALEN);
    memcpy((char *)hdr->__ar_tip, (char *)p->dest_ip, 4);
    if (p->arp_type == 0)
        hdr->ar_op = htons(ARPOP_REQUEST);
    else
        hdr->ar_op = htons(ARPOP_REPLY);
}

void build_ethernet_header(void *buffer, parameters_t *p)
{
    struct ether_header *hdr = buffer;

    memcpy((char *)hdr->ether_shost, p->src_mac, 6);
    memcpy((char *)hdr->ether_dhost, (char *)p->dest_mac, 6);
    hdr->ether_type = htons(ETHERTYPE_ARP);
}

/*
* create_broadcast_packet -> parameters_t *p
* creating the broadcast packet.
*/

void *create_packet(parameters_t *p)
{
    unsigned long len = sizeof(struct ether_header) + sizeof(arp_header_t);
    void *buffer = malloc(len * sizeof(uint8_t));

    if (!buffer)
        return (NULL);
    memset(buffer, 0, len * sizeof(uint8_t));
    build_ethernet_header(buffer, p);
    build_arp_header(buffer, p);
    return (buffer);
}