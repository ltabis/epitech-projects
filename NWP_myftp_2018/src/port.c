/*
** EPITECH PROJECT, 2019
** port.c
** File description:
** port file
*/

#include "ftp.h"

int check_valid_port(char *full_buff, connexion_t *con, size_t idx)
{
    size_t comma = 0;
    size_t port = 0;

    for (; full_buff[comma] && full_buff[comma] != ','; comma++);
    full_buff[comma] = 0;
    if (is_string_number(full_buff) == EXIT_FAIL)
        return (EXIT_FAIL);
    if (is_string_number(&full_buff[comma + 1]) == EXIT_FAIL)
        return (EXIT_FAIL);
    port = atoi(full_buff) * 256 + atoi(&full_buff[comma + 1]);
    if (con->data_list[idx]) {
        close(con->data_list[idx]);
        con->data_list[idx] = 0;
    }
    con->data_list[idx] = create_new_socket();
    if (con->data_list[idx] == EXIT_FAIL ||
    port >= MAX_PORT || bind_socket(con->data_list[idx], port)
    == EXIT_FAIL || listen_socket(con->data_list[idx]) == EXIT_FAIL)
        return (EXIT_FAIL);
    return (EXIT_SUCCESS);
}

int check_valid_address(char *full_buff, connexion_t *con, size_t idx)
{
    char *ip[] = {"127", "0", "0", "1"};
    size_t commas = 0;
    size_t c = 0;

    for (size_t i = 0; full_buff[i]; i++)
        commas += full_buff[i] == ',' ? 1 : 0;
    if (commas != 5)
        return (EXIT_FAIL);
    for (size_t i = 0, valid = 0; valid != 4 && full_buff[i];) {
        for (; full_buff[c] != ','; c++);
        if (!strncmp(&full_buff[i], ip[valid], c - i)) {
            valid++;
            i = ++c;
        } else
            return (EXIT_FAIL);
    }
    return (check_valid_port(&full_buff[c], con, idx));
}