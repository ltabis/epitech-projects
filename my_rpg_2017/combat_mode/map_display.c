/*
** EPITECH PROJECT, 2018
** map_display.c
** File description:
** functions that will display the 3d map
*/

#include "../include/combat.h"

void draw_2d_map(sfRenderWindow *w, map_cb_t map,
		sfVector2i lims, sfRenderStates state)
{
	sfVector2i decal = {0, 0};

	for (char trig = 0; decal.y < lims.y; decal.y++) {
		for (decal.x = 0; decal.x < lims.x; decal.x++) {
			check_display_on_x_axes(decal, lims, map, w);
			check_display_on_y_axes(decal, lims, map, w);
			trig = decal.x + 1 < lims.x &&
			decal.y + 1 < lims.y ? 1 : 0;
			trig == 1 ?
			check_display_on_both_axes(
			decal, map, w, state) : 0;
		}
	}
	sfSprite_rotate(map.hud->arrow, 1.01);
	sfRenderWindow_drawSprite(w, map.hud->clock, NULL);
	sfRenderWindow_drawSprite(w, map.hud->arrow, NULL);
	sfRenderWindow_drawSprite(w, map.hud->hud, NULL);
}

sfVector2f project_iso_point(int x, int y, int z)
{
	sfVector2f vect_2d = {0, 0};
	float angle_x = 35 * (PI / 180);
	float angle_y = 25 * (PI / 180);

	x += 800;
	y -= 400;
	vect_2d.x = cos(angle_x) * x - cos(angle_x) * y;
	vect_2d.y = sin(angle_y) * y + sin(angle_y) * x - z;
	return (vect_2d);
}

sfVertexArray *create_tiles(map_cb_t *map, sfVector2i decal)
{
	int type_cpy = map->tiles[decal.y][decal.x].type * 100;

	type_cpy = choose_special_tile(&map->tiles[decal.y][decal.x], type_cpy);
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = map->map_2d[decal.y][decal.x],
	.color = sfWhite, .texCoords = {type_cpy, 0}};
	sfVertex vertex2 = {.position = map->map_2d[decal.y][decal.x + 1],
	.color = sfWhite, .texCoords = {type_cpy + 100, 0}};
	sfVertex vertex3 = {.position = map->map_2d[decal.y + 1][decal.x],
	.color = sfWhite, .texCoords = {type_cpy, 100}};
	sfVertex vertex4 = {.position = map->map_2d[decal.y + 1][decal.x + 1],
	.color = sfWhite, .texCoords = {type_cpy + 100, 100}};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesStrip);
	return (vertex_array);
}

sfVertexArray *create_lines(sfVector2f *point1, sfVector2f *point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = *point1, .color = sfWhite};
	sfVertex vertex2 = {.position = *point2, .color = sfWhite};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

void draw_tile_lines(sfVector2f **map_2d,
	sfVector2i decal, sfVector2i next, sfRenderWindow *window)
{
	sfVertexArray *ver_1 = NULL;

	ver_1 = create_lines(
	&map_2d[decal.y][decal.x], &map_2d[decal.y + next.y][decal.x + next.x]);
	sfRenderWindow_drawVertexArray(window, ver_1, NULL);
	sfVertexArray_destroy(ver_1);
}
