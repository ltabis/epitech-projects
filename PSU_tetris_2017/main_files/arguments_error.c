/*
** EPITECH PROJECT, 2018
** arguments_error.c
** File description:
** args gestions
*/

#include "../include/tetris.h"

void check_valid_arguments(int ac, char **av)
{
	for (int i = 0; i < ac; i++) {
		if (i > 0 && av[i][0] != '-' && av[i - 1][0] != '-') {
			write(2, "Bad input : ", 12);
			write(2, av[i], my_strlen(av[i]));
			write(2, " isn't an option\n", 17);
			exit(84);
		} else if (i > 0 && av[i][0] != '-' && av[i - 1][0] == '-' &&
			(av[i - 1][1] == 'D' || av[i - 1][1] == 'w')) {
			write(2, "Bad input : ", 12);
			write(2, av[i - 1], my_strlen(av[i - 1]));
			write(2, " do not take any parameters\n", 28);
			exit(84);
		} else if (i > 0 && av[i][0] != '-' && av[i - 1][0] == '-' &&
			av[i - 1][1] == '-'  ) {
			write(2, "Bad input : ", 12);
			write(2, av[i], my_strlen(av[i]));
			write(2, " isn't an option\n", 17);
			exit(84);
		}
	}
}

void check_other_valid_arguments(int ac, char **av)
{
	for (int i = 0; i < ac; i++) {
		if (i > 0 && av[i][0] == '-' &&
			my_strlen(av[i]) < 2) {
			write(2, "Bad input : ", 12);
			write(2, av[i], my_strlen(av[i]));
			write(2, " option doesn'exist\n", 20);
			exit(84);
		} else if (i > 0 && my_strlen(av[i]) == 2 && av[i][0] == '-' &&
			av[i][1] == '-') {
			write(2, "Bad input : ", 12);
			write(2, av[i], my_strlen(av[i]));
			write(2, " option doesn'exist\n", 20);
			exit(84);
		}
	}
}

void set_up_arrows(control_t *controls)
{
	char keys[4];

	keys[0] = 27;
	keys[1] = 91;
	keys[2] = 68;
	keys[3] = 0;
	free(controls->key_left2);
	free(controls->key_right2);
	free(controls->key_turn2);
	free(controls->key_drop2);
	controls->key_left2 = my_strcpy(controls->key_left2, keys);
	keys[2] = 67;
	controls->key_right2 = my_strcpy(controls->key_right2, keys);
	keys[2] = 65;
	controls->key_turn2 = my_strcpy(controls->key_turn2, keys);
	keys[2] = 66;
	controls->key_drop2 = my_strcpy(controls->key_drop2, keys);
}

void check_map_size(control_t cntrl, tetrimino_t *tetr, int nb_file)
{
	for (int i = 0; i < nb_file; i++) {
		if (tetr[i].info.size.x > cntrl.map_size.x ||
		tetr[i].info.size.y > cntrl.map_size.y) {
			write(2, "One of the tetrimino is too big"\
			" to fit in the game window\n", 58);
			exit(84);
		}
	}
}