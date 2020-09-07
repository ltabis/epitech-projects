/*
** EPITECH PROJECT, 2018
** create_map.c
** File description:
** creating the 3D map
*/

#include "../include/combat.h"

sfVector2f **create_2d_map(void)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * MAP_SIZE);

	if (!map_2d)
		return (NULL);
	for (unsigned int y = 0; y < MAP_SIZE; y++) {
		map_2d[y] = malloc(sizeof(sfVector2f) * MAP_SIZE);
		if (!map_2d[y])
			return (NULL);
		for (unsigned int x = 0; x < MAP_SIZE; x++)
			map_2d[y][x] =
			project_iso_point(x * MAP_ZOOM, y * MAP_ZOOM, 0);
	}
	return (map_2d);
}

tiles_t **create_random_tiles(monster_t *monsters)
{
	tiles_t **tiles = malloc(sizeof(tiles_t *) * 20);
	unsigned int nbr_monsters = count_monsters(monsters);

	if (!tiles)
		return (NULL);
	for (unsigned int i = 0; i < 19; i++) {
		tiles[i] = malloc(sizeof(tiles_t) * 20);
		if (!tiles[i])
			return (NULL);
		for (unsigned int j = 0; j < 19; j++) {
			choose_tile_type(&tiles[i][j]);
			choose_monsters(&tiles[i][j], monsters, nbr_monsters);
		}
	}
	tiles[19] = NULL;
	tiles[rand() % 18][rand() % 18].entity = 2;
	return (tiles);
}

sfRenderStates set_state(sfTexture *tilemap)
{
	sfRenderStates state;
	sfTexture *text =
	sfTexture_createFromFile("sprites/plain/tm_ground.png", NULL);

	tilemap = tilemap;
	state.texture = text;
	state.shader = NULL;
	state.blendMode = sfBlendAlpha;
	state.transform = sfTransform_Identity;
	return (state);
}

void update_2d_map(map_cb_t *map)
{
	for (unsigned int y = 0; y < MAP_SIZE; y++) {
		for (unsigned int x = 0; x < MAP_SIZE; x++) {
			map->map_2d[y][x] = project_iso_point(
			x * map->map_zoom + map->map_pos.x,
			y * map->map_zoom + map->map_pos.y, 0);
		}
	}
}

void set_trees(map_cb_t map, sfVector2i decal, sfRenderWindow *w)
{
	sfVector2f vect = {map.map_2d[decal.y][decal.x].x,
	map.map_2d[decal.y][decal.x].y + map.map_zoom / 2};
	sfIntRect rect = {0, 0, 100, 100};
	sfVector2f fact = {map.map_zoom / 60, map.map_zoom / 60};
	e_tile_type env[] = {FOLLIAGE, TREE};
	unsigned int i = 0;

	for (; i < 2 && env[i] != map.tiles[decal.y][decal.x].type; i++);
	if (i < 2) {
		rect.left += i * 100;
		sfSprite_setTextureRect(map.ter_spr, rect);
		sfSprite_setPosition(map.ter_spr, vect);
		sfSprite_setScale(map.ter_spr, fact);
		sfRenderWindow_drawSprite(w, map.ter_spr, NULL);
	}
	if (map.tiles[decal.y][decal.x].entity > 0)
		display_entity(&map, &decal, w, &vect);
}
