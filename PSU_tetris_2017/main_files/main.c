/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for the tetris project
*/

#include "tetris.h"

int main(int ac, char **av, char **env)
{
	int nb_files = count_file();
	char **names = sort_names(nb_files);
	control_t controls;
	struct termios oldterm;
	tetrimino_t *tetriminos = malloc(sizeof(tetrimino_t) * nb_files);

	if (!tetriminos || !env[0])
		return (84);
	tcgetattr(0, &oldterm);
	controls = handle_arguments(ac, av, env);
	for (unsigned int i = 0; names[i]; i++)
		tetriminos[i].info =
		check_tetriminos(my_strcat("tetriminos/", names[i]));
	create_tetriminos(tetriminos, names);
	display_debug_mode(controls, tetriminos, nb_files);
	if (start_tetris(controls, tetriminos, nb_files, oldterm) == -1)
		return (84);
	free_structs(tetriminos, &controls, nb_files, oldterm);
	return (0);
}
