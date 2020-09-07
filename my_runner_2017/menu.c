/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** menu loop and behavior
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "include/proto.h"

int launch_menu(object_t *board, map_t *map, int y,
		char *av, sfText *scr)
{
	sfRenderWindow *window = construct_window();
	object_t *menu_obj = create_menu_objects();
	sfEvent event;
	sfMusic *music = configure_music(music);

	if (!window || !music)
		return (84);
	for (int clic = 0, trig = 0; sfRenderWindow_isOpen(window);) {
		while (sfRenderWindow_pollEvent(window, &event) && clic == 0)
			clic = analyse_events_menu(event, window);
		if (clic == 1) {
			board = do_game_loop_infinite(board, window);
			clic = 0;
		}
		else if (clic == 2)
			trig = do_game_loop_finite(board, map, window, scr);
		for (; trig == 1; clic = 0, trig = 0, board[6].end = 0)
			map = load_map_from_file(av);
		menu_obj = render_menu(menu_obj, window);
	}
	destroy_objects(board, map);
	sfMusic_destroy(music);
	return (0);
}

int analyse_events_menu(sfEvent event, sfRenderWindow *window)
{
	sfVector2i MosPos;

	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event.type == sfEvtMouseButtonPressed) {
		MosPos = sfMouse_getPosition(window);
		if ((MosPos.x >= 100 && MosPos.x <= 600) &&
		(MosPos.y >= 100 && MosPos.y <= 400))
			return (2);
		if ((MosPos.x >= 1420 && MosPos.x <= 1920) &&
		(MosPos.y >= 100 && MosPos.y <= 400))
			return (1);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			sfRenderWindow_close(window);
	}
	return (0);
}
object_t *render_menu(object_t *obj, sfRenderWindow *window)
{
	for (int i = 0; i < 3; i++)
		obj[i] = display_sprites_menu(obj[i], window);
	sfRenderWindow_display(window);
	return (obj);
}

object_t *create_menu_objects(void)
{
	object_t *obj = malloc(sizeof(object_t) * 3);
	sfVector2f pos;

	for (int i = 0; i != 1; pos.x = 0, pos.y = 0, i = 1);
	obj[0] = create_object_menu(
		"Sprites/Background/Background_1.png", pos);
	for (int i = 0; i != 1; pos.x = 0, pos.y = 100, i = 1);
	obj[1] = create_object_menu(
		"Sprites/Background/ButtonMap.png", pos);
	for (int i = 0; i != 1; pos.x = 1420, pos.y = 100, i = 1);
	obj[2] = create_object_menu(
		"Sprites/Background/Button2.png", pos);
	return (obj);
}

object_t create_object_menu(char *path_to_spritesheet, sfVector2f pos)
{
	object_t obj;

	obj.vect = pos;
	obj.initialisation = 1;
	obj.speed = 4;
	obj.txt = sfTexture_createFromFile(path_to_spritesheet, NULL);
	if (obj.txt == NULL)
		return (obj);
	obj.spr = sfSprite_create();
	if (obj.spr == NULL)
		return (obj);
	sfSprite_setTexture(obj.spr, obj.txt, 0);
	sfSprite_setPosition(obj.spr, pos);
	obj.initialisation = 0;
	return (obj);
}
