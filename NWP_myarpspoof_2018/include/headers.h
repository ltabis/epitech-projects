/*
** EPITECH PROJECT, 2019
** arpspoof
** File description:
** headers def
*/

#ifndef NWP_MYARPSPOOF_2018_HEADERS_H
#define NWP_MYARPSPOOF_2018_HEADERS_H

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"
#include <net/ethernet.h>
#include <net/if_arp.h>

typedef struct arp_s {
    uint16_t htype;
    uint16_t ptype;
    uint8_t hlen;
    uint8_t plen;
    uint16_t opcode;
    uint8_t sender_mac[6];
    uint8_t sender_ip[4];
    uint8_t target_mac[6];
    uint8_t target_ip[4];
} arp_t;

typedef struct ethr_s {
    unsigned char h_dest[6];
    unsigned char h_src[6];
    uint16_t type;
} ethr_t;

#endif //NWP_MYARPSPOOF_2018_HEADERS_H
