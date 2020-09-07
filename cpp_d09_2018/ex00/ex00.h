/*
** EPITECH PROJECT, 2019
** ex00.h
** File description:
** ex00
*/

#ifndef EX00_H_
#define EX00_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define UNUSED __attribute__ ((unused))

typedef struct s_cthulhu {
    int m_power;
    char *m_name;

    struct s_cthulhu *(*new_cthulhu)(void);
    void (*print_power)(struct s_cthulhu *);
    void (*attack)(struct s_cthulhu *);
    void (*sleeping)(struct s_cthulhu *);
} cthulhu_t;

typedef struct s_koala {
    cthulhu_t m_parent;
    char m_is_a_legend;

    struct s_koala *(*new_koala)(char *, char);
    void (*eat)(struct s_koala *);
} koala_t;

cthulhu_t *new_cthulhu(void);
void print_power(cthulhu_t *);
void attack(cthulhu_t *);
void sleeping(cthulhu_t *);
koala_t *new_koala(char *, char);
void eat(koala_t *this);

#endif /* !EX00_H_ */
