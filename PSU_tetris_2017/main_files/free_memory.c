/*
** EPITECH PROJECT, 2018
** free_memory.c
** File description:
** free the memory
*/

#include "tetris.h"
#include <stdlib.h>

void free_structs(tetrimino_t *tetriminos, control_t *controls,
	unsigned int nb_files, struct termios term)
{
	tcsetattr(0, TCSANOW, &term);
	for (unsigned int i = 0; i < nb_files; i++) {
		for (unsigned int j = 0; tetriminos[i].info.state != -1 &&
		tetriminos[i].piece[j]; j++)
			free(tetriminos[i].piece[j]);
		free(tetriminos[i].piece);
		free(tetriminos[i].name);
	}
	free(controls->key_quit2);
	free(controls->key_pause2);
	free(tetriminos);
}

void check_term_errors_and_free(char *term_name)
{
	int error = 0;

	if (!term_name) {
		write(2, "Environnement couldn't be loaded\n", 33);
		exit(84);
	} else
		term_name++;
	error = tgetent(NULL, term_name);
	if (error <= 0) {
		write(2, "Environnement couldn't be loaded\n", 33);
		exit(84);
	}
}

void delete_ressources(window_t *w,
	char **game_board, control_t controls)
{
	for (int i = 0; i < controls.map_size.y; i++)
		free(game_board[i]);
	free(game_board);
	delwin(w->game);
	delwin(w->next);
	delwin(w->highscore);
	free(w);
	endwin();
}

char *alloc_tetriminos_line(char *s2, int rd)
{
	unsigned int i = 0;
	unsigned int len = my_strlen(s2);
	char jump_line = 0;
	char *s1 = NULL;

	jump_line = (s2[rd - 1] != '\n') ? 2 : 1;
	s1 = malloc(sizeof(char) * (len + jump_line));
	if (!s1)
		exit(84);
	for (; i < len; i++)
		s1[i] = s2[i];
	s1[i] = 0;
	if (jump_line == 2) {
		s1[i] = '\n';
		s1[i + 1] = 0;
	}
	return (s1);
}
