/*
** EPITECH PROJECT, 2018
** combat_system.c
** File description:
** combat system main loop
*/

#include "../include/combat.h"
#include "../include/particles.h"
#include "../include/monster.h"

void call_combat_system(sfRenderWindow *w,
	tilemap_t tilemaps, player_stat_t *player)
{
	monster_t *monsters = parse_monsters();
	map_cb_t map = init_elements(monsters, player, &tilemaps);
	background_t *back = init_background(w);
	sfClock *clock = sfClock_create();
	sfVector2i lims = {MAP_SIZE, MAP_SIZE};

	if (map.initialisation == -1 || !back || !clock || !monsters)
		return;
	for (char stop = 0; sfRenderWindow_isOpen(w) && stop == 0;) {
		for (sfEvent event; sfRenderWindow_pollEvent(w, &event);)
			stop = compute_controls(event, &map, w);
		compute_background(w, back, clock, player);
		compute_turns(player, &map, w);
		draw_2d_map(w, map, lims, map.state);
		draw_hud_status(player, w, &map);
		stop = stop == 0 ? end_combat(player, &map, back, w) : stop;
		if (stop == 2)
			player->stats->current_hp = -1;
	}
}

map_cb_t init_elements(monster_t *monsters, player_stat_t *player,
	tilemap_t *tilemaps)
{
	sfFont *font = sfFont_createFromFile("pixelmix.ttf");
	map_cb_t map = {player->perso, create_hud(player), create_2d_map(),
	create_random_tiles(monsters), {0, 0},
	sfTexture_createFromFile("sprites/plain/3d_elem.png", NULL),
	sfSprite_create(), MAP_ZOOM, PLAYER_TURN, sfText_create(), -1,
	set_state(tilemaps->plain_tilemap)};

	if (!map.ter_txt || !map.ter_spr || !font ||
	!map.map_2d || !map.tiles || !map.play)
		return (map);
	sfSprite_setScale(map.perso, (sfVector2f){2.0f, 2.0f});
	sfSprite_setOrigin(map.perso, (sfVector2f){35, 35});
	sfText_setFont(map.play, font);
	sfText_setString(map.play, "Your turn");
	sfSprite_setTexture(map.ter_spr, map.ter_txt, sfTrue);
	sfSprite_setOrigin(map.ter_spr, (sfVector2f){50, 100});
	map.initialisation = 0;
	return (map);
}

hud_t *create_hud(player_stat_t *player)
{
	hud_t *hud = malloc(sizeof(hud_t));

	if (!hud)
		return (NULL);
	hud->hud_txt = sfTexture_createFromFile("sprites/hud.png", NULL);
	hud->clock_txt = sfTexture_createFromFile("sprites/clock.png", NULL);
	hud->arrow_txt = sfTexture_createFromFile("sprites/arrow.png", NULL);
	if (!hud->hud_txt || !hud->clock_txt || !hud->arrow_txt)
		return (NULL);
	hud->hud = sfSprite_create();
	hud->clock = sfSprite_create();
	hud->arrow = sfSprite_create();
	hud = create_texts(hud, player);
	if (!hud || !hud->hud || !hud->clock || !hud->arrow)
		return (NULL);
	sfSprite_setTexture(hud->hud, hud->hud_txt, 0);
	sfSprite_setTexture(hud->clock, hud->clock_txt, 0);
	sfSprite_setTexture(hud->arrow, hud->arrow_txt, 0);
	set_spr_pos(hud);
	return (hud);
}

void set_spr_pos(hud_t *hud)
{
	sfVector2f pos = {1800, 875};

	sfSprite_setPosition(hud->clock, pos);
	sfSprite_setOrigin(hud->arrow, (sfVector2f){22.5, 42});
	pos.y += 42;
	pos.x += 41;
	sfSprite_setPosition(hud->arrow, pos);
}
