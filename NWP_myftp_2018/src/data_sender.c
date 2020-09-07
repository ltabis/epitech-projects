/*
** EPITECH PROJECT, 2019
** data_sender.hpp
** File description:
** data_sender class
*/

#include <fcntl.h>
#include "ftp.h"

void exec_ls(char *full_buff, connexion_t *con, size_t idx)
{
    int fd = 0;
    char *argv[4];
    char *path;
    char *real_path = NULL;

    cut_command(&full_buff, 5);
    full_buff[0] = full_buff[0] == '\n' ? '.' : full_buff[0];
    real_path = create_path(full_buff, con, idx);
    if (!(path = realpath(real_path, NULL)))
        exit(EXIT_FAIL);
    fd = accept_socket(con->data_list[idx]);
    free(real_path);
    argv[0] = "/bin/ls";
    argv[1] = "-la";
    argv[2] = path;
    argv[3] = NULL;
    dup2(fd, 1);
    close(fd);
    if (execve(argv[0], argv, con->env) == -1)
        exit(EXIT_FAIL);
}

int check_file(char *full_buff, connexion_t *con, size_t idx)
{
    FILE *fd = NULL;
    char *path = NULL;
    char *real_path = NULL;

    real_path = create_path(full_buff, con, idx);
    if (!(path = realpath(real_path, NULL)))
        return (EXIT_FAIL);
    free(real_path);
    if (!(fd = fopen(path, "r")))
        return (EXIT_FAIL);
    free(path);
    fclose(fd);
    return (EXIT_SUCCESS);
}

void download_data(char *full_buff, connexion_t *con, size_t idx)
{
    int fd = 0;
    FILE *fp = NULL;
    char *path = NULL;
    char *real_path = NULL;
    size_t len = 0;

    real_path = create_path(full_buff, con, idx);
    path = realpath(real_path, NULL);
    free(real_path);
    fp = fopen(path, "r");
    free(path);
    write(con->fd_list[idx], M150, strlen(M150));
    fd = accept_socket(con->data_list[idx]);
    for (path = NULL; getline(&path, &len, fp) > 0;)
        write(fd, path, strlen(path));
    write(con->fd_list[idx], M226, strlen(M226));
    close(fd);
    fclose(fp);
}

char *check_file_creation(char *full_buff, connexion_t *con, size_t idx)
{
    int fd = 0;
    char *path = NULL;
    char *file_name = NULL;
    char *real_path = create_path(full_buff, con, idx);
    size_t idx_slash = 0;

    for (size_t i = 0; real_path[i]; i++)
        idx_slash = real_path[i] == 47 ? i : idx_slash;
    file_name = strdup(&real_path[idx_slash + 1]);
    real_path[idx_slash] = 0;
    if (!(path = realpath(real_path, NULL)))
        return (NULL);
    free(real_path);
    real_path = my_concat(path, my_concat("/", file_name));
    if (!(fd = open(real_path, O_CREAT, S_IRUSR | S_IWUSR |
    S_IRGRP | S_IWGRP | S_IROTH)))
        return (NULL);
    free(path);
    close(fd);
    return (real_path);
}

void create_file(connexion_t *con, size_t idx, char *file)
{
    int fd = open(file, O_WRONLY);
    int fdread = 0;
    FILE *fdata = NULL;
    size_t len = 0;

    free(file);
    write(con->fd_list[idx], M150, strlen(M150));
    fdread = accept_socket(con->data_list[idx]);
    fdata = fdopen(fdread, "r");
    for (file = NULL; getline(&file, &len, fdata) > 0;)
        write(fd, file, strlen(file));
    write(con->fd_list[idx], M226, strlen(M226));
    close(fd);
    close(fdread);
    fclose(fdata);
}