/*
** EPITECH PROJECT, 2018
** npc_parser.c
** File description:
** parser for npc
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "proto.h"

void fill_npc(npc_t *npc, FILE *fd, size_t size)
{
	int gtln_value;
	char *buf = NULL;

	gtln_value = getline(&buf, &size, fd);
	if (gtln_value == -1)
		my_put_err("Error during read npc id");
	npc->id = my_getnbr(buf);
	gtln_value = getline(&buf, &size, fd);
	if (gtln_value == -1)
		my_put_err("Error during read npc text id");
	npc->txt_id = my_getnbr(buf);
}

void set_npc_type(npc_t *npc, char *buf)
{
	npc->type = 4;
	if (my_strcmp(buf, "NONE\n") == 0)
		npc->type = NONE;
	else if (my_strcmp(buf, "MERCHAND\n") == 0)
		npc->type = MERCHAND;
	else if (my_strcmp(buf, "QUESTER\n") == 0)
		npc->type = QUESTER;
	if (npc->type == 4)
		my_put_err("Error: Unknow npc type\n");
}

npc_t *create_npc_list(FILE *fd)
{
	char *buf = NULL;
	npc_t *new = NULL;
	npc_t *first = NULL;
	npc_t *npc = NULL;
	size_t size = 30;

	while (getline(&buf, &size, fd) != -1) {
		new = malloc(sizeof(npc_t));
		if (my_strcmp(buf, "\n") != 0 && new != NULL) {
			set_npc_type(new, buf);
			fill_npc(new, fd, size);
			new->next = NULL;
			if (first == NULL)
				first = new;
			if (npc != NULL)
				npc->next = new;
			npc = new;
		}
	}
	return (first);
}

npc_t *npc_parser(char *file)
{
	FILE *fd = fopen(file, "r");
	npc_t *result;

	if (fd == NULL)
		return (NULL);
	result = create_npc_list(fd);
	fclose(fd);
	if (result != NULL)
		my_putstr("End of npc parsing\n");
	else
		my_putstr("Error(s) during npc parsing\n");
	return (result);
}
