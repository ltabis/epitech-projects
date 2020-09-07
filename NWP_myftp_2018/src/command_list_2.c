/*
** EPITECH PROJECT, 2019
** command_list_2.c
** File description:
** commands handling
*/

#include "ftp.h"

/*
* cmd_dele -> char * -> connexion_t * -> size_t
* delete a file specified by the client
*/

int cmd_dele(char *full_buff, connexion_t *con, size_t idx)
{
    char *path = NULL;
    char *real_path = NULL;

    cut_command(&full_buff, 5);
    real_path = create_path(full_buff, con, idx);
    if (!(path = realpath(real_path, NULL)) || remove(path) == -1) {
        if (path)
            free(path);
        free(real_path);
        write(con->fd_list[idx], M550, strlen(M550));
        return (USAGE);
    }
    free(path);
    free(real_path);
    write(con->fd_list[idx], M250, strlen(M250));
    return (USAGE);
}

/*
* cmd_pwd -> char * -> connexion_t * -> size_t
* Print clients current working directory
*/

int cmd_pwd(char *full_buff, connexion_t *con, size_t idx)
{
    write(con->fd_list[idx], "257 \"", 5);
    write(con->fd_list[idx], con->path_list[idx], strlen(con->path_list[idx]));
    write(con->fd_list[idx], "\"\n", 2);
    (void) full_buff;
    return (USAGE);
}

/*
* cmd_pasv -> char * -> connexion_t * -> size_t
* Check commands that doesn't need logging.
*/

int cmd_pasv(__attribute__ ((unused)) char *full_buff,
connexion_t *con, size_t idx)
{
    size_t port = CONNEXIONS;

    if (con->data_list[idx]) {
        close(con->data_list[idx]);
        con->data_list[idx] = 0;
    }
    if (!(con->data_list[idx] = create_new_socket())) {
        write(con->data_list[idx], M500, strlen(M500));
        return (USAGE);
    }
    for (; port < MAX_PORT && bind_socket(con->data_list[idx], port); port++);
    if (port == MAX_PORT || listen_socket(con->data_list[idx]) == EXIT_FAIL ||
    write_pasv(con, idx, port) == EXIT_FAIL) {
        if (port == MAX_PORT)
            return (USAGE);
        close(con->data_list[idx]);
        con->data_list[idx] = 0;
    }
    return (USAGE);
}

/*
* cmd_port -> char * -> connexion_t * -> size_t
* Check commands that doesn't need logging.
*/

int cmd_port(char *full_buff, connexion_t *con, size_t idx)
{
    cut_command(&full_buff, 5);
    if (check_valid_address(full_buff, con, idx) == EXIT_FAIL) {
        write(con->fd_list[idx], M500, strlen(M500));
        return (USAGE);
    }
    write(con->fd_list[idx], M200, strlen(M200));
    return (USAGE);
}

/*
* cmd_help -> char * -> connexion_t * -> size_t
* Check commands that doesn't need logging.
*/

int cmd_help(char *full_buff, connexion_t *con, size_t idx)
{
    write(con->fd_list[idx], M214, strlen(M214));
    write(con->fd_list[idx], HELP, strlen(HELP));
    write(con->fd_list[idx], M214, strlen(M214));
    (void) full_buff;
    return (USAGE);
}