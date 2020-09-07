/*
** EPITECH PROJECT, 2018
** display_tetriminos.c
** File description:
** display tetriminos when debug mod active
*/

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include "../include/tetris.h"
#include <term.h>

void display_debug_mode(control_t controls, tetrimino_t *tetriminos,
	unsigned int nb_files)
{
	struct termios term;
	char buff[1];

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
	if (controls.debug != 1)
		return;
	check_map_size(controls, tetriminos, nb_files);
	my_putstr("*** DEBUG MODE ***\nKey Left : ");
	display_key_special(controls.key_left2);
	display_controls_informations(controls);
	my_putstr("\nTetriminos : ");
	my_put_nbr(nb_files);
	write(1, "\n", 1);
	for (unsigned int i = 0; i < nb_files; i++)
		display_infos(tetriminos[i]);
	my_putstr("Press any key to start Tetris\n");
	read(0, buff, 1);
}

void display_controls_informations(control_t controls)
{
	my_putstr("\nKey Right : ");
	display_key_special(controls.key_right2);
	my_putstr("\nKey Turn : ");
	display_key_special(controls.key_turn2);
	my_putstr("\nKey Drop : ");
	display_key_special(controls.key_drop2);
	my_putstr("\nKey Quit : ");
	display_key_special(controls.key_quit2);
	my_putstr("\nKey Pause : ");
	display_key_special(controls.key_pause2);
	my_putstr("\nNext : ");
	(controls.act_next_tetr == 1 ? my_putstr("No") : my_putstr("Yes"));
	my_putstr("\nLevel : ");
	my_put_nbr(controls.level);
	my_putstr("\nSize : ");
	my_put_nbr(controls.map_size.y);
	write(1, "*", 1);
	my_put_nbr(controls.map_size.x);
}

void display_infos(tetrimino_t tetrimino)
{
	my_putstr("Tetriminos : Name ");
	for (unsigned int i = 0; tetrimino.name[i + 10]; i++)
		write(1, &tetrimino.name[i], 1);
	if (tetrimino.info.state == -1) {
		my_putstr(" : Error\n");
		return;
	}
	my_putstr(" : Size ");
	my_put_nbr(tetrimino.info.size.x);
	write(1, "*", 1);
	my_put_nbr(tetrimino.info.size.y);
	my_putstr(" : Color ");
	my_put_nbr(tetrimino.info.color);
	write(1, " :\n", 3);
	for (unsigned int i = 0; tetrimino.piece[i]; i++)
		my_putstr(tetrimino.piece[i]);
}

void set_up_terminal(control_t *controls, char **env)
{
	unsigned int i = 0;
	char *env_cpy = NULL;
	char *tmp_env_cpy = NULL;

	for (char trig = 0; env[i] && trig != 1; i++)
		trig = (my_strncmp(env[i], "TERM=", 4) == 0 ? 1 : 0);
	if (env[i] && my_strlen(env[i]) > 4)
		env_cpy = my_strcpy(env_cpy, env[--i]);
	else
		env_cpy = NULL;
	tmp_env_cpy = env_cpy;
	for (; env_cpy && env_cpy[0] && env_cpy[0] != '='; env_cpy++);
	check_term_errors_and_free(env_cpy);
	if (tmp_env_cpy)
		free(tmp_env_cpy);
	controls->key_turn2 = my_strcpy(controls->key_turn2, tigetstr("kcuu1"));
	controls->key_drop2 = my_strcpy(controls->key_drop2, tigetstr("kcud1"));
	controls->key_left2 = my_strcpy(controls->key_left2, tigetstr("kcub1"));
	controls->key_right2 =
	my_strcpy(controls->key_right2, tigetstr("kcuf1"));
}

void display_key_special(char *key)
{
	char tmp = 0;

	for (unsigned int i = 0; key[i]; i++) {
		if (key[i] == 32)
			write(1, "(space)", 7);
		else if (key[i] < 32) {
			tmp = key[i] + 64;
			tmp = (tmp == 91 ? 'E' : tmp);
			write(1, "^", 1);
			write(1, &tmp, 1);
		} else
			write(1, &key[i], 1);
	}
}
