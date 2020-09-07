/*
** EPITECH PROJECT, 2018
** start tetris
** File description:
** start tetris
*/

#include "tetris.h"
#include <time.h>

window_t *init_windows(tetrimino_t *tetriminos, int nb_files)
{
	window_t *w = malloc(sizeof(window_t));

	initscr();
	if (!w)
		return (NULL);
	w->game = NULL;
	w->highscore = NULL;
	w->next = NULL;
	start_color();
	init_color(COLOR_BLACK, 0, 0, 0);
	for (int i = 0, color = 0; i < nb_files; i++) {
		color = tetriminos[i].info.color;
		init_pair(color, color, color);
	}
	init_pair(1, 1, 1);
	init_pair(3, 3, 3);
	return (w);
}

control_t set_windows(window_t *w, control_t controls,
	tetrimino_t *tetriminos, int nb_files)
{
	int max_sz_y = 3;
	int max_sz_x = 3;

	for (unsigned int i = 0; i < (unsigned int)nb_files; i++) {
		max_sz_y = (tetriminos[i].info.size.y > max_sz_y ?
		tetriminos[i].info.size.y : max_sz_y);
		max_sz_x = (tetriminos[i].info.size.x > max_sz_x ?
		tetriminos[i].info.size.x : max_sz_x);
	}
	w->highscore = newwin(15, 30, 0, 0);
	w->game = newwin(controls.map_size.y, controls.map_size.x, 0, 30);
	w->next =
	newwin(max_sz_y + 2, max_sz_x + 2, 0, 30 + controls.map_size.x);
	controls.nbr_files = nb_files;
	return (controls);
}

void set_parameters(window_t *w, control_t *controls,
	tetrimino_t *tetriminos, int nb_files)
{
	unsigned int nxt = 0;

	srand(time(NULL));
	refresh();
	noecho();
	curs_set(0);
	*controls = set_windows(w, *controls, tetriminos, nb_files);
	for (char trig = 0; controls->nbr_files - 1 > 0 && trig != 1;) {
		nxt = rand() % (controls->nbr_files - 1);
		trig = (tetriminos[nxt].info.state == -1 ? 0 : 1);
	}
	controls->curr_tetr = nxt;
	for (char trig = 0; controls->nbr_files - 1 > 0 && trig != 1;) {
		nxt = rand() % (controls->nbr_files - 1);
		trig = (tetriminos[nxt].info.state == -1 ? 0 : 1);
	}
	controls->next_tetr = nxt;
	set_up_arrows(controls);
}

int start_tetris(control_t cntrl, tetrimino_t *tetriminos, int nb_files,
		struct termios old)
{
	char **game_board = create_game_board(cntrl);
	window_t *w = NULL;
	int score = 0;
	int y_game = 0;
	int x_game = 0;

	if ((w = init_windows(tetriminos, nb_files)) == NULL)
		return (-1);
	set_parameters(w, &cntrl, tetriminos, nb_files);
	get_window_sizes(w, &x_game, &y_game);
	cntrl = choose_next_tetriminos(tetriminos, w, cntrl);
	while (cntrl.pass != 2) {
		cntrl = compute_gameplay(cntrl, tetriminos, w, game_board);
		display_best_players(w, score);
		handle_windows(w, y_game, x_game, cntrl);
		check_lines(game_board, cntrl, &score);
	}
	handle_highscore(score, w, old);
	delete_ressources(w, game_board, cntrl);
	return (0);
}
