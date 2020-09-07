/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils functions
*/

#include "../include/combat.h"
#include "../include/base.h"
#include "../include/monster.h"
#include <stdlib.h>

void choose_monsters(tiles_t *tiles, monster_t *monsters,
	unsigned int nbr_monsters)
{
	unsigned int random = rand() % nbr_monsters;

	if (tiles->entity == 1) {
		for (unsigned int i = 0; i < random; i++)
			monsters = monsters->next;
		tiles->ptr = create_new_monster_entity(monsters);
	} else
		tiles->ptr = NULL;
}

hud_t *create_texts(hud_t *hud, player_stat_t *player)
{
	sfFont *font = sfFont_createFromFile("pixelmix.ttf");

	hud->hp = sfText_create();
	hud->sh = sfText_create();
	if (!hud->hp || !hud->sh || !(hud->st = sfText_create()) || !font)
		return (NULL);
	sfText_setFont(hud->hp, font);
	sfText_setFont(hud->sh, font);
	sfText_setFont(hud->st, font);
	sfText_setString(hud->hp,
	my_strcat(convert_nbr_to_str(player->stats->current_hp)
	, my_strcat(" / ", convert_nbr_to_str(player->stats->max_hp))));
	sfText_setString(hud->sh,
	my_strcat(convert_nbr_to_str(player->stats->current_sp)
	, my_strcat(" / ", convert_nbr_to_str(player->stats->max_sp))));
	sfText_setString(hud->st,
	my_strcat(convert_nbr_to_str(player->stats->current_st)
	, my_strcat(" / ", convert_nbr_to_str(player->stats->max_st))));
	set_text_characteristics(hud);
	return (hud);
}

char *convert_nbr_to_str(int nbr)
{
	int lenght = 1;
	int tmp = nbr;
	char *str = NULL;

	for (; nbr >= 10; lenght++, nbr = nbr / 10);
	str = malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (NULL);
	str[0] = (tmp % 10) + 48;
	for (lenght = 1; tmp >= 10; lenght++) {
		tmp = tmp / 10;
		str[lenght] = (tmp % 10) + 48;
	}
	str[lenght] = 0;
	my_revstr(str);
	return (str);
}

void set_text_characteristics(hud_t *hud)
{
	sfFloatRect textRect = sfText_getLocalBounds(hud->sh);

	sfText_setOrigin(hud->sh, (sfVector2f){textRect.left + textRect.width,
	textRect.top + textRect.height});
	textRect = sfText_getLocalBounds(hud->hp);
	sfText_setOrigin(hud->hp, (sfVector2f){textRect.left + textRect.width,
	textRect.top + textRect.height});
	textRect = sfText_getLocalBounds(hud->st);
	sfText_setOrigin(hud->st, (sfVector2f){textRect.left + textRect.width,
	textRect.top + textRect.height});
	sfText_setPosition(hud->sh, (sfVector2f){1870, 990});
	sfText_setPosition(hud->hp, (sfVector2f){1870, 1010});
	sfText_setPosition(hud->st, (sfVector2f){1870, 1030});
	sfText_setScale(hud->sh, (sfVector2f){0.7f, 0.7f});
	sfText_setScale(hud->hp, (sfVector2f){0.7f, 0.7f});
	sfText_setScale(hud->st, (sfVector2f){0.7f, 0.7f});
}

void draw_texts(map_cb_t *map, sfRenderWindow *w)
{
	sfFloatRect textRect = sfText_getLocalBounds(map->hud->sh);

	sfText_setOrigin(map->hud->sh,
	(sfVector2f){textRect.left + textRect.width,
	textRect.top + textRect.height});
	textRect = sfText_getLocalBounds(map->hud->hp);
	sfText_setOrigin(map->hud->hp,
	(sfVector2f){textRect.left + textRect.width,
	textRect.top + textRect.height});
	textRect = sfText_getLocalBounds(map->hud->st);
	sfText_setOrigin(map->hud->st,
	(sfVector2f){textRect.left + textRect.width,
	textRect.top + textRect.height});
	sfText_setPosition(map->hud->sh, (sfVector2f){1870, 990});
	sfText_setPosition(map->hud->hp, (sfVector2f){1870, 1010});
	sfText_setPosition(map->hud->st, (sfVector2f){1870, 1030});
	sfRenderWindow_drawText(w, map->hud->hp, NULL);
	sfRenderWindow_drawText(w, map->hud->sh, NULL);
	sfRenderWindow_drawText(w, map->hud->st, NULL);
}
