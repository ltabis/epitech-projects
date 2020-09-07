/*
** EPITECH PROJECT, 2019
** command_list_1.c
** File description:
** commands handling
*/

#include <dirent.h>
#include "ftp.h"

int cmd_user(char *full_buff, connexion_t *con, size_t idx)
{
    cut_command(&full_buff, 5);
    if (!strcasecmp("anonymous", full_buff)) {
        write(con->fd_list[idx], M331, strlen(M331));
        con->log_list[idx] = LOGGED;
    } else if (full_buff[0] == '\n') {
        write(con->fd_list[idx], M530, strlen(M530));
        con->log_list[idx] = 0;
    } else {
        write(con->fd_list[idx], M331, strlen(M331));
        con->log_list[idx] = 3;
    }
    return (LOGGED);
}

int cmd_pass(connexion_t *con, size_t idx)
{
    if (con->log_list[idx] == LOGGED) {
        write(con->fd_list[idx], M230, strlen(M230));
        con->log_list[idx] = PASS;
    } else if (!con->log_list[idx]){
        write(con->fd_list[idx], M503, strlen(M503));
    } else {
        con->log_list[idx] = 0;
        write(con->fd_list[idx], M530, strlen(M530));
    }
    return (PASS);
}

int cmd_quit(int current_user)
{
    write(current_user, M221, strlen(M221));
    return (QUIT);
}

int cmd_cwd(char *full_buff, connexion_t *con, size_t idx)
{
    DIR *dir = NULL;
    char *path = NULL;
    char *real_path = NULL;

    cut_command(&full_buff, 4);
    real_path = create_path(full_buff, con, idx);
    if (!(path = realpath(real_path, NULL)) || !(dir = opendir(path))) {
        if (path)
            free(path);
        free(real_path);
        write(con->fd_list[idx], M550, strlen(M550));
        return (USAGE);
    } else if (con->path_list[idx])
        free(con->path_list[idx]);
    con->path_list[idx] = strdup(path);
    write(con->fd_list[idx], M250, strlen(M250));
    closedir(dir);
    free(path);
    free(real_path);
    return (USAGE);
}

int cmd_cdup(char *full_buff, connexion_t *con, size_t idx)
{
    size_t last_slash = 0;

    if (con->path_list[idx][0] == 47 && !con->path_list[idx][1]) {
        write(con->fd_list[idx], M200, strlen(M200));
        return (USAGE);
    }
    for (size_t i = 0; con->path_list[idx][i]; i++)
        last_slash = con->path_list[idx][i] == 47 ? i : last_slash;
    if (last_slash == 0)
        con->path_list[idx][1] = 0;
    else
        con->path_list[idx][last_slash] = 0;
    write(con->fd_list[idx], M200, strlen(M200));
    (void) full_buff;
    return (USAGE);
}