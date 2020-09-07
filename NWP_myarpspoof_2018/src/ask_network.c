/*
** EPITECH PROJECT, 2019
** ask_network.hpp
** File description:
** ask_network class
*/

#include "socket.h"
#include "utils.h"
#include "packet.h"
#include <netinet/ip.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <ifaddrs.h>

int print_broadcast(char *packet)
{
    for (size_t i = 0,
    len = sizeof(arp_header_t) + sizeof(struct ether_header); i < len; ++i)
        if (i == len - 1)
            printf("%02x\n", packet[i] & 0xff);
        else
            printf("%02x ", packet[i] & 0xff);
    return (EXIT_SUCCESS);
}

int ask_network(parameters_t *p)
{
    int fd = create_raw_socket();

    (void)fd;
    (void)p;
    return (EXIT_SUCCESS);
}

int check_interface(struct ifreq *ifr, struct ifconf *ifc,
int sock, parameters_t *p)
{
    if (!strcmp(ifr->ifr_name, p->iface) &&
    !(ifr->ifr_flags & IFF_LOOPBACK) &&
    ioctl(sock, SIOCGIFCONF, ifc) != -1)
        if (!ioctl(sock, SIOCGIFHWADDR, ifr)) {
            memcpy(p->src_mac, ifr->ifr_hwaddr.sa_data, 6);
            return (EXIT_SUCCESS);
        }
    return (EXIT_FAIL);
}

int get_mac_address(parameters_t *p)
{
    char buf[1024] = {0};
    struct ifreq ifr = {0};
    struct ifconf ifc = {.ifc_len = sizeof(buf), .ifc_buf = buf};
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    struct ifreq *it = ifc.ifc_req;
    const struct ifreq *const end = it + ifc.ifc_len / sizeof(struct ifreq);

    if (!(p->src_mac = malloc(sizeof(unsigned char) * 6)) ||
    sock < 0 || ioctl(sock, SIOCGIFCONF, &ifc) == -1)
        return (EXIT_FAIL);
    for (; it != end; ++it) {
        strcpy(ifr.ifr_name, it->ifr_name);
        if (!ioctl(sock, SIOCGIFFLAGS, &ifr) &&
        check_interface(&ifr, &ifc, sock, p) == EXIT_SUCCESS)
            return (EXIT_SUCCESS);
        else if (ioctl(sock, SIOCGIFFLAGS, &ifr))
            return (
            puterr("The network interface given as not been found.\n"));
    }
    return (puterr("The network interface given as not been found."));
}