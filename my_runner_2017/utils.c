/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** useful functions
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/proto.h"

void display_how_to_use(void)
{
	write(1, "USAGE :\n", 9);
	write(1, "           map_name.txt\n", 25);
	write(1, "           with -h : display usage\n", 36);
	write(1, "           You can create your own map ", 39);
	write(1, "folowing the map_format.legend rules\n\nCONTROLS :\n", 49);
	write(1, "           SPACE to jump\n\n", 26);
	write(1, "Good luck !\n\n", 13);
}

void destroy_objects(object_t *board, map_t *map)
{
	for (int i = 0; i < 7; i++) {
		sfSprite_destroy(board[i].spr);
		sfTexture_destroy(board[i].txt);
	}
	free(board);
	for (; map->prev != 0; map = map->prev)
		free(map->next);
	free(map);
}

int check_usage_and_params(char *av1, int ac, char **env)
{
	unsigned int i = 0;

	if (ac != 2) {
		write(2, "Bad arguments, retry with -h\n", 29);
		return (84);
	}
	if (av1[0] == '-' && av1[1] == 'h') {
		display_how_to_use();
		return (0);
	}
	if (!env[0])
		return (84);
	for (; env[i]; i++)
		if (my_strcmp(env[i], "DISPLAY=:0") == 0)
			return (1);
	if (!env[i])
		return (84);
	return (1);
}

int find_y(char *filepath)
{
	int y = 0;
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen(filepath, "r");
	if (stream == NULL)
		return (-1);
	for (int i = 0; read = getline(&line, &len, stream) != -1; i++) {
		y++;
		line = NULL;
	}
	fclose(stream);
	return (y);
}

object_t display_sprites_menu(object_t obj, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, obj.spr, NULL);
	return (obj);
}
