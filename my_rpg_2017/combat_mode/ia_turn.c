/*
** EPITECH PROJECT, 2018
** ia_turn.c
** File description:
** ia computing
*/

#include "../include/combat.h"

void compute_enemy_turn(map_cb_t *map, player_stat_t *player)
{
	unsigned int monsters = 0;
	sfVector2i *idxs = NULL;

	for (unsigned int i = 0; i < 19; i++)
		for (unsigned int j = 0; j < 19; j++)
			monsters += map->tiles[i][j].entity == 1 ? 1 : 0;
	if (!(idxs = malloc(sizeof(sfVector2i) * (monsters + 1))))
		return;
	for (unsigned int i = 0, idx = 0; i < 19; i++)
		for (unsigned int j = 0; j < 19; j++) {
			idxs[idx].x = map->tiles[i][j].entity == 1 ? j : 0;
			idxs[idx].y = map->tiles[i][j].entity == 1 ? i : 0;
			idx += map->tiles[i][j].entity == 1 ? 1 : 0;
		}
	idxs[monsters].x = -1;
	execute_monster_actions(idxs, map, player);
	free(idxs);
}

void execute_monster_actions(sfVector2i *idxs, map_cb_t *map,
	player_stat_t *player)
{
	int action = 0;

	for (unsigned int i = 0; idxs[i].x != -1; i++) {
		action = rand() % 2;
		if (action == 0)
			move_monster(&idxs[i], map);
		else if (action == 1 &&
		map->tiles[idxs[i].y][idxs[i].x].type != FOLLIAGE)
			search_for_prey_or_move(&idxs[i], map, player);
	}
}

void move_monster(sfVector2i *idx, map_cb_t *map)
{
	monster_t *monster = map->tiles[idx->y][idx->x].ptr;

	map->tiles[idx->y][idx->x].ptr = NULL;
	map->tiles[idx->y][idx->x].entity = 0;
	for (int x = rand() % 19, y = rand() % 19, trig = 0; trig != 1;
	x = rand() % 19, y = rand() % 19) {
		if (map->tiles[y][x].entity == 0 &&
		map->tiles[y][x].type != TREE) {
			trig = 1;
			map->tiles[y][x].entity = 1;
			map->tiles[y][x].ptr = monster;
		}
	}
}

void search_for_prey_or_move(sfVector2i *idx,
	map_cb_t *map, player_stat_t *player)
{
	sfVector2i row_start = {idx->x - 5, idx->y - 5};
	sfVector2i row_end = {idx->x + 5, idx->y + 5};
	char trig = 0;

	check_valid_coordinates(&row_start);
	check_valid_coordinates(&row_end);
	for (int i = row_start.y;
	i < 20 && i < row_end.y && trig != 1; i++)
		for (int j = row_start.x;
		j < 20 && j < row_end.x && trig != 1; j++)
			if (map->tiles[i][j].entity == 2 &&
			map->tiles[i][j].type != FOLLIAGE) {
				teleport_to_player(map,
				player, idx);
				trig = 1;
			}
	if (trig != 1)
		move_monster(idx, map);
}

void teleport_to_player(map_cb_t *map, player_stat_t *player,
	sfVector2i *pos)
{
	sfVector2i p_pos = {0, 0};
	sfVector2i pos_end = {0, 0};

	for (int i = 0, trig = 0; i < 19 && trig != 1; i++)
		for (int j = 0; j < 19 && trig != 1; j++) {
			p_pos.x = map->tiles[i][j].entity == 2 ? i : 0;
			p_pos.y = map->tiles[i][j].entity == 2 ? j : 0;
			trig = map->tiles[i][j].entity == 2 ? 1 : 0;
		}
	p_pos = (sfVector2i){p_pos.x - 1, p_pos.y - 1};
	check_valid_coordinates(&p_pos);
	pos_end = (sfVector2i){p_pos.x + 1, p_pos.y + 1};
	check_valid_coordinates(&pos_end);
	for (int i = p_pos.y, trig = 0;
	i < pos_end.y + 2 && trig != 1; i++)
		for (int j = p_pos.x;
		j < pos_end.x + 2 && trig != 1; j++)
			trig = attack_player(map, pos,
			&(sfVector2i){i, j}, player);
}
