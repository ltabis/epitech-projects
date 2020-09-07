/*
** EPITECH PROJECT, 2018
** tab_ptr_fct.c
** File description:
** function pointer
*/

#include <fcntl.h>
#include "proto.h"
#include "combat.h"
#include "dialogue.h"
#include "my.h"

void reset_view(map_all_t *map, sfRenderWindow *window)
{
	sfView_setCenter(map->view_map, (sfVector2f){map->player->case_x * 100,
	map->player->case_y * 100});
	sfRenderWindow_setView(window, map->view_map);
}

void fct_tab(map_all_t *map, int nbr, sfRenderWindow *window, sfVector2i pos)
{
	void (*fct[20])(map_all_t *, sfRenderWindow *, int) =
	{swap, swap_map, swap_a, start_combat_mod, ship_to_map_1,
	map_1_to_map_2, map_2_to_map_1, map_1_to_map_3, map_3_to_map_1,
	map_2_to_map_3, map_3_to_map_2, map_1_to_donjon_1, donjon_1_to_map_1,
	map_2_to_donjon_2, donjon_2_to_map_2, map_3_to_donjon_3,
	donjon_3_to_map_3, map_2_to_boss, boss_to_map_2, launch_end};

	if (nbr - 3 < 20 && nbr - 3 >= 0) {
		fct[nbr - 3](map, window, 0);
		if (nbr != 11 && nbr != 13 && nbr != 15)
			reset_view(map, window);
	} else if (nbr == 23) {
		sfView_setCenter(map->view_map, (sfVector2f){960, 540});
		sfRenderWindow_setView(window, map->view_map);
		map->rect = choose_player(map->player, window, map->view_map);
		reset_view(map, window);
	} else if (nbr == 24) {
		launch_dialogue(map->npc, window, 0, map->txt);
	} else
		nbr >= 25 ? env_actions(map, window, pos, nbr) : 0;
}

void start_combat_mod(map_all_t *map, sfRenderWindow* window,
	UNUSED int back)
{
	turn_off_music(map);
	sfView_setCenter(map->view_map, (sfVector2f){1920 / 2, 1080 / 2});
	sfRenderWindow_setView(window, map->view_map);
	call_combat_system(window, *map->tilemap, map->pl_stats);
	if (map->pl_stats->stats->current_hp == 0)
		map->pl_stats->stats->current_hp =
		map->pl_stats->stats->max_hp;
	sfMusic_stop(map->audio->msc_comb);
	if ((map->pl_stats->stats->current_hp != -1)) {
		sfMusic_play(map->audio->msc_norm);
		map->map[map->player->case_y + 1]
		[map->player->case_x + 2]->option = 1;
		map->map[map->player->case_y + 2]
		[map->player->case_x + 1]->option = 1;
		map->map[map->player->case_y + 1]
		[map->player->case_x]->option = 1;
		map->map[map->player->case_y]
		[map->player->case_x + 1]->option = 1;
	}
}

void launch_end(map_all_t *map, sfRenderWindow *window,
	UNUSED int back)
{
	sfSprite *corewar = sfSprite_create();
	sfTexture *txt =
	sfTexture_createFromFile("ressources/pictures/pull.png", NULL);
	sfClock *clock = sfClock_create();
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 100000.0;

	if (!corewar || !txt || !clock)
		return;
	sfView_setCenter(map->view_map, (sfVector2f){1920 / 2, 1080 / 2});
	sfSprite_setTexture(corewar, txt, 0);
	sfRenderWindow_setView(window, map->view_map);
	while (seconds < 20) {
		sfRenderWindow_clear(window, sfBlack);
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 100000.0;
		sfRenderWindow_drawSprite(window, corewar, NULL);
		sfRenderWindow_display(window);
	}
	map->pl_stats->stats->current_hp = -1;
	sfClock_destroy(clock);
}

void turn_off_music(map_all_t *map)
{
	sfSprite_setTextureRect(map->pl_stats->perso,
	(sfIntRect){map->rect, 0, 35, 35});
	sfMusic_stop(map->audio->msc_norm);
	sfMusic_play(map->audio->msc_comb);
}
