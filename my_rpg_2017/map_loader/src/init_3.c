/*
** EPITECH PROJECT, 2018
** init_3.c
** File description:
** initialisation
*/

#include <stdlib.h>
#include <fcntl.h>
#include "map.h"
#include "my.h"

int get_next_nd(char *str)
{
	for (; *str != ','; str++);
	str++;
	return (my_getnbr(str));
}

int get_option(char *str)
{
	for (; *str != ','; str++);
	str++;
	for (; *str != ','; str++);
	str++;
	return (my_getnbr(str));
}

int get_pos_y(tab_map_t *tab_map, int i, int j)
{
	return (get_next_nd(tab_map->tab[i][j]));
}

void init_sprite(map_t ***map, int i, int j, tab_map_t *tab_map)
{
	map[i][j]->rect.height = 100;
	map[i][j]->rect.width = 100;
	map[i][j]->rect.left = get_pos_x(tab_map, i, j);
	map[i][j]->rect.top = get_pos_y(tab_map, i, j);
	map[i][j]->option = get_option(tab_map->tab[i][j]);
	map[i][j]->sprite = sfSprite_create();
	map[i][j]->position.x = j * 100 + tab_map->decal_x - 100;
	map[i][j]->position.y = i * 100 + tab_map->decal_y - 100;
}
