/*
** EPITECH PROJECT, 2018
** text_parser.c
** File description:
** functions for parse text
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "proto.h"

line_t *get_dialog(FILE *fd)
{
	line_t *new = NULL;
	line_t *line = NULL;
	line_t *first = NULL;
	char *buf = NULL;
	size_t size = 20;

	while (getline(&buf, &size, fd) != -1 && my_strcmp(buf, "\n") != 0) {
		new = malloc(sizeof(line_t));
		if (new == NULL)
			return (NULL);
		new->line = my_strdup(buf);
		new->next = NULL;
		if (first == NULL)
			first = new;
		if (line != NULL)
			line->next = new;
		line = new;
	}
	free(buf);
	return (first);
}

text_t *create_text_list(FILE *fd)
{
	char *buf = NULL;
	text_t *new = NULL;
	text_t *text = NULL;
	text_t *first = NULL;
	size_t size = 30;

	while (getline(&buf, &size, fd) != -1) {
		new = malloc(sizeof(text_t));
		if (new == NULL)
			return (NULL);
		new->id = my_getnbr(buf);
		new->dialog = get_dialog(fd);
		new->next = NULL;
		if (first == NULL)
			first = new;
		if (text != NULL)
			text->next = new;
		text = new;
	}
	return (first);
}

text_t *text_parser(char *file)
{
	FILE *fd = fopen(file, "r");
	text_t *result = NULL;

	if (fd == NULL) {
		my_put_err("Error during opening file\n");
		return (NULL);
	}
	result = create_text_list(fd);
	fclose(fd);
	if (result == NULL)
		my_putstr("Error(s) during text parsing\n");
	else
		my_putstr("End of text parsing\n");
	return (result);
}
