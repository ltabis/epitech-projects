/*
** EPITECH PROJECT, 2017
** normal_mod.c
** File description:
** normal mod by loading maps from files
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/proto.h"

int launch_normal_mod(map_t *map, int y, char *av)
{
	sfVector2f pos;
	sfIntRect rect;
	object_t *board;
	int error = 0;

	for (int i = 0; i != 1; pos.x = 0, pos.y = 0, rect.left = 0, i = 1);
	rect.width = 1920;
	rect.height = 1080;
	rect.top = 0;
	board = create_objects_static(pos, rect);
	for (int i = 0; i < 7; i++)
		if (board[i].initialisation == 1)
			return (84);
	board[2].rect.left = -1920;
	board[4].rect.left = -1920;
	error = launch_menu(board, map, y, av, create_text());
	if (error == 84)
		return (84);
	return (0);
}

int play_jump_sound(sfClock *clock)
{
	sfSoundBuffer *sndbff;
	sfSound *snd = sfSound_create();
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 1000000.0;

	sndbff = sfSoundBuffer_createFromFile("Sounds/JumpSnd.wav");
	if (!snd || !sndbff) {
		sfSound_destroy(snd);
		sfSoundBuffer_destroy(sndbff);
		return (84);
	}
	sfSound_setBuffer(snd, sndbff);
	sfSound_setVolume(snd, 5);
	sfSound_play(snd);
	if (seconds > 0.75) {
		sfSound_destroy(snd);
		sfSoundBuffer_destroy(sndbff);
	}
	return (0);
}

object_t check_block_type(object_t obj, object_t player,
			sfRenderWindow *window, int trig, sfText *scr)
{
	sfVector2f pl_pos = sfSprite_getPosition(player.spr);
	sfVector2f obj_pos = sfSprite_getPosition(obj.spr);

	if (pl_pos.x + 300 >= obj_pos.x && obj.type == '|') {
		trig = display_won_game(window, scr);
		player.end = 1;
	} else if ((obj.type == '^' || obj.type == 'E') &&
	(pl_pos.y <= obj_pos.y - 348 && pl_pos.y >= obj_pos.y) &&
	(pl_pos.x + 250 >= obj_pos.x &&
	pl_pos.x + 250 <= obj_pos.x + 108)) {
		trig = display_lost_game(window, scr);
		player.end = 1;
	} else if ((pl_pos.x + 350 >= obj_pos.x &&
	pl_pos.x + 350 <= obj_pos.x + 10) &&
	(pl_pos.y > obj_pos.y - 348 && pl_pos.y < obj_pos.y) &&
	obj.type != '|') {
		trig = display_lost_game(window, scr);
		player.end = 1;
	}
	return (player);
}

object_t create_rect(object_t obj)
{
	sfIntRect rect;

	rect.top = 0;
	rect.left = 0;
	rect.width = 108;
	rect.height = 108;
	obj.rect = rect;
	sfSprite_setTextureRect(obj.spr, obj.rect);
	obj.speed = 2;
	return (obj);
}

