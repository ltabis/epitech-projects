/*
** EPITECH PROJECT, 2019
** socket.hpp
** File description:
** socket class
*/

#ifndef socket_H
#define socket_H

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

/* socket.c */
int create_raw_socket(void);
int listen_socket(int);
int accept_socket(int);
int bind_socket(int, uint16_t);

#endif /* !NWP_MYARPSPOOF_2018_SOCKET_H */
