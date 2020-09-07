/*
** EPITECH PROJECT, 2019
** sendb
** File description:
** sasa
*/

#include <netinet/ip.h>
#include <netinet/udp.h>
#include <stdlib.h>
#include <net/if.h>
#include <errno.h>
#include <ctype.h>
#include <sys/ioctl.h>
#include <linux/if_packet.h>
#include "socket.h"
#include "spoof.h"
#include "utils.h"
#include "packet.h"

int send_broadcast_packet(parameters_t *p, char *packet)
{
    int sskt = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW);
    struct sockaddr_ll device;
    int len = sizeof(arp_header_t) + sizeof(struct ether_header);

    memset(&device, 0, sizeof(struct sockaddr_ll));
    device.sll_family = AF_PACKET;
    device.sll_protocol = htons(ETH_P_IP);
    device.sll_ifindex = if_nametoindex(p->iface);
    device.sll_halen = ETH_ALEN;
    memset(device.sll_addr, 0, 8);
    memcpy(device.sll_addr, p->dest_mac, 6);
    if (sskt < 0 || (sendto(sskt, packet,
    len, 0, (struct sockaddr *)&device, sizeof(struct sockaddr_ll))) <= 0) {
        perror("sendto() failed");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void go_spoof(parameters_t *p, void *packet)
{
    int sskt = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW);
    struct sockaddr_ll dev;
    int len = sizeof(arp_header_t) + sizeof(struct ether_header);

    memset(&dev, 0, sizeof(struct sockaddr_ll));
    dev.sll_family = AF_PACKET;
    dev.sll_protocol = htons(ETH_P_IP);
    dev.sll_ifindex = if_nametoindex(p->iface);
    dev.sll_halen = ETH_ALEN;
    memset(dev.sll_addr, 0, 8);
    memcpy(dev.sll_addr, p->dest_mac, 6);
    while (1) {
        if (sskt < 0 || (sendto(sskt, packet, len, 0, (struct sockaddr *)&dev,
        sizeof(struct sockaddr_ll))) <= 0)
            break;
        printf("Spoofed packet sent to '%d.%d.%d.%d'\n", p->dest_ip[0],
        p->dest_ip[1], p->dest_ip[2], p->dest_ip[3]);
        usleep(1000000);
    }
}