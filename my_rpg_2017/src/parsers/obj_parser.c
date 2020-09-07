/*
** EPITECH PROJECT, 2018
** obj_parser.c
** File description:
** parser for obj
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "proto.h"

obj_stat_t *get_obj_stats(char *buf)
{
	char *tmp = buf;
	obj_stat_t *stat = malloc(sizeof(obj_stat_t));

	if (stat == NULL) {
		my_put_err("Invalid memory allocation for stat struct\n");
		return (NULL);
	}
	stat->att = my_getnbr(tmp);
	for (;tmp[0] != '\0' && tmp[0] != '\n'; tmp++);
	tmp++;
	stat->def = my_getnbr(tmp);
	for (;tmp[0] != '\0' && tmp[0] != '\n'; tmp++);
	tmp++;
	stat->spd = my_getnbr(tmp);
	free(buf);
	return (stat);
}

void fill_obj(obj_t *obj, FILE *fd, size_t size)
{
	int gnl;
	char *buf = NULL;

	gnl = getline(&buf, &size, fd);
	if (gnl == -1)
		my_put_err("Error during obj name reading\n");
	obj->name = my_strdup(buf);
	gnl = getline(&buf, &size, fd);
	if (gnl == -1)
		my_put_err("Error during obj sprite path reading\n");
	obj->sprite = create_sprite(buf);
	gnl = getline(&buf, &size, fd);
	if (gnl == -1)
		my_put_err("Error during obj sprite path reading\n");
	obj->stats = get_obj_stats(buf);
}

obj_t *create_obj_list(FILE *fd)
{
	char *buf = NULL;
	obj_t *new = NULL;
	obj_t *obj = NULL;
	obj_t *first = NULL;
	size_t size = 30;

	while (getline(&buf, &size, fd) != -1) {
		new = malloc(sizeof(obj_t));
		if (my_strcmp(buf, "\n") != 0) {
			new->id = my_getnbr(buf);
			fill_obj(new, fd, size);
			new->next = NULL;
			if (first == NULL)
				first = new;
			if (obj != NULL)
				obj->next = new;
			obj = new;
		}
	}
	return (first);
}

obj_t *obj_parser(char *file)
{
	FILE *fd = fopen(file, "r");
	obj_t *result;

	if (fd == NULL) {
		my_put_err("Error during opening obj file\n");
		return (NULL);
	}
	result = create_obj_list(fd);
	fclose(fd);
	if (result != NULL)
		my_putstr("End of object parsing\n");
	return (result);
}
