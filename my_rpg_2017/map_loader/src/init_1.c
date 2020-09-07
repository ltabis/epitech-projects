/*
** EPITECH PROJECT, 2018
** init_1.c
** File description:
** initialisation
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "map.h"
#include "my.h"
#include "proto.h"

char *until_space(char const *c)
{
	int i = 0;
	char *result = NULL;

	for (; c[i] != ' '; i++);
	result = malloc(sizeof(char) * (i+ 1));
	for (int j = 0; c[j] != ' '; j++)
		result[j] = c[j];
	result[i] = '\0';
	return (result);
}

char *get_next(char *c)
{
	for (; *c != ' '; c++);
	c++;
	return (c);
}

char ***fill_tab(char ***tab, int x, int y, int fd)
{
	char *c = NULL;

	for (int i = 0; i < y; i++) {
		c = get_next_line(fd);
		for (int j = 0; j < x && c != NULL && c[0] != '-'; j++) {
			tab[i][j] = until_space(c);
			c = get_next(c);
		}
	}
	return (tab);
}

char ***init_tab(int *x, int *y, char *str)
{
	char *c = NULL;
	char ***tab = NULL;
	int fd = open(str, O_RDONLY);

	c = get_next_line(fd);
	*x = my_getnbr(c);
	*y = my_getnbr(get_next(c));
	tab = malloc(sizeof(char *) * (*y + 1));
	for (int i = 0; i < *y; i++) {
		tab[i] = malloc(sizeof(char *) * (*x));
		for (int j = 0; j < *y; j++)
			tab[i][j] = NULL;
	}
	tab = fill_tab(tab, *x, *y, fd);
	return (tab);
}

void init_npcs(map_all_t *map)
{
	sfIntRect rect = {0, 0, 35, 35};
	sfIntRect rect_obj = {0, 0, 100, 100};

	map->spr_npcs = malloc(sizeof(sfSprite *) * 3);
	map->txt_npcs = sfTexture_createFromFile(
	"ressources/pictures/menu/main_menu/npcs.png", NULL);
	for (unsigned int i = 0; i < 3; i++, rect.left += 105) {
		map->spr_npcs[i] = sfSprite_create();
		sfSprite_scale(map->spr_npcs[i], (sfVector2f){2, 2});
		sfSprite_setTexture(map->spr_npcs[i], map->txt_npcs, 0);
		sfSprite_setTextureRect(map->spr_npcs[i], rect);
	}
	map->spr_obj = sfSprite_create();
	map->txt_obj = sfTexture_createFromFile(
	"ressources/pictures/objects/object.png", NULL);
	sfSprite_setTexture(map->spr_obj, map->txt_obj, 0);
	sfSprite_setTextureRect(map->spr_obj, rect_obj);
	init_move(map);
	map->rect = 0;
}
