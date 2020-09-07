/*
** EPITECH PROJECT, 2018
** move_up_down.c
** File description:
** functions to move the player around the map
*/

#include <stdlib.h>
#include <fcntl.h>
#include "proto.h"
#include "my.h"

void set_x_y(int *x, int *y, map_all_t *all_map)
{
	*x = all_map->player->case_x + 1;
	*y = all_map->player->case_y + 1;
}

sfView *up(sfView *view, UNUSED int i, map_all_t *mp, sfRenderWindow *w)
{
	sfVector2f a  = sfView_getCenter(view);
	int x = mp->player->case_x + 1;
	int y = mp->player->case_y + 1;

	if (png_up(mp) == 1)
		return (view);
	if (mp->map[y - 1][x]->option > 2 && mp->player->tempo_y < 0)
		fct_tab(mp, mp->map[y - 1][x]->option,
		w, (sfVector2i){x, y - 1});
	set_x_y(&x, &y, mp);
	if (mp->map[y - 1][x]->option == 2 && mp->player->tempo_y < 50)
		return (view);
	if (mp->player->tempo_y < 0 &&
	(mp->map[y - 1][x]->option == 1 || mp->map[y - 1][x]->option == 0)) {
		mp->player->tempo_y = 100 + mp->player->tempo_y;
		mp->player->case_y--;
	} a = (sfVector2f){0, -3};
	up_nd(mp);
	sfView_move(view, a);
	return (view);
}

sfView *down(sfView *view, UNUSED int i, map_all_t *mp, sfRenderWindow *w)
{
	sfVector2f a  = sfView_getCenter(view);
	int x = mp->player->case_x + 1;
	int y = mp->player->case_y + 1;

	if (png_down(mp) == 1)
		return (view);
	if (mp->map[y + 1][x]->option > 2 && mp->player->tempo_y > 100)
		fct_tab(mp, mp->map[y + 1][x]->option,
		w, (sfVector2i){x, y + 1});
	set_x_y(&x, &y, mp);
	if (mp->map[y + 1][x]->option == 2 && mp->player->tempo_y > 50)
		return (view);
	if (mp->player->tempo_y > 100 &&
	(mp->map[y + 1][x]->option == 1 || mp->map[y + 1][x]->option == 0)) {
		mp->player->tempo_y = mp->player->tempo_y - 100;
		mp->player->case_y++;
	} a = (sfVector2f){0, 3};
	down_nd(mp);
	sfView_move(view, a);
	return (view);
}

void turn(map_all_t *all_map, sfRenderWindow *w, sfClock *clock)
{
	float seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock));

	while (sfKeyboard_isKeyPressed(sfKeyRight) && seconds > 0.001) {
		all_map->view_map = right(all_map->view_map, all_map, w);
		seconds = reset_time(clock, seconds, all_map, w);
	}
	while (sfKeyboard_isKeyPressed(sfKeyLeft) && seconds > 0.001) {
		all_map->view_map = left(all_map->view_map, 0, all_map, w);
		seconds = reset_time(clock, seconds, all_map, w);
	}
	while (sfKeyboard_isKeyPressed(sfKeyUp) && seconds > 0.001) {
		all_map->view_map = up(all_map->view_map, 0, all_map, w);
		seconds = reset_time(clock, seconds, all_map, w);
	}
	while (sfKeyboard_isKeyPressed(sfKeyDown) && seconds > 0.001) {
		all_map->view_map = down(all_map->view_map, 0, all_map, w);
		seconds = reset_time(clock, seconds, all_map, w);
	}
}

float reset_time(sfClock *clock, float seconds,
	map_all_t *all_map, sfRenderWindow *w)
{
	seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock));
	sfClock_restart(clock);
	disp_map(all_map, w, 0);
	return (seconds);
}
