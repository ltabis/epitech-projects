/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** parsing
*/

#include "proto.h"

grid_info_t *parsing_file(char * const *av)
{
	grid_info_t *info = NULL;
	FILE *stream = fopen(av[1], "r");

	if (!stream || !(info = malloc(sizeof(grid_info_t))))
		return (NULL);
	info->x = 0;
	info->y = 0;
	info->grid = NULL;
	info->new_grid = NULL;
	if (check_file_content(stream, info) == -1)
		return (NULL);
	if (!(stream = fopen(av[1], "r")) || (create_grid(stream, info)) == -1)
		return (NULL);
	return (info);
}

int check_file_content(FILE *stream, grid_info_t *info)
{
	size_t len = 0;
	char *line = NULL;

	for (int last_len = 0, new_len = 0, i = 0;
	getline(&line, &len, stream) != -1; i++) {
		new_len = my_strlen(line);
		if (new_len != last_len && i != 0) {
			fprintf(stderr, "Error : line %d and line %d aren't"\
			" the same lenght\n", i + 1, i);
			return (-1);
		}
		last_len = my_strlen(line);
		info->y++;
	}
	info->x = strlen(line);
	fclose(stream);
	free(line);
	return (0);
}

int create_grid(FILE *stream, grid_info_t *info)
{
	size_t len = 0;
	char *line = NULL;

	info->grid = malloc(sizeof(char *) * (info->y + 1));
	if (!info->grid)
		return (-1);
	for (int i = 0, j = 0;
	getline(&line, &len, stream) != -1; i++) {
		info->grid[i] = malloc(sizeof(char) * (info->x));
		if (!info->grid[i])
			return (-1);
		for (j = 0; line && line[j] && line[j] != '\n'; j++)
			info->grid[i][j] = line[j];
		info->grid[i][j] = 0;
	}
	info->grid[info->y] = NULL;
	fclose(stream);
	free(line);
	return (0);
}
