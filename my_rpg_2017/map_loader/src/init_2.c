/*
** EPITECH PROJECT, 2018
** init_2.c
** File description:
** initialisation
*/

#include <stdlib.h>
#include <fcntl.h>
#include "map.h"
#include "my.h"

int is_first(char *str)
{
	int i = 0;

	for (; str[i] != ','; i++);
	i++;
	for (; str[i] != ',' && str[i]; i++);
	if (str[i] == '\0')
		return (1);
	i++;
	if (str[i] == '0')
		return (0);
	return (1);
}

void init_starter(tab_map_t *tab_map, int i, int j)
{
	if (is_first(tab_map->tab[i][j]) == 0) {
		tab_map->pos_x = j;
		tab_map->pos_y = i;
	}
}

tab_map_t *init_tab_map(char *str)
{
	tab_map_t *tab_map = malloc(sizeof(tab_map_t));

	tab_map->tab = init_tab(&tab_map->size_x, &tab_map->size_y, str);
	tab_map->first = '0';
	tab_map->decal_x = 0;
	tab_map->decal_y = 0;
	for (int i = 0; i < tab_map->size_y; i++) {
		for (int j = 0; j < tab_map->size_x; j++)
			init_starter(tab_map, i, j);
	}
	return (tab_map);
}

map_t ***init_map(tab_map_t *tab_map)
{
	map_t ***map = malloc(sizeof(map_t *) * tab_map->size_y);

	for (int i = 0; i < tab_map->size_y; i++) {
		map[i] = malloc(sizeof(map_t *) * tab_map->size_x);
		for (int j = 0; j < tab_map->size_x; j++)
			map[i][j] = malloc(sizeof(map_t));
	}
	return (map);
}

int get_pos_x(tab_map_t *tab_map, int i, int j)
{
	return (my_getnbr(tab_map->tab[i][j]));
}

