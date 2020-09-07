/*
** EPITECH PROJECT, 2019
** ftp.h
** File description:
** ftp header
*/

#ifndef SPOOF_H_
#define SPOOF_H_

#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/* structs */
typedef struct parameters_s {
    unsigned char *dest_ip;
    unsigned char *src_ip;
    unsigned char *dest_mac;
    char *src_mac;
    char *iface;
    char mode;
    char arp_type;
    char *dip;
    char *sip;
    int recvsock;
} parameters_t;

/* init.c */
int init_spoof_attack(parameters_t *p);
parameters_t *fill_parameters(const int ac, const char * const *av);
int get_mac_address(parameters_t *p);
void convert_to_array(unsigned char **ip);
void go_spoof(parameters_t *p, void *packet);

#endif /* !SPOOF_H_ */
