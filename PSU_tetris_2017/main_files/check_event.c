/*
** EPITECH PROJECT, 2018
** check event
** File description:
** check event
*/

#include "tetris.h"

control_t check_event(control_t controls)
{
	char buff[controls.len_max];
	struct termios tmpterm;
	struct termios term;
	int rd = 0;

	for (int i = 0; i < controls.len_max; i++)
		buff[i] = 0;
	tcgetattr(0, &tmpterm);
	tcgetattr(0, &term);
	tmpterm.c_cc[VTIME] = 1;
	tmpterm.c_cc[VMIN] = 0;
	tcsetattr(0, TCSANOW, &tmpterm);
	rd = read(0, buff, controls.len_max);
	if (rd == -1)
		exit(84);
	controls.pass = check_key_active(buff, controls);
	tcsetattr(0, TCSANOW, &term);
	controls.pass = (controls.key_quit2[0] == buff[0] ? 2 : controls.pass);
	return (controls);
}

int check_key_active(char *buff, control_t controls)
{
	if (my_strncmp(buff, controls.key_left2, 2) == 0)
		return (3);
	else if (my_strncmp(buff, controls.key_right2, 2) == 0)
		return (4);
	else if (my_strncmp(buff, controls.key_turn2, 2) == 0)
		return (5);
	else if (my_strncmp(buff, controls.key_drop2, 2) == 0)
		return (6);
	return (0);
}

void decal_tetrimino(sz_t *d, control_t *cntl,
	char **brd, tetrimino_t *tetr)
{
	int x_r = 0;
	int x_l = 0;

	for (int i = 0; tetr[cntl->curr_tetr].piece[i]; i++) {
		for (int j = 0; tetr[cntl->curr_tetr].piece[i][j]; j++) {
			if (tetr[cntl->curr_tetr].piece[i][j] == '*') {
				x_r = (x_r != -1 &&
				d->x + j < cntl->map_size.x - 3 &&
				brd[d->y + i + 1][d->x + j + 1] == -1 ? 0 : -1);
				x_l = (x_l != -1 && d->x >= 1 &&
				brd[d->y + i + 1][d->x + j - 1] == -1 ? 0 : -1);
			}
		}
	}
	d->x -= (cntl->pass == 3 && d->x >= 1 && x_l != -1 ? 1 : 0);
	d->x += (cntl->pass == 4 && x_r != -1 ? 1 : 0);
	if (cntl->pass == 5)
		tetr[cntl->curr_tetr].piece = my_rotate(tetr[cntl->curr_tetr]);
	if (cntl->pass != 2)
		cntl->pass = 0;
}