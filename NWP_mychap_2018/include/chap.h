/*
** EPITECH PROJECT, 2019
** chap.hpp
** File description:
** chap class
*/

#ifndef chap_H
#define chap_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* macros */
#define EXIT_FAIL 84
#define EXIT_SUCCESS 0
#define CONNEXIONS 1024
#define PCKT_LEN 8192

/* structs */
typedef struct e_parameters {
    char *target;
    unsigned int port;
    char *password;
} parameters_t;

/* socket.c */
int bind_socket(int, uint16_t);
int set_socket(int);
int create_raw_socket(void);

/* argument_parsing.c */
parameters_t *check_args(int ac, const char * const *av);

/* run.c */
int run_client(parameters_t *parameters);

/* fill_parameters.c */
int append_target(parameters_t *parameters, const char *param);
int append_port(parameters_t *parameters, const char *param);
int append_password(parameters_t *parameters, const char *param);

/* packets.c */
void send_package_to(int, char *, char *, parameters_t *);
char *receive_package_from(int, parameters_t *);
struct iphdr *create_ip_wrap(char *buffer, char *message,
parameters_t *parameters);
struct udphdr *create_udp_wrap(char *buffer, char *message,
parameters_t *parameters);
char *catch_correct_packet(int socket, parameters_t *parameters);

/* utils.c */
int puterr(const char *str);
int is_string_number(const char *str);
void cleanup_parameter(parameters_t *parameters);

/* debug.c*/
void print_parameters_content(parameters_t *parameters);
void display_result(char *response);

#endif /* !chap_H */
