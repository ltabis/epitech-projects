/*
** EPITECH PROJECT, 2018
** move_r_l.c
** File description:
** another move functions
*/

#include <stdlib.h>
#include <fcntl.h>
#include "proto.h"
#include "my.h"

void right_nd(map_all_t *mp)
{
	mp->player->tempo_x = mp->player->tempo_x + 3;
	anim_player(mp, 70);
	mp->player->position.x = mp->player->position.x + 3;

}

int png_right(map_all_t *mp)
{
	if (mp->move->position.x < mp->player->position.x + 50 &&
	mp->move->position.x > mp->player->position.x) {
		if (mp->player->position.y + 50 > mp->move->position.y &&
		mp->player->position.y < mp->move->position.y + 50)
			return (1);
	}
	return (0);
}

sfView *right(sfView *view, map_all_t *mp, sfRenderWindow* window)
{
	sfVector2f a = sfView_getCenter(view);
	int x = mp->player->case_x + 1;
	int y = mp->player->case_y + 1;

	if (png_right(mp) == 1)
		return (view);
	if (mp->map[y][x + 1]->option > 2 && mp->player->tempo_x > 80)
		fct_tab(mp, mp->map[y][x + 1]->option,
			window, (sfVector2i){x + 1, y});
	set_x_y(&x, &y, mp);
	if (mp->map[y][x + 1]->option == 2 && mp->player->tempo_x > 55)
		return (view);
	if (mp->player->tempo_x > 100 &&
	(mp->map[y][x + 1]->option == 1 || mp->map[y][x + 1]->option == 0)) {
		mp->player->tempo_x = mp->player->tempo_x - 100;
		mp->player->case_x++;
	} a = (sfVector2f){3, 0};
	sfView_move(view, a);
	right_nd(mp);
	return (view);
}

void left_nd(map_all_t *mp)
{
	mp->player->tempo_x = mp->player->tempo_x - 3;
	mp->player->position.x = mp->player->position.x -3;
	anim_player(mp, 36);
}

sfView *left(sfView *view, UNUSED int i, map_all_t *mp, sfRenderWindow* window)
{
	sfVector2f a  = sfView_getCenter(view);
	int x = mp->player->case_x + 1;
	int y = mp->player->case_y + 1;

	if (png_left(mp) == 1)
		return (view);
	if (mp->map[y][x - 1]->option > 2 && mp->player->tempo_x < 30)
		fct_tab(mp, mp->map[y][x - 1]->option,
		window, (sfVector2i){x + 1, y});
	set_x_y(&x, &y, mp);
	if (mp->map[y][x - 1]->option == 2 && mp->player->tempo_x < 55)
		return (view);
	if (mp->player->tempo_x < 0 &&
	(mp->map[y][x - 1]->option == 1 || mp->map[y][x - 1]->option == 0)) {
		mp->player->tempo_x = 100 + mp->player->tempo_x;
		mp->player->case_x--;
	} a = (sfVector2f){-3, 0};
	left_nd(mp);
	sfView_move(view, a);
	return (view);
}
