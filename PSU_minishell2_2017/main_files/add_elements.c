/*
** EPITECH PROJECT, 2018
** add_elements.c
** File description:
** adding elements to the main chained list
*/

#include "../include/parser.h"
#include "../include/proto.h"
#include <unistd.h>
#include <stdlib.h>

command_t *add_and_arguments(lexer_t *lex)
{
	command_t *commands = NULL;
	unsigned int idx = 1;

	for (unsigned int i = 0; lex[i].arg; i++)
		idx += lex[i].token == AND ? 1 : 0;
	if ((commands = malloc(sizeof(command_t) * (idx + 1))) == NULL)
		exit(84);
	commands[0].idx_start = 0;
	for (unsigned int i = 0, j = 0; j < idx; i++) {
		if (j + 1 < idx && lex[i].arg && lex[i].token == AND) {
			commands[j++].idx_stop = i - 1;
			commands[j].idx_start = i + 1;
		} else if (!lex[i].arg)
			commands[j++].idx_stop = i - 1;
	}
	commands[idx].idx_start = -1;
	commands[idx].idx_stop = -1;
	return (commands);
}

int check_pipes_before_redirect(command_t *commands, lexer_t *lexer)
{
	char ret = 0;

	for (unsigned int i = 0; commands[i].idx_start != -1 && ret == 0; i++)
		ret = check_indexes(commands[i], lexer);
	return (ret == -1 ? -1 : 0);
}

int check_indexes(command_t commands, lexer_t *lexer)
{
	unsigned int catch_first_redirect = commands.idx_stop;
	unsigned int catch_last_pipe = 0;

	for (unsigned int i = commands.idx_start;
		(int)i <= commands.idx_stop; i++) {
		catch_first_redirect = lexer[i].token >= 2 &&
		lexer[i].token <= 5 &&
		i < catch_first_redirect ? i : catch_first_redirect;
		catch_last_pipe = lexer[i].token == 1 &&
		i > catch_last_pipe ? i : catch_last_pipe;
	}
	return (catch_last_pipe > catch_first_redirect ? -1 : 0);
}