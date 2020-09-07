/*
** EPITECH PROJECT, 2019
** run.c
** File description:
** run server
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <sys/time.h>
#include <sys/types.h>
#include "ftp.h"

/*
* read_instruction -> connexion_t *
* reads the socket used by the client to extract and process instructions.
*/

void read_instruction(connexion_t *con, size_t idx)
{
    int value = 0;
    char full_buff[1024] = {0};

    if ((value = read(con->data, full_buff, 16000)) > 0) {
        if (full_buff[strlen(full_buff) - 2] == '\r' &&
        full_buff[strlen(full_buff) - 1] == '\n')
            value = process_command(full_buff, con, idx);
        if (value == QUIT)
            close_connexion(con, idx);
    } else
        close_connexion(con, idx);
}

/*
* check_sockets -> connexion_t *
* checking if new connexion or instructions to read.
*/

void check_sockets(connexion_t *con)
{
    if (FD_ISSET(con->control, &con->rfds)) {
        con->data = accept_socket(con->control);
        write(con->data, M220, strlen(M220));
        for (size_t i = 0; con->fd_list[i] != con->data &&
        i < CONNEXIONS;) {
            con->fd_list[i] = !con->fd_list[i] ? con->data : con->fd_list[i];
            i += con->fd_list[i] != con->data ? 1 : 0;
        }
        FD_SET(con->data, &con->rfds);
        return;
    }
    for (size_t i = 0; i < CONNEXIONS; i++) {
        if (con->fd_list[i] && FD_ISSET(con->fd_list[i], &con->rfds)) {
            con->data = con->fd_list[i];
            read_instruction(con, i);
            return;
        }
    }
}

/*
*  setup_fd_lists -> connexion_t *
*  setup file descriptors in select's list.
*/

int setup_fd_lists(connexion_t *con)
{
    int max_fd = con->control;

    FD_ZERO(&con->rfds);
    FD_SET(con->control, &con->rfds);
    for (size_t i = 0; i < CONNEXIONS; i++)
        if (con->fd_list[i] > 0) {
            FD_SET(con->fd_list[i], &con->rfds);
            max_fd = con->fd_list[i] > max_fd ? con->fd_list[i] : max_fd;
        }
    return (max_fd);
}

/*
*  run_server -> connexion_t *
*  runs the server
*/

int run_server(connexion_t *con)
{
    struct timeval tv = {30, 0};

    for (int retval = 0, max_fd = 0; 1;) {
        max_fd = setup_fd_lists(con);
        retval = select(max_fd + 1, &con->rfds, NULL, NULL, &tv);
        if (retval == -1)
            return (EXIT_FAIL);
        else if (retval)
            check_sockets(con);
    }
}

/*
*  setup_server -> const char * const *
*  setup the sever with the port and path given as arguments,
*  and then run it
*/

int setup_server(const char * const *av, char * const *env)
{
    connexion_t con;
    uint16_t port = 0;

    con.control = create_new_socket();
    con.data = 0;
    if (check_default_path(&con, av[2]) == EXIT_FAIL ||
    !(con.path_list = malloc(sizeof(char *) * CONNEXIONS)))
        return (EXIT_FAIL);
    init_buffers(&con, env);
    if (is_string_number(av[1]) == EXIT_FAIL)
        return (puterr("The port specified isn't valid.\n"));
    port = (uint16_t)atoi(av[1]);
    if (con.control == -1 || bind_socket(con.control, port) == EXIT_FAIL ||
    listen_socket(con.control) == EXIT_FAIL)
        return (EXIT_FAIL);
    return (run_server(&con));
}
