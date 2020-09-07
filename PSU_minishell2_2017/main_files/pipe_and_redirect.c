/*
** EPITECH PROJECT, 2018
** pipe_and_redirect.c
** File description:
** executing pipe and redirection when asked
*/

#include "../include/proto.h"
#include "../include/parser.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void execute_commands_one_by_one(cmd_lex_t *pass, char **path,
	env_t *env_lst, app_info_t *infos)
{
	lexer_t cmd[2];

	for (unsigned int i = 0; pass->cmd_ptr[i].idx_start != -1; i++) {
		for (int j = pass->cmd_ptr[i].idx_start;
		j + 2 <= pass->cmd_ptr[i].idx_stop &&
		pass->cmd_ptr[i].idx_stop - pass->cmd_ptr[i].idx_start != 0;
		j += 2) {
			cmd[0] = pass->lex_ptr[j];
			cmd[1] = pass->lex_ptr[j + 2];
			if (pass->lex_ptr[j + 1].token == PIPE)
				create_pipe(cmd, path, env_lst, infos);
			else
				redirect_in_file(cmd, path, env_lst, infos);
		}
		pass->cmd_ptr_act = &pass->cmd_ptr[i];
		exec_command_alone(pass, path, env_lst, infos);
	}
}

void create_pipe(lexer_t *cmd, char **path, env_t *env_lst, app_info_t *infos)
{
	pid_t pid = fork();

	if (pid == -1) {
		my_puterr("failed to for\n");
		return;
	} else if (pid != 0) {
		wait(NULL);
	} else
		link_pipes(cmd, path, env_lst, infos);
}

void redirect_in_file(lexer_t *cmd, char **path,
	env_t *env_lst, app_info_t *infos)
{
	int pipefd[2];
	pid_t pid = 0;
	int fd = open(cmd[1].arg, O_CREAT | O_RDWR,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (fd == -1 || pipe(pipefd) == -1 || (pid = fork()) == -1) {
		my_puterr("Failed to create new process or pipe\n");
		return;
	} else if (pid == 0) {
		close(pipefd[0]);
		if (dup2(pipefd[1], 1) == -1)
			exit(84);
		close(pipefd[1]);
		search_exec(cmd[0].arg, path, env_lst, infos);
		exit(0);
	} else {
		write_in_file(fd, pipefd);
		close(fd);
	}
}

void exec_command_alone(cmd_lex_t *p, char **path,
	env_t *env_lst, app_info_t *infos)
{
	if (p->cmd_ptr_act->idx_stop - p->cmd_ptr_act->idx_start == 0) {
		if (my_strcmp_env(
		p->lex_ptr[p->cmd_ptr_act->idx_start].arg, "setenv") == 0 ||
		my_strcmp_env(
		p->lex_ptr[p->cmd_ptr_act->idx_start].arg, "unsetenv") == 0 ||
		my_strcmp_env(
		p->lex_ptr[p->cmd_ptr_act->idx_start].arg, "cd") == 0)
			add_or_remove_env_variable(&env_lst,
			p->lex_ptr[p->cmd_ptr_act->idx_start].arg, infos);
		else {
			search_exec(
			p->lex_ptr[p->cmd_ptr_act->idx_start].arg,
			path, env_lst, infos);
		}
	}
}

void link_pipes(lexer_t *cmd, char **path, env_t *env_lst, app_info_t *infos)
{
	pid_t pid = 0;
	static int pipefd[2];

	if (pipe(pipefd) == -1 || (pid = fork()) == -1) {
			return;
	} else if (pid != 0) {
		close(pipefd[1]);
		if (dup2(pipefd[0], 0) == -1)
			exit(84);
		close(pipefd[0]);
		search_pipe_exec(cmd[1].arg, path, env_lst, infos);
	} else {
		close(pipefd[0]);
		if (dup2(pipefd[1], 1) == -1)
			exit(84);
		close(pipefd[1]);
		search_pipe_exec(cmd[0].arg, path, env_lst, infos);
	}
}