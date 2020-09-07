/*
** EPITECH PROJECT, 2018
** parsing_chained_lists.c
** File description:
** creating binary tree
*/

#include "../include/proto.h"
#include "../include/parser.h"
#include <unistd.h>
#include <stdlib.h>

cmd_lex_t *create_binary_tree(lexer_t *lexer)
{
	command_t *commands = NULL;
	cmd_lex_t *pass = malloc(sizeof(cmd_lex_t));

	if (check_input(lexer) == -1 || !pass)
		return (NULL);
	commands = add_and_arguments(lexer);
	if (check_pipes_before_redirect(commands, lexer) == -1) {
		my_puterr("Ambiguous output redirect.\n");
		return (NULL);
	}
	pass->cmd_ptr = commands;
	pass->cmd_ptr_act = NULL;
	pass->lex_ptr = lexer;
	return (pass);
}

int check_input(lexer_t *lexer)
{
	for (unsigned int i = 0; lexer[i].arg; i++) {
		if (check_line(lexer[i]) == -1 ||
		check_redirect(lexer[i]) == -1)
			return (-1);
		if (i != 0 && ((lexer[i].token != ARG &&
		lexer[i - 1].token != ARG) ||
		(lexer[i].token != ARG &&
		lexer[i + 1].token != ARG))) {
			my_puterr("Invalid null command.\n");
			return (-1);
		}
	}
	return (0);
}

int check_line(lexer_t lexer)
{
	if (lexer.token < 6 && my_strlen(lexer.arg) > 3) {
		my_puterr("Invalid null command.");
		return (-1);
	} else if (lexer.token == 6 && my_strlen(lexer.arg) == 1) {
		my_puterr("Invalid null command.\n");
		return (-1);
	}
	for (unsigned int i = 0; lexer.arg[i]; i++) {
		if (lexer.token == 6 && (lexer.arg[i] == '>' ||
		lexer.arg[i] == '<' || lexer.arg[i] == ';' ||
		lexer.arg[i] == '|')) {
			my_puterr("Invalid null command.\n");
			return (-1);
		}
	}
	return (0);
}

int check_redirect(lexer_t lexer)
{
	if (lexer.token < 6) {
		if (my_strlen(lexer.arg) > 1 &&
		(!(lexer.arg[0] == '>' && lexer.arg[1] == '>') &&
		!(lexer.arg[0] == '<' && lexer.arg[1] == '<'))) {
			my_puterr("Invalid null command.\n");
			return (-1);
		}
	}
	if (lexer.arg[0] == 0) {
		my_puterr("Missing a command between two options\n");
		return (-1);
	}
	return (0);
}