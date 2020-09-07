/*
** EPITECH PROJECT, 2018
** instatiation.c
** File description:
** functions that will instantiate random or predefined objects
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/proto.h"

map_t *display_map_objects(map_t *map, sfRenderWindow *window, sfClock *clock)
{
	sfVector2f pos;
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 1000000.0;

	pos.y = 0;
	for (; map->prev != 0; map = map->prev) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		pos.x = -10 * map->obj.speed;
		if (map->obj.type == 'E' && seconds > 0.1)
			map->obj = move_sprite(map->obj);
		sfSprite_move(map->obj.spr, pos);
		sfSprite_setTexture(map->obj.spr, map->obj.txt, 0);
		sfRenderWindow_drawSprite(window, map->obj.spr, NULL);
	}
	for (; map->next != 0; map = map->next);
	return (map);
}

map_t *create_object_list(char type, map_t *map, int height, int widht)
{
	map_t *tmp = malloc(sizeof(map_t));
	int stop = 0;
	int  i = 0;

	if (!tmp)
		return (NULL);
	tmp->obj = create_object_env(type, height, widht);
	if (tmp->obj.initialisation == 1)
		return (NULL);
	tmp->next = 0;
	tmp->prev = map;
	map->next = tmp;
	map = tmp;
	return (map);
}

object_t create_object_env(char type, int height, int width)
{
	object_t obj;
	sfVector2f pos;
	char *find_texture = select_texture(type);

	obj.initialisation = 1;
	obj.type = type;
	height = 10 - height;
	pos.x = 1980 + width * 108;
	pos.y = -height * 108 + 888;
	obj.speed = 1;
	obj.spr = sfSprite_create();
	obj.txt = sfTexture_createFromFile(find_texture, NULL);
	if (!obj.spr || !obj.txt)
		return (obj);
	if (type == 'E')
		obj = create_rect(obj);
	sfSprite_setTexture(obj.spr, obj.txt, 0);
	sfSprite_setPosition(obj.spr, pos);
	obj.initialisation = 0;
	return (obj);
}

char *select_texture(char type)
{
	int i = 0;
	char *filepath;
	char all_types[] = "T^=|E";
	char *(*select_filepath[5])(void) = {inst_block, inst_spike,
	inst_floor, inst_finish, inst_ennemie};

	for (; all_types[i] != '\0' && all_types[i] != type; i++);
	if (i == 5)
		return (NULL);
	filepath = (*select_filepath[i])();
	return (filepath);
}
