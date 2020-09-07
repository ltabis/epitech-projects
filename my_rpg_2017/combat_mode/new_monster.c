/*
** EPITECH PROJECT, 2018
** new_monster.c
** File description:
** creating a new monster
*/

#include "../include/monster.h"
#include "../include/base.h"
#include <stdlib.h>

monster_t *create_new_monster(monster_t *monsters)
{
	monster_t *new = malloc(sizeof(monster_t));

	if (!new || !(new->spr = sfSprite_create()))
		return (NULL);
	sfSprite_setOrigin(new->spr, (sfVector2f){50, 100});
	new->current_hp = -1;
	new->current_sp = -1;
	new->current_st = -1;
	new->max_hp = -1;
	new->max_sp = -1;
	new->max_st = -1;
	new->att = -1;
	new->def = -1;
	new->spd = -1;
	new->txt = NULL;
	new->next = NULL;
	new->next = monsters;
	monsters->next = new;
	return (new);
}

sfTexture *clean_texture(char *line)
{
	char *texture = NULL;
	sfTexture *new = NULL;
	unsigned int i = 0;

	for (; line[i] == '\t' ||
	line[i] == ' ' || line[i] == '}'; i++);
	for (unsigned int j = 0; line[j]; j++)
		line[j] = line[j] == '\n' ? 0 : line[j];
	texture = &line[i];
	new = sfTexture_createFromFile(texture, NULL);
	return (new);
}

void fill_stat(monster_t *monster, char *line)
{
	char *new_line = clear_and_copy(line);
	char *stat_name = separate_stats(new_line);
	char *stat_value = NULL;

	for (; new_line[0] && new_line[0] != ' ' &&
	new_line[0] != '\t'; new_line++);
	new_line = clear_and_copy(new_line);
	stat_value = separate_stats(new_line);
	compare_stats(stat_name, stat_value, monster);
}

char *clear_and_copy(char *line)
{
	unsigned int i = 0;
	char *new_line = NULL;

	for (; line[i] && (line[i] == ' ' || line[i] == '\t'); i++);
	new_line = &line[i];
	return (new_line);
}

char *separate_stats(char *line)
{
	unsigned int i = 0;
	char *value = NULL;

	for (; line[i] && line[i] != ' ' && line[i] != '\t'; i++);
	value = my_strndup(line, i);
	return (value);
}
