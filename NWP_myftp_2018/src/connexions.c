/*
** EPITECH PROJECT, 2019
** connexions.hpp
** File description:
** connexions class
*/

#include "ftp.h"

/*
* close_connexion -> connexion_t * -> size_t
* close current connexion when needed.
*/

void close_connexion(connexion_t *con, size_t i)
{
    close(con->fd_list[i]);
    if (con->data_list[i])
        close(con->data_list[i]);
    con->fd_list[i] = 0;
    con->log_list[i] = 0;
    if (con->path_list[i])
        free(con->path_list[i]);
    con->path_list[i] = strdup(con->default_path);
}

/*
* init_buffers -> connexion_t * -> const char *path
* initialise buffers for the connexion struct.
*/

void init_buffers(connexion_t *con, char * const *env)
{
    for (size_t i = 0; i < CONNEXIONS; i++) {
        con->data_list[i] = 0;
        con->log_list[i] = 0;
        con->fd_list[i] = 0;
        con->path_list[i] = strdup(con->default_path);
    }
    con->env = env;
}

/*
* my_revstr -> char *
* reverse a string.
*/

char *my_revstr(char *str)
{
    unsigned int i = 0;
    char save = 0;

    if (!str)
        return (NULL);
    i = strlen(str);
    for (unsigned int count = 0; count != i / 2; count++) {
        save = str[count];
        str[count] = str[i - count - 1];
        str[i - count - 1] = save;
    }
    return (str);
}

/*
* my_itoa -> int
* convert an int to a string.
*/

char *my_itoa(int nbr)
{
    unsigned int i = 1;
    char *str = NULL;
    char sign = nbr >= 0 ? 0 : 1;

    nbr *= sign == 1 ? -1 : 1;
    for (int tmp = nbr; tmp >= 10; tmp /= 10, i++);
    str = malloc(sizeof(char) * (i + sign + 1));
    if (!str)
        return (NULL);
    str[0] = (nbr % 10) + '0';
    for (i = 1; nbr >= 10; i++) {
        nbr = nbr / 10;
        str[i] = (nbr % 10) + '0';
    }
    if (sign == 1)
        str[i++] = '-';
    str[i] = 0;
    my_revstr(str);
    return (str);
}

/*
* write_pasv -> connexion_t * -> size_t -> size_t
* writes the port for the pasv command
*/

int write_pasv(connexion_t *con, size_t idx, size_t port)
{
    char *p1 = NULL;
    char *p2 = NULL;

    if (!(p1 = my_itoa(port / 256)) || !(p2 = my_itoa(port % 256)))
        return (EXIT_FAIL);
    write(con->fd_list[idx], M227, strlen(M227));
    write(con->fd_list[idx], "(127,0,0,1,", 11);
    write(con->fd_list[idx], p1, strlen(p1));
    write(con->fd_list[idx], ",", 1);
    write(con->fd_list[idx], p2, strlen(p2));
    write(con->fd_list[idx], ")\n", 2);
    free(p1);
    free(p2);
    return (USAGE);
}