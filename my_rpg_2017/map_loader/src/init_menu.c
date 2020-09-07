/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** initialise structure
*/

#include <SFML/Audio.h>
#include <SFML/Graphics/Rect.h>
#include "proto.h"
#include "menu.h"
#include "my.h"
#include "../../include/proto.h"

void invert_key(map_all_t *map_all, sfRenderWindow *window)
{
	(void)window;
	map_all->pl_stats->invert == 0 ? (map_all->pl_stats->invert = 1) :
	(map_all->pl_stats->invert = 0);
}

game_s *text_init(game_s *g, sfView *view)
{
	sfFont *font = sfFont_createFromFile("pixelmix.ttf");
	sfVector2f screen_center = {0, 0};

	screen_center = sfView_getCenter(view);
	screen_center.x = screen_center.x + 460;
	screen_center.y = screen_center.y + 500;
	g->sound = sfText_create();
	g->framerate = sfText_create();
	sfText_setFont(g->framerate, font);
	sfText_setFont(g->sound, font);
	sfText_setString(g->framerate, "Framerate = 60");
	sfText_setString(g->sound, "Sound = 100");
	sfText_setPosition(g->framerate, screen_center);
	sfText_setPosition(g->sound, screen_center);
	g->volume = 100;
	return (g);
}

game_s *button_initialisation(game_s *g, sfView *view)
{
	g->button[2] = create_but(create_vect(100, 500), create_vect(300, 100)
		, create_sprite(VIDEO_BUTTON), create_rect(0, 0, 300, 61));
	g->button[3] = create_but(create_vect(950, 450), create_vect(200, 200)
		, create_sprite(BACK_BUTTON), create_rect(0, 0, 200, 200));
	g->button[4] = create_but(create_vect(525, 200), create_vect(150, 71)
		, create_sprite(VSYNC), create_rect(0, 0, 150, 71));
	g->button[5] = create_but(create_vect(525, 300), create_vect(200, 93)
		, create_sprite(INVERT_MOUSE), create_rect(0, 0, 200, 93));
	g->button[6] = create_but(create_vect(950, 200), create_vect(200, 56)
		, create_sprite(TXT_FOR), create_rect(0, 0, 200, 56));
	g->button[7] = create_but(create_vect(800, 280), create_vect(175, 175)
		, create_sprite(PLUS), create_rect(0, 0, 175, 175));
	g->button[8] = create_but(create_vect(225, 280), create_vect(175, 175)
		, create_sprite(MINUS), create_rect(0, 0, 175, 175));
	g = text_init(g, view);
	return (g);
}

game_s *game_initialisation(game_s *g, sfView *view)
{
	g->sprite[0] = sprite_init(g->sprite[0], create_vect(421, 151)
		, create_vect(1280, 684), SETTINGS);
	g->sprite[1] = sprite_init(g->sprite[1], create_vect(421, 151)
		, create_vect(1280, 684), AUDIO);
	g->sprite[2] = sprite_init(g->sprite[2], create_vect(421, 151)
		, create_vect(1280, 684), VIDEO);
	g->sprite[3] = sprite_init(g->sprite[3], create_vect(421, 151)
		, create_vect(1280, 684), CONTROL);
	g->sprite[4] = sprite_init(g->sprite[4], create_vect(421, 151)
		, create_vect(1280, 617), STATS);
	g->button[0] = create_but(create_vect(100, 100), create_vect(300, 100)
		, create_sprite(AUDIO_BUTTON), create_rect(0, 0, 300, 56));
	g->button[1] = create_but(create_vect(100, 300), create_vect(300, 100)
		, create_sprite(CONTROL_BUTTON), create_rect(0, 0, 300, 46));
	g = button_initialisation(g, view);
	return (g);
}

int init_struct(game_s *game)
{
	game->sprite = malloc(sizeof(sprite_s *) * SPRITE_NBR);
	if (game->sprite == NULL)
		return (ERROR);
	for (int i = 0; i < SPRITE_NBR; i++) {
		game->sprite[i] = malloc(sizeof(sprite_s));
		if (game->sprite[i] == NULL)
			return (ERROR);
	}
	game->button = malloc(sizeof(button_t *) * BUTTON_NBR);
	if (game->button == NULL)
		return (ERROR);
	for (int i = 0; i < BUTTON_NBR; i++) {
		game->button[i] = malloc(sizeof(button_t));
		if (game->button[i] == NULL)
			return (ERROR);
	}
	game->fps = 60;
	game->v_sync = 1;
	game->obj = obj_parser(PATH_ITEM);
	return  (0);
}
