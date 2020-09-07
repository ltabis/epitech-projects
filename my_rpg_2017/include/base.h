/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef PROTO_H_
#define PROTO_H_

int my_strcmp(char *, char *);
int my_strrevcmp(const char *, const char *, unsigned int);
char *my_strndup(char *, unsigned int);
unsigned int my_strlen(char *);
int my_getnbr(char *);
char *my_strcat(char const *, char const *);
void my_revstr(char *);

#endif /* !PROTO_H_ */
