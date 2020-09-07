/*
** EPITECH PROJECT, 2017
** game_loop_finite_mod.c
** File description:
** game loop for the normal mod
*/
#include <SFML/Graphics.h>
#include <unistd.h>
#include "include/proto.h"

int do_game_loop_finite(object_t *board, map_t *map,
			sfRenderWindow *window, sfText *scr)
{
	sfEvent event;
	int jumping = 0;
	sfVector2f pl_pos;
	sfClock *clock = sfClock_create();

	board = init_speed(board);
	for (int jump = 0, error = 0, x = 0; sfRenderWindow_isOpen(window);) {
		while (sfRenderWindow_pollEvent(window, &event))
			jump = analyse_events(event, window, clock, jumping);
		jumping = (jump == 1) ? 1 : jumping;
		board = compute_gameplay(board, jumping, window, clock);
		map = display_map_objects(map, window, clock);
		pl_pos = sfSprite_getPosition(board[6].spr);
		scr = update_text(scr, x++, window);
		board = check_collision(board, map, window, &jumping, scr);
		jumping = (pl_pos.y >= board[6].lim) ? 0 : jumping;
		if (board[6].end == 1)
			return (1);
	}
	return (0);
}

object_t *compute_gameplay(object_t *board, int jumping,
			sfRenderWindow *window, sfClock *clock)
{
	sfVector2f p_pos = sfSprite_getPosition(board[6].spr);
	sfVector2f vect;

	vect.x = 0;
	if (jumping == 1) {
		vect.y = board[6].jump;
		sfSprite_move(board[6].spr, vect);
		board[6].jump += 0.5;
	}
	if (jumping == 0 && p_pos.y < board[6].lim) {
		vect.y = board[6].jump;
		sfSprite_move(board[6].spr, vect);
		board[6].jump += 0.5;
	}
	for (int i = 0; i < 7; i++)
		board[i] = display_sprites(board[i], window, clock);
	board = compute_jump(&jumping, board);
	return (board);
}

object_t *compute_jump(int *jump, object_t *board)
{
	sfVector2f p_pos = sfSprite_getPosition(board[6].spr);
	sfVector2f pos;

	if (p_pos.y >= board[6].lim) {
		pos.x = 0;
		pos.y = board[6].lim;
		*jump = 0;
		board[6].jump = -13;
		sfSprite_setPosition(board[6].spr, pos);
	}
	return (board);
}

object_t *init_speed(object_t *board)
{
	board[1].speed = 1;
	board[2].speed = 1;
	board[5].speed = 12;
	board[6].lim = 550;
	board[6].jump = -13;
	return (board);
}

object_t *check_collision(object_t *board, map_t *map,
			sfRenderWindow *window, int *jumping, sfText *scr)
{
	sfVector2f pl_pos;
	sfVector2f obj_pos;
	int trig = 0;

	for (int x = 300; map->prev != 0; map = map->prev) {
		pl_pos = sfSprite_getPosition(board[6].spr);
		obj_pos = sfSprite_getPosition(map->obj.spr);
		if (pl_pos.y <= obj_pos.y - 348 && map->obj.type != 'E' &&
		(( obj_pos.x <= 250 && obj_pos.x + 108 >= 250) ||
		(obj_pos.x <= 500 && obj_pos.x + 108 >= 500))) {
			board[6].lim = obj_pos.y - 348;
			for (; trig != 1; *jumping = 0, trig = 1);
		}
		board[6] =
		check_block_type(map->obj, board[6], window, trig, scr);
	}
	if (trig == 0)
		board[6].lim = 550;
	for (; map->next != 0; map = map->next);
	return (board);
}
