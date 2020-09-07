/*
** EPITECH PROJECT, 2017
** score.c
** File description:
** score
*/
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "include/my.h"
#include "include/proto.h"

map_t *put_targ_coords(map_t *map)
{
	unsigned int decal = 0;
	struct score_s sc;

	for (int y = 0; y < map->y; y++) {
		for (int x = 0; map->x_file[y][x] != '\n'; x++) {
			if (map->x_file[y][x] == 'O') {
				sc.x = x;
				sc.y = y;
				map->O_pos[decal] = sc;
				decal++;
			}
		}
	}
	return (map);
}

map_t *load_2d_arr_from_file_save(char *filepath, map_t *map)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen(filepath, "r");
	if (!stream)
		exit(84);
	for (int i = 0; (read = getline(&line, &len, stream)) != -1; i++) {
		map->x_file_save[i] = line;
		line = NULL;
	}
	fclose(stream);
	return (map);
}

void verify_score(map_t *map)
{
	int score = 0;
	struct score_s sc;

	for (int i = 0; i < map->boxes; i++) {
		sc = map->O_pos[i];
		if (map->x_file[sc.y][sc.x] != 'P'
		&& map->x_file[sc.y][sc.x] != 'X')
			map->x_file[sc.y][sc.x] = 'O';
		else if (map->x_file[sc.y][sc.x] == 'X')
			score++;
	}
	if (score == map->score_goal) {
		endwin();
		exit(0);
	}
}

map_t *initialise_values(map_t *map)
{
	map->stop = 0;
	map->x = 0;
	map->y = 0;
	map->score_goal = 0;
	map->boxes_stuck = 0;
	map->boxes = 0;
	map->boxes_base = 0;
	map->p_pos_x = 0;
	map->p_pos_y = 0;
	map->p_pos_x_base = 0;
	map->p_pos_y_base = 0;
	map->pos_x_cir = 0;
	map->pos_y_cir = 0;
	return (map);
}
