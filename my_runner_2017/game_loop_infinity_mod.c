/*
** EPITECH PROJECT, 2017
** game_loop_infinity_mod.c
** File description:
** game loop for the entire infinity mod
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "include/proto.h"

object_t *do_game_loop_infinite(object_t *board, sfRenderWindow *window)
{
	sfSprite *spr = sfSprite_create();
	sfTexture *txt = sfTexture_createFromFile("Sprites/Background/Skin_menu.png", NULL);

	while (sfRenderWindow_isOpen(window)) {
		sfSprite_setTexture(spr, txt, 0);
		sfRenderWindow_drawSprite(window, spr, NULL);
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			return (board);
		else if (sfKeyboard_isKeyPressed(sfKeyNum3) == sfTrue) {
			board[6] = create_player("Sprites/Background/Washy_spites.png");
			return (board);
		} else if (sfKeyboard_isKeyPressed(sfKeyNum1) == sfTrue) {
			board[6] = create_player("Sprites/Background/Washy_spites_3.png");
			return (board);
		} else if (sfKeyboard_isKeyPressed(sfKeyNum5) == sfTrue) {
			board[6] = create_player("Sprites/Background/Washy_spites_4.png");
			return (board);
		} else if (sfKeyboard_isKeyPressed(sfKeyNum2) == sfTrue) {
			board[6] = create_player("Sprites/Background/Washy_spites_5.png");
			return (board);
		} else if (sfKeyboard_isKeyPressed(sfKeyNum4) == sfTrue) {
			board[6] =  create_player("Sprites/Background/Washy_spites_6.png");
			return (board);
		}
	}
	sfSprite_destroy(spr);
	sfTexture_destroy(txt);
	return (board);
}

int analyse_events(sfEvent event, sfRenderWindow *window, sfClock *clock,
		int jump)
{
	sfSprite *butt1;
	sfTexture *text_butt1;
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 1000000.0;
	int error = 0;

	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
		display_pause(window, clock, time, seconds);
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && jump == 0) {
		error = play_jump_sound(clock);
		if (error == 84)
			return (84);
	}
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
		return (1);
	return (0);
}

object_t move_sprite(object_t obj)
{
	if (obj.type != 'E') {
		obj.rect.left += obj.speed;
		if (obj.rect.left == 1920)
			obj.rect.left = -1920;
	} else {
		obj.rect.left += 108;
		if (obj.rect.left == 432)
			obj.rect.left = 0;
		sfSprite_setTextureRect(obj.spr, obj.rect);
	}
	return (obj);
}

object_t move_player(object_t obj)
{
	obj.rect.left += 500;
	if (obj.rect.left == 2500)
		obj.rect.left = 0;
	return (obj);
}

object_t display_sprites(object_t board, sfRenderWindow *window,
			sfClock *clock)
{
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 1000000.0;

	if (board.rect.width == 500) {
		if (seconds > 0.2) {
			board = move_player(board);
			sfClock_restart(clock);
		}
	} else
		board = move_sprite(board);
	sfSprite_setTextureRect(board.spr, board.rect);
	sfRenderWindow_drawSprite(window, board.spr, NULL);
	return (board);
}
