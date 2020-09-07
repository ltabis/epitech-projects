/*
** EPITECH PROJECT, 2018
** monster_parser.c
** File description:
** parsing monster scripts
*/

#include "../include/monster.h"
#include "../include/base.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

monster_t *parse_monsters(void)
{
	monster_t *monsters = malloc(sizeof(monster_t));
	monster_t *first = monsters;
	DIR *dir = opendir("monsters");
	struct dirent *file = NULL;

	if (!monsters || !dir)
		return (NULL);
	monsters->spr = NULL;
	file = readdir(dir);
	for (; file; file = readdir(dir))
		if (my_strrevcmp((char *)file->d_name, ".mstr", 5) == 0)
			monsters =
			fill_monster_stats((char *)file->d_name, monsters);
	create_new_monster(monsters);
	return (closedir(dir) == -1 ? NULL : first->next);
}

monster_t *fill_monster_stats(char *name, monster_t *monsters)
{
	FILE *stream = fopen(my_strcat("monsters/", name), "r");
	char *line = NULL;
	size_t len = 0;

	if (!stream)
		return (NULL);
	while (getline(&line, &len, stream) != -1) {
		if (check_brace(line, 0) == 1)
			monsters = add_stats_to_monster(line, stream, monsters);
		line = NULL;
	}
	free(line);
	return (monsters);
}

int check_brace(char *line, int mode)
{
	unsigned int i = 0;

	if (mode == 0) {
		for (; line[i] && line[i] != '{'; i++);
		return (my_strlen(line) == i ? 0 : 1);
	} else {
		for (; line[i] && line[i] != '}'; i++);
		return (my_strlen(line) == i ? 0 : 1);
	}
	return (0);
}

monster_t *add_stats_to_monster(char *line, FILE *stream,
	monster_t *monsters)
{
	monster_t *new = create_new_monster(monsters);
	size_t len = 0;

	if (!new)
		return (NULL);
	while (getline(&line, &len, stream) != -1) {
		if (check_brace(line, 1) == 1) {
			if ((new->txt = clean_texture(line))) {
				sfSprite_setTexture(new->spr, new->txt, 0);
				return (new);
			}
			return (NULL);
		}
		fill_stat(new, line);
		line = NULL;
	}
	return (NULL);
}

unsigned int count_monsters(monster_t *monsters)
{
	unsigned int nbr_monsters = 0;

	for (; monsters->current_hp != -1;
	nbr_monsters++, monsters = monsters->next);
	return (nbr_monsters);
}
