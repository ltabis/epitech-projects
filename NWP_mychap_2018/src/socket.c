/*
** EPITECH PROJECT, 2019
** socket.c
** File description:
** file to create sockets
*/

#include "chap.h"

/*
* bind_socket -> int -> uint16_t
* assign address to the socket fd passed as parameter
*/

int bind_socket(int fd, uint16_t port)
{
    struct sockaddr_in sock;

    if (!port)
        return (EXIT_FAIL);
    sock.sin_family = AF_INET;
    sock.sin_port = htons(port);
    sock.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(fd, (const struct sockaddr *)&sock, sizeof(sock)) == -1) {
        perror("bind() error");
        return (EXIT_FAIL);
    }
    return (EXIT_SUCCESS);
}

/*
* set_scoket -> int
* don't add headers when the socket is opened
*/

int set_socket(int fd)
{
    int one = 1;
    const int *val = &one;

    return (setsockopt(fd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)));
}

/*
* create_new_socket -> void
* creates a new socket
*/

int create_raw_socket(void)
{
    return (socket(AF_INET, SOCK_RAW, IPPROTO_UDP));
}
