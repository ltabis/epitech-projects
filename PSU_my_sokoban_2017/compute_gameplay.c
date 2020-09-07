/*
** EPITECH PROJECT, 2017
** compute_gameplay.c
** File description:
** file that compute gameplay
*/
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include "include/my.h"
#include "include/proto.h"

map_t *compute_gameplay(map_t *map, int input)
{
	map_t *(*PickAction[5])(map_t *) = {mv_p_left, mv_p_up,
				mv_p_right, mv_p_down, mv_space};

	input = detect_key(input);
	if (input == 5)
		return (map);
	else
		map = (*PickAction[input])(map);
	return (map);
}

int detect_key(int input)
{
	int keys[] = { 260, 259, 261, 258, 32 };
	int i = 0;

	for (; input != keys[i] && keys[i] != '\0'; i++);
	return (i);
}

int allocate_memory(int y, char *filepath)
{
	char buff[1];
	int dir = open(filepath, O_RDONLY);
	int result = read(dir, buff, 1);
	int i = 0;

	for (int j = 0; result != 0 && j < y; i++) {
		if (buff[0] == '\n')
			j++;
		result = read(dir, buff, 1);
	}
	for (i = 0; buff[0] != '\n'; i++, result = read(dir, buff, 1));
	close(dir);
	return (i);
}
