/*
** EPITECH PROJECT, 2018
** new_stat_2.c
** File description:
** monster stats part 2
*/

#include "../include/monster.h"
#include "../include/base.h"

void change_max_sp(char *stat_value, monster_t *monster)
{
	monster->max_sp = my_getnbr(stat_value);
}

void change_max_st(char *stat_value, monster_t *monster)
{
	monster->max_st = my_getnbr(stat_value);
}

void change_att(char *stat_value, monster_t *monster)
{
	monster->att = my_getnbr(stat_value);
}

void change_def(char *stat_value, monster_t *monster)
{
	monster->def = my_getnbr(stat_value);
}

void change_spd(char *stat_value, monster_t *monster)
{
	monster->spd = my_getnbr(stat_value);
}