/*
** EPITECH PROJECT, 2018
** check_redirections.c
** File description:
** check refirections and other parameters for the minishell 2
*/

#include "../include/proto.h"
#include "../include/parser.h"
#include <unistd.h>
#include <stdlib.h>

void check_redirections(char *command, char **path,
	env_t *env_lst, app_info_t *infos)
{
	char op = 0;
	unsigned int count_elements = 1;
	lexer_t *lexer = NULL;
	cmd_lex_t *pass = NULL;

	for (unsigned int i = 0; command[i]; i++)
		op = check_command_line(command, op, i, &count_elements);
	if (op != 1)
		search_exec(command, path, env_lst, infos);
	else {
		lexer = malloc(sizeof(lexer_t) * (count_elements + 1));
		if (!lexer)
			exit(84);
		parse_all_parameters(command, command, lexer, count_elements);
		pass = create_binary_tree(lexer);
		if (!command)
			return;
		execute_commands_one_by_one(pass, path, env_lst, infos);
	}
}

char check_command_line(char *command, char op,
	unsigned int i, unsigned int *count_elements)
{
	const char operation[] = ";|><";
	unsigned int len = my_strlen(command);

	for (unsigned int j = 0; operation[j]; j++) {
		if (i + 1 <= len &&
		command[i] == operation[j] && command[i + 1] != operation[j]) {
			*count_elements += 2;
			return (1);
		} else if (i + 1 <= len &&
		((command[i] == '>' && command[i + 1] == '>') ||
		(command[i] == '<' && command[i + 1] == '<')))
			return (1);
	}
	return (op == 1 ? 1 : 0);
}

void parse_all_parameters(char *cmd, char *tmp,
	lexer_t *lexer, unsigned int count_elements)
{
	const char operation[] = ";|><";

	for (unsigned int i = 0, r = 0, save = 0; r < count_elements; i++) {
		if (cmd[i] == 0) {
			i = get_back_to_old_position(cmd, i);
			lexer[r].arg = my_strndup(tmp, i - save);
			lexer[r++].token = ARG;
		}
		for (unsigned int j = 0; operation[j]; j++)
			if (cmd[i] == operation[j]) {
				i = get_back_to_old_position(cmd, i);
				tmp = cpy_cmd(tmp, &lexer[r++], i - save);
				for (; cmd[i] == '\t' || cmd[i] == ' '; i++);
				save = i;
				i += cmd[i + 1] == operation[j] ? 2 : 1;
				tmp = cpy_cmd(tmp, &lexer[r++], i - save);
				save = i;
			}
	}
	lexer[count_elements].arg = NULL;
}

char *cpy_cmd(char *tmp_index, lexer_t *lexer, unsigned int diff)
{
	unsigned int i = 0;
	const char operation[] = ";|><";

	for (; (diff == 1 || diff == 2) &&
	operation[i] && tmp_index[0] != operation[i]; i++);
	lexer->arg = my_strndup(tmp_index, diff);
	if (diff == 1 && i < 4)
		lexer->token = i;
	else if (diff == 2 && i < 4)
		lexer->token = i + 2;
	else
		lexer->token = ARG;
	tmp_index += diff;
	for (; tmp_index[0] && (tmp_index[0] == '\t' || tmp_index[0] == ' ');
	tmp_index++);
	return (tmp_index);
}

int get_back_to_old_position(char *command, unsigned int i)
{
	for (; i != 0 &&
	(command[i - 1] == ' ' || command[i - 1] == '\t'); i--);
	return (i);
}