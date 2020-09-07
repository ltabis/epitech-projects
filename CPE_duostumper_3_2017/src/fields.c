/*
** EPITECH PROJECT, 2018
** fields.c
** File description:
** fields -f option
*/

#include "../include/proto.h"
#include <stdlib.h>

void compute_fields(options_t *options, char *input)
{
	char *to_display = NULL;

	for (unsigned int i = 0; input[i]; i++) {
		if (input[i] == '\n') {
			search_fieds_to_display(
			options, input, i, to_display);
			input = advance_buffer(input);
			i = 0;
		}
	}
}

char *advance_buffer(char *buff)
{
	for (; buff[0] && buff[0] != '\n'; buff++);
	if (buff[0] == '\n')
		buff++;
	return (buff);
}

void search_fieds_to_display(options_t *options, char *input,
	unsigned int i, char *to_display)
{

}
