/*
** EPITECH PROJECT, 2017
** main_calls.c
** File description:
** main file with all game calls
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

map_t *load_2d_arr_from_file(char *filepath, map_t *map)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen(filepath, "r");
	if (stream == NULL)
		exit(84);
	map->x_file = malloc(sizeof(char *) * map->y);
	map->x_file_save = malloc(sizeof(char *) * map->y);
	map->O_pos = malloc(sizeof(score) * map->boxes);
	if (!map->x_file || !map->x_file_save || !map->O_pos)
		exit(84);
	for (int i = 0; (read = getline(&line, &len, stream)) != -1; i++) {
		map->x_file[i] = line;
		line = NULL;
	}
	map = load_2d_arr_from_file_save(filepath, map);
	fclose(stream);
	return (map);
}

void verify_file_stat(char *av)
{
	char *concat = concat_params("./", av);
	int fd = open(concat, O_RDONLY);

	if (fd == -1)
		exit(84);
	verify_file_content(concat);
	close(fd);
}

void verify_file_content(char *filepath)
{
	char buff[1];
	int dir = open(filepath, O_RDONLY);
	int result = read(dir, buff, 1);

	while (result != 0) {
		if (buff[0] == 'X' || buff[0] == 'O' || buff[0] == ' ')
			result = read(dir, buff, 1);
		else if (buff[0] == '#' || buff[0] == '\n')
			result = read(dir, buff, 1);
		else if (buff[0] == 'P')
			result = read(dir, buff, 1);
		else
			exit(84);
	}
	free(filepath);
	close(dir);
}

map_t *find_widht_and_height(map_t *map, char *filepath)
{
	char buff[1];
	int dir = open(filepath, O_RDONLY);
	int result = read(dir, buff, 1);

	for (int x = 1; result != 0; x++) {
		if (map->x < x)
			map->x = x;
		if (buff[0] == 'P') {
			map->p_pos_y_base = map->y;
			map->p_pos_x_base = x;
		} else if (buff[0] == 'X')
			map->boxes++;
		else if (buff[0] == '\n') {
			x = 0;
			map->y++;
		}
		result = read(dir, buff, 1);
	}
	return (map);
}
