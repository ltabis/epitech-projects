/*
** EPITECH PROJECT, 2018
** utils_2.c
** File description:
** antoher utils fucntions
*/

#include "../include/combat.h"
#include "../include/base.h"

monster_t *create_new_monster_entity(monster_t *monsters)
{
	monster_t *new = malloc(sizeof(monster_t));

	if (!new || !(new->spr = sfSprite_create()))
		return (NULL);
	sfSprite_setOrigin(new->spr, (sfVector2f){50, 100});
	new->current_hp = monsters->current_hp;
	new->current_sp = monsters->current_sp;
	new->current_st = monsters->current_st;
	new->max_hp = monsters->max_hp;
	new->max_sp = monsters->max_sp;
	new->max_st = monsters->max_st;
	new->att = monsters->att;
	new->def = monsters->def;
	new->spd = monsters->spd;
	new->txt = NULL;
	new->next = NULL;
	sfSprite_setTexture(new->spr, monsters->txt, 0);
	return (new);
}

int choose_special_tile(tiles_t *tile, int decal)
{
	if (tile->cursor == 1)
		decal = 900;
	else if (tile->entity == 1)
		decal = 700;
	else if (tile->entity == 2)
		decal = 800;
	return (decal);
}

void choose_tile_type(tiles_t *tile)
{
	tile->cursor = 0;
	tile->entity = rand() % 10;
	tile->entity =
	tile->entity == 1 && rand() % 3 == 2 ? 1 : 0;
	tile->type = tile->entity == 1 ? rand() % 5 : rand() % 7;
}

void display_entity(map_cb_t *map, sfVector2i *decal,
	sfRenderWindow *w, sfVector2f *vect)
{
	sfVector2f fact = {map->map_zoom / 60, map->map_zoom / 60};

	change_color(map, decal);
	if (map->tiles[decal->y][decal->x].entity == 1 &&
	map->tiles[decal->y][decal->x].ptr->current_hp > 0) {
		sfSprite_setPosition(
		map->tiles[decal->y][decal->x].ptr->spr, *vect);
		sfSprite_setScale(
		map->tiles[decal->y][decal->x].ptr->spr, fact);
		sfRenderWindow_drawSprite(w,
		map->tiles[decal->y][decal->x].ptr->spr, NULL);
	} else {
		sfSprite_setPosition(map->perso,
		(sfVector2f){(*vect).x + 35, (*vect).y});
		sfSprite_setScale(map->perso, (sfVector2f){fact.x * 2,
		fact.y * 2});
		sfRenderWindow_drawSprite(w, map->perso, NULL);
	}
}
