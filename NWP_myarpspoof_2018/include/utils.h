/*
** EPITECH PROJECT, 2019
** utils.h
** File description:
** utils functions header
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include "spoof.h"

/* macros */
#define EXIT_FAIL 84
#define EXIT_SUCCESS 0

#define CONNEXIONS 1024
#define MAX_PORT 65535

/* utils.c */
int puterr(const char *str);
int is_string_number(const char *str);
int mac_to_unsigned(parameters_t *p, const char *address);

#endif /* !UTILS_H_ */
