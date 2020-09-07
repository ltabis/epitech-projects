/*
** EPITECH PROJECT, 2019
** ex00.c
** File description:
** ex00
*/

#include "ex00.h"

static void koala_initializer(koala_t *, char *, char);
static void cthulhu_initializer(cthulhu_t *);

void print_power(cthulhu_t *this)
{
        if (this)
                printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
        if (this) {
                if (this->m_power >= 42) {
                        printf("%s attacks and destroys the city\n",
                        this->m_name);
                        this->m_power -= 42;
                } else
                        printf("%s can't attack, he doesn't have enough power\n",
                        this->m_name);
        }
}

void sleeping(cthulhu_t *this)
{
        if (this) {
                printf("%s sleeps\n", this->m_name);
                this->m_power += 42000;
        }
}

cthulhu_t *new_cthulhu(void)
{
        cthulhu_t *new = malloc(sizeof(cthulhu_t));

        if (!new)
                return (NULL);
        cthulhu_initializer(new);
        return (new);
}

void eat(koala_t *this)
{
        if (this && this->m_parent.m_name) {
                printf("%s eats\n", this->m_parent.m_name);
                this->m_parent.m_power += 42;
        }
}

koala_t *new_koala(char *name, char is_a_legend)
{
        koala_t *new = malloc(sizeof(koala_t));

        if (!new)
                return (NULL);
        koala_initializer(new, name, is_a_legend);
        return (new);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
        this->m_parent = *new_cthulhu();
        if (this->m_parent.m_name)
                free(this->m_parent.m_name);
        this->m_parent.m_name = strdup(_name);
        if (!this->m_parent.m_name)
                return;
        this->m_is_a_legend = _is_A_Legend;
        this->new_koala = &new_koala;
        this->eat = &eat;
        if (_is_A_Legend == 0) {
                this->m_parent.m_power = 0;
                printf("Building NotLegend\n");
        } else
                printf("Building Legend\n");
}

static void cthulhu_initializer(cthulhu_t *this)
{
        this->m_power = 42;
        this->m_name = strdup("Cthulhu");
        this->new_cthulhu = &new_cthulhu;
        this->print_power = &print_power;
        this->attack = &attack;
        this->sleeping = &sleeping;
        printf("----\nBuilding Cthulhu\n");
}
