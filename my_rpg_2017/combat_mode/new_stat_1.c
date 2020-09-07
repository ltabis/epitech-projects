/*
** EPITECH PROJECT, 2018
** new_stat_1.c
** File description:
** stat function for the monsters
*/

#include "../include/monster.h"
#include "../include/base.h"

monster_t *compare_stats(char *name, char *val, monster_t *monster)
{
	unsigned int i = 0;
	void (*change_stat[9])(char *, monster_t *) = {
		change_current_hp, change_current_sp, change_current_st,
		change_max_hp, change_max_sp, change_max_st,
		change_att, change_def, change_spd};
	char *stats[] = {
		"current_hp", "current_sp", "current_st",
		"max_hp", "max_sp", "max_st",
		"att", "def", "spd"};

	for (char trig = 0; i < 9 && trig != 1; i++)
		trig = my_strcmp(stats[i], name) == 0 ? 1 : 0;
	if (i - 1 < 9) {
		for (unsigned int i = 0; val[i]; i++)
			val[i] = val[i] == '\n' ? 0 : val[i];
		(*change_stat[i - 1])(val, monster);
	}
	return (monster);
}

void change_current_hp(char *stat_value, monster_t *monster)
{
	monster->current_hp = my_getnbr(stat_value);
}

void change_current_sp(char *stat_value, monster_t *monster)
{
	monster->current_sp = my_getnbr(stat_value);
}

void change_current_st(char *stat_value, monster_t *monster)
{
	monster->current_st = my_getnbr(stat_value);
}

void change_max_hp(char *stat_value, monster_t *monster)
{
	monster->max_hp = my_getnbr(stat_value);
}
