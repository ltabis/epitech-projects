/*
** EPITECH PROJECT, 2019
** packets.hpp
** File description:
** packets class
*/

#include <netinet/ip.h>
#include <netinet/udp.h>
#include "chap.h"

/*
* create_ip_wrap -> char * -> char * -> parameters_t *
* creates the ip header
*/

struct iphdr *create_ip_wrap(char *buffer, char *message,
parameters_t *parameters)
{
    struct iphdr *ip = (struct iphdr *) buffer;

    ip->ihl = 5;
    ip->version = 4;
    ip->tos = 0;
    ip->tot_len =
    htons(sizeof(struct iphdr) + sizeof(struct udphdr) + strlen(message));
    ip->frag_off = 0;
    ip->ttl = 64;
    ip->protocol = IPPROTO_UDP;
    ip->saddr = 0;
    ip->daddr = inet_addr(parameters->target);
    ip->check = 0;
    return (ip);
}

/*
* create_udp_wrap -> char * -> char * -> parameters_t *
* creates the udp header
*/

struct udphdr *create_udp_wrap(char *buffer, char *message,
parameters_t *parameters)
{
    struct udphdr *udp = (struct udphdr *) (buffer + sizeof(struct iphdr));

    udp->uh_sport = htons(4444);
    udp->uh_dport = htons(parameters->port);
    udp->uh_ulen = htons(sizeof(struct udphdr) + strlen(message));
    udp->uh_sum = 0;
    return (udp);
}

/*
* send_package_to -> int -> char * -> char * -> parameters_t *
* send a message given as parameters to the socket.
*/

void send_package_to(int socket, char *message,
char *buffer, parameters_t *parameters)
{
    char *data = buffer + sizeof(struct iphdr) + sizeof(struct udphdr);
    struct sockaddr_in sin;

    strcpy(data, message);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(parameters->port);
    inet_pton(AF_INET, parameters->target, &sin.sin_addr);
    if (sendto(socket, buffer,
    sizeof(struct iphdr) + sizeof(struct udphdr) + strlen(data), 0,
    (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("sendto() error");
        return;
    }
}

/*
* receive_package_from -> int
* get a message coming from the CHAP server.
*/

char *receive_package_from(int socket, parameters_t *parameters)
{
    struct sockaddr_in sin;
    char *message = malloc(sizeof(char) * 4096);
    socklen_t sin_len = sizeof(sin);

    sin.sin_family = AF_INET;
    sin.sin_port = htons(parameters->port);
    inet_pton(AF_INET, parameters->target, &sin.sin_addr);
    memset(message, 0, 4096);
    if (recvfrom(socket, message, 4096 , 0,
    (struct sockaddr *)&sin, &sin_len) == -1) {
        perror("recv() error");
        return (NULL);
    }
    return (message);
}

/*
* catch_correct_packet -> int -> parameters_t *
* catch the packet from the server.
*/

char *catch_correct_packet(int socket, parameters_t *parameters)
{
    char *response = NULL;
    struct iphdr *ip = NULL;
    struct udphdr *udp = NULL;
    char *data = NULL;

    while (1) {
        if (response)
            free(response);
        response = receive_package_from(socket, parameters);
        data = response + sizeof(struct iphdr) + sizeof(struct udphdr);
        ip = (void *)response;
        udp = (void *)response + sizeof(struct iphdr);
        if (ip->saddr == inet_addr(parameters->target) &&
        udp->source == htons(parameters->port))
            break;
    }
    data = strdup(data);
    free(response);
    return (data);
}