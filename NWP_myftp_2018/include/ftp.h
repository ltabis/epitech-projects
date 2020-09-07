/*
** EPITECH PROJECT, 2019
** ftp.h
** File description:
** ftp header
*/

#ifndef FTP_H_
#define FTP_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"

/* structs */
typedef struct s_connexion {
    int control;
    int data;
    int fd_list[1024];
    int log_list[1024];
    int data_list[1024];
    fd_set rfds;
    char **path_list;
    char *default_path;
    char * const * env;
} connexion_t;

/* macros */
#define M120 "120 Service ready in nnn minutes.\n"
#define M125 "125 Data connection already open; transfer starting.\n"
#define M150 "150 File status okay; about to open data connection.\n"
#define M200 "200 Command okay.\n"
#define M214 "214 Help message.\n"
#define M220 "220 Service ready for new user.\n"
#define M221 "221 Service closing control connection.\n"
#define M226 "226 Closing data connection.\n"
#define M227 "227 Entering Passive Mode "
#define M230 "230 User logged in, proceed.\n"
#define M250 "250 Requested file action okay, completed.\n"
#define M257 "257 \"PATHNAME\" created.\n"
#define M331 "331 User name okay, need password.\n"
#define M332 "332 Need account for login.\n"
#define M421 "421 Timeout.\n"
#define M425 "425 Use PORT or PASV first.\n"
#define M500 "500 Unknown command.\n"
#define M503 "503 Login with USER first.\n"
#define M530 "530 Please login with USER and PASS.\n"
#define M550 "550 Failed to change directory.\n"

#define HELP " CDUP CWD DELE HELP LIST NOOP PASV PASS PORT PWD QUIT\n"\
" RETR STOR USER\n"

/* socket.c */
int setup_server(const char * const *, char * const *);
int create_new_socket(void);
int listen_socket(int);
int accept_socket(int);
int bind_socket(int, uint16_t);
int process_command(char *, connexion_t *, size_t);
int write_pasv(connexion_t *, size_t, size_t);
void close_connexion(connexion_t *, size_t);
void init_buffers(connexion_t *, char * const *);
int check_default_path(connexion_t *, const char *);
char *create_path(char *, connexion_t *, size_t);
int check_valid_address(char *, connexion_t *, size_t);

/* data_sender.c */
void exec_ls(char *, connexion_t *, size_t);
void download_data(char *, connexion_t *, size_t);
int check_file(char *, connexion_t *, size_t);
char *check_file_creation(char *, connexion_t *, size_t);
void create_file(connexion_t *, size_t, char *);

/* special commands.c */
int cmd_cwd(char *, connexion_t *, size_t);
int cmd_user(char *, connexion_t *, size_t);
int cmd_pass(connexion_t *, size_t);
int cmd_quit(int);

/* regular commands.c */
int cmd_pwd(char *, connexion_t *, size_t);
int cmd_cdup(char *, connexion_t *, size_t);
int cmd_dele(char *, connexion_t *, size_t);
int cmd_pasv(char *, connexion_t *, size_t);
int cmd_port(char *, connexion_t *, size_t);
int cmd_help(char *, connexion_t *, size_t);
int cmd_noop(char *, connexion_t *, size_t);
int cmd_retr(char *, connexion_t *, size_t);
int cmd_stor(char *, connexion_t *, size_t);
int cmd_list(char *, connexion_t *, size_t);

#endif /* !FTP_H_ */
