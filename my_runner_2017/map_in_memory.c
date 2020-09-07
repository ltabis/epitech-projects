/*
** EPITECH PROJECT, 2017
** map_in_memory.c
** File description:
** file that put the map in memory
*/
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/proto.h"

map_t *load_map_from_file(char *filepath)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	map_t *map = malloc(sizeof(map_t));

	stream = fopen(filepath, "r");
	if (!map || !stream)
		return (NULL);
	map->prev = 0;
	map->next = 0;
	for (int i = 0; (read = getline(&line, &len, stream)) != -1; i++) {
	        for (int j = 0; line[j] != '\n'; j++)
			if (line[j] != ' ' && line[j] != '#')
				map = create_object_list(line[j],
							map, i, j);
	        line = NULL;
	}
	fclose(stream);
	return (map);
}

sfMusic *configure_music(sfMusic *music)
{
	music = sfMusic_createFromFile("Sounds/STrack.wav");
	sfMusic_setVolume(music, 20);
	sfMusic_setLoop(music, sfTrue);
	sfMusic_play(music);
	return (music);
}
