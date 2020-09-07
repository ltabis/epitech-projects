/*
** EPITECH PROJECT, 2019
** socket.c
** File description:
** file to create sockets
*/

#include "ftp.h"

/*
* accept_socket -> int
* wait for connection, and then extract data from it
*/

int accept_socket(int fd)
{
    struct sockaddr_in sock;
    socklen_t len = sizeof(sock);
    int new_socket = 0;

    new_socket = accept(fd, (struct sockaddr *)&sock, &len);
    printf("New connexion : IP Adress = %s, Port = %d\n",
    inet_ntoa(sock.sin_addr), ntohs(sock.sin_port));
    return (new_socket);
}

/*
* listen_socket -> int
* passive mode
*/

int listen_socket(int fd)
{
    return (listen(fd, CONNEXIONS) == -1 ? EXIT_FAIL : EXIT_SUCCESS);
}

/*
* bind_socket -> int -> uint16_t
* assign address to the socket fd passed as parameter
*/

int bind_socket(int fd, uint16_t port)
{
    struct sockaddr_in sock;

    if (!port)
        return (puterr("Port cannot be 0\n"));
    sock.sin_family = AF_INET;
    sock.sin_port = htons(port);
    sock.sin_addr.s_addr = htonl(INADDR_ANY);
    return bind(fd, (const struct sockaddr *)&sock, sizeof(sock)) == -1 ?
    EXIT_FAIL : EXIT_SUCCESS;
}

/*
* create_new_socket -> void
* creates a new socket
*/

int create_new_socket(void)
{
    return (socket(AF_INET, SOCK_STREAM, 0));
}
