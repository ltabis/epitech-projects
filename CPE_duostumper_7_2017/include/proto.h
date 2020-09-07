/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** prototypes
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int my_isnum(const char *);
int check_parameters(int, char * const *);
int parse_file(char *, int);
char *my_strcat(const char *, const char *);
void free_utils(char *, char *, char *, FILE *);
void apply_cesar_cipher(char *, int, int);
void change_upper_case(char *, int);
void change_lower_case(char *, int);
void change_line(char *, int);
int write_ciphered_string_into_file(char *, int);

#endif
