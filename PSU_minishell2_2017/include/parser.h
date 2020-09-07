/*
** EPITECH PROJECT, 2017
** parser.h
** File description:
** prototypes for a particular program
*/

#include <stdarg.h>
#ifndef PARSER_H_
#define PARSER_H_

#include "proto.h"

enum token_e {AND, PIPE, ARROW_R, ARROW_L, DBL_ARROW_R, DBL_ARROW_L, ARG};

typedef enum token_e t_token;

typedef struct command_s {
	int idx_start;
	int idx_stop;
} command_t;

typedef struct lexer_s {
	t_token token;
	char *arg;
} lexer_t;

typedef struct cmd_lex_s {
	command_t *cmd_ptr;
	command_t *cmd_ptr_act;
	lexer_t *lex_ptr;
} cmd_lex_t;

void write_in_file(int, int *);
void link_pipes(lexer_t *, char **, env_t *, app_info_t *);
void start_special_forking(char **, env_t *, app_info_t *);
void search_pipe_exec(char *, char **, env_t *, app_info_t *);
void exec_command_alone(cmd_lex_t *, char **, env_t *, app_info_t *);
void exec_command(lexer_t, env_t *, app_info_t *);
void redirect_in_file(lexer_t *, char **, env_t *, app_info_t *);
void execute_commands_one_by_one(cmd_lex_t *, char **,
	env_t *, app_info_t *);
void create_pipe(lexer_t *, char **, env_t *, app_info_t *);
void redirect_input(lexer_t *, lexer_t, env_t *, app_info_t *);
command_t *add_and_arguments(lexer_t *);
int check_pipes_before_redirect(command_t *, lexer_t *);
int check_indexes(command_t, lexer_t *);
int check_redirect(lexer_t);
int check_line(lexer_t);
cmd_lex_t *create_binary_tree(lexer_t *);
char *cpy_cmd(char *, lexer_t *, unsigned int);
void parse_all_parameters(char *, char *, lexer_t *, unsigned int);
char check_command_line(char *, char, unsigned int, unsigned int *);
void check_redirections(char *, char **, env_t *, app_info_t *);
int get_back_to_old_position(char *, unsigned int);
char advance_tmp_variable(char);
int check_input(lexer_t *);

#endif /* !PARSER_H_ */