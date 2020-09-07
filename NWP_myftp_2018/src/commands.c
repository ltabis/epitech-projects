/*
** EPITECH PROJECT, 2019
** commands.c
** File description:
** commands handling
*/

#include "ftp.h"

/* Function pointer */

int (* const func[14])(char *, connexion_t *, size_t) = {cmd_cdup, cmd_dele,
cmd_pwd, cmd_pasv, cmd_port, cmd_help, cmd_noop, cmd_retr, cmd_stor,
cmd_list};

/* Commands */

const char *cmd[] = {"CDUP", "DELE", "PWD", "PASV",
"PORT", "HELP", "NOOP", "RETR", "STOR", "LIST", NULL};

/*
* check_special_cases -> char * -> connexion_t * -> size_t
* Check commands that doesn't need logging.
*/

int check_special_cases(char *full_buff, connexion_t *con, size_t idx)
{
    if (!strncasecmp("QUIT\r\n", full_buff, strlen("QUIT\r\n")))
        return (cmd_quit(con->fd_list[idx]));
    if (!strncasecmp("USER", full_buff, 4))
        return (cmd_user(full_buff, con, idx));
    if (!strncasecmp("PASS", full_buff, 4)
    && (!full_buff[4] || full_buff[4] == '\r' || full_buff[4] == ' '))
        return (cmd_pass(con, idx));
    if (!strncasecmp("CWD", full_buff, 3) && con->log_list[idx] == PASS)
        return (cmd_cwd(full_buff, con, idx));
    return (EXIT_SUCCESS);
}

/*
* process_command -> char * -> connexion_t * -> size_t
* cleaning command and executing it if valid
*/

int process_command(char *buf, connexion_t *con, size_t idx)
{
    unsigned int i = 0;
    int value = check_special_cases(buf, con, idx);

    my_clean_str(buf);
    if (value > EXIT_SUCCESS)
        return (value);
    for (value = 0; cmd[i] && !value; i++)
        if ((!strncasecmp(cmd[i], buf, strlen(cmd[i])) &&
        con->log_list[idx] == 2))
            value = (*(func[i]))(buf, con, idx);
    if (con->log_list[idx] != 2 && strcmp(buf, "\r\n") > 0)
        write(con->fd_list[idx], M530, strlen(M530));
    else if (!value && con->log_list[idx] == 2 && strcmp(buf, "\r\n") > 0)
        write(con->fd_list[idx], M500, strlen(M500));
    return (EXIT_SUCCESS);
}

int check_default_path(connexion_t *con, const char *path)
{
    con->default_path = realpath(path, NULL);

    if (!con->default_path)
        return (puterr("Error : path specified invalid.\n"));
    return (EXIT_SUCCESS);
}

char *my_concat(char const *s1, char const *s2)
{
    unsigned int len_s1 = strlen(s1);
    unsigned int len_s2 = strlen(s2);
    unsigned int index = 0;
    char *str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));

    if (!str || !s1 || !s2)
        return (NULL);
    str[len_s1 + len_s2] = 0;
    for (unsigned int i = 0; s1[i]; i++, index++)
        str[index] = s1[i];
    for (unsigned int i = 0; s2[i]; i++, index++)
        str[index] = s2[i];
    str[index] = 0;
    return (str);
}

char *create_path(char *full_buff, connexion_t *con, size_t idx)
{
    char *primary_path = NULL;
    char *new_path = NULL;

    if (full_buff[0] == '/' || full_buff[0] == '~') {
        primary_path = strdup(full_buff);
        return (primary_path);
    }
    primary_path = my_concat(con->path_list[idx], "/");
    new_path = my_concat(primary_path, full_buff);
    free(primary_path);
    return (new_path);
}