/*
** EPITECH PROJECT, 2019
** command_list_3.c
** File description:
** commands handling
*/

#include <fcntl.h>
#include <errno.h>
#include "ftp.h"

int cmd_noop(char *full_buff, connexion_t *con, size_t idx)
{
    write(con->fd_list[idx], M200, strlen(M200));
    (void)full_buff;
    return (USAGE);
}

int cmd_retr(char *full_buff, connexion_t *con, size_t idx)
{
    cut_command(&full_buff, 5);
    full_buff[0] = full_buff[0] == '\n' ? '.' : full_buff[0];
    if (!con->data_list[idx]) {
        write(con->fd_list[idx], M425, strlen(M425));
        return (USAGE);
    } else if (check_file(full_buff, con, idx) == EXIT_FAIL) {
        write(con->fd_list[idx], M550, strlen(M550));
        return (USAGE);
    } else if (!fork()) {
        download_data(full_buff, con, idx);
        exit(0);
    }
    close(con->data_list[idx]);
    con->data_list[idx] = 0;
    return (USAGE);
}

int cmd_stor(char *full_buff, connexion_t *con, size_t idx)
{
    char *file = NULL;

    cut_command(&full_buff, 5);
    full_buff[0] = full_buff[0] == '\n' ? '.' : full_buff[0];
    if (!con->data_list[idx]) {
        write(con->fd_list[idx], M425, strlen(M425));
        return (USAGE);
    } else if (!(file = check_file_creation(full_buff, con, idx))) {
        write(con->fd_list[idx], M550, strlen(M550));
        return (USAGE);
    } else if (!fork()) {
        create_file(con, idx, file);
        exit(0);
    }
    close(con->data_list[idx]);
    con->data_list[idx] = 0;
    return (USAGE);
}

int cmd_list(char *full_buff, connexion_t *con, size_t idx)
{
    if (!con->data_list[idx]) {
        write(con->fd_list[idx], M425, strlen(M425));
        return (USAGE);
    } else if (!fork()) {
        if (!fork()) {
            write(con->fd_list[idx], M226, strlen(M226));
            exit(0);
        }
        write(con->fd_list[idx], M150, strlen(M150));
        exec_ls(full_buff, con, idx);
    }
    close(con->data_list[idx]);
    con->data_list[idx] = 0;
    return (USAGE);
}