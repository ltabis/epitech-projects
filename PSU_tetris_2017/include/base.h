/*
** EPITECH PROJECT, 2017
** base.h
** File description:
** prototypes for the tetris progam
*/

#ifndef BASE_H_
#define BASE_H_

#include "tetris.h"
#include "get_next_line.h"

char *my_strndup(char *, unsigned int);
int my_getnbr(char *);
int my_getnbr_no_char(char *);
int my_strcmp(char *, char *);
int my_strncmp(char const *, char const *, int);
void my_put_nbr(int);
void my_putchar(int);
char *my_strncpy(char *, char *, int);
char *my_strcpy(char *, char *);
int my_strlen(char *);
void my_putstr(char *str);

#endif /* !BASE_H_ */