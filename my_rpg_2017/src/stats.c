/*
** EPITECH PROJECT, 2018
** stats.c
** File description:
** functions for stats
*/

#include "my.h"
#include "combat.h"
#include "proto.h"

sfText *create_stat_txt(int stat, sfFont *font, char *str, sfVector2f pos)
{
	sfText *txt = sfText_create();

	sfText_setFont(txt, font);
	if (stat != -1)
		str = convert_nbr_to_str(stat);
	sfText_setString(txt, str);
	sfText_setCharacterSize(txt, 34);
	sfText_setColor(txt, sfWhite);
	sfText_setPosition(txt, pos);
	return (txt);
}

char *get_life(int current, int max)
{
	char *current_hp = convert_nbr_to_str(current);
	char *max_hp = convert_nbr_to_str(max);
	char *life = NULL;

	life = my_strcat(current_hp, "/");
	life = my_strcat(life, max_hp);
	return (life);
}

sfText **update_stats(sfView *view, stats_t *stats)
{
	char *life = get_life(stats->current_hp, stats->max_hp);
	sfFont *font = sfFont_createFromFile(FONT);
	sfText **txt_stats = malloc(sizeof(sfText *) * NBR_STATS);
	sfVector2f pos = sfView_getCenter(view);

	if (txt_stats != NULL) {
		txt_stats[0] = create_stat_txt(stats->lvl, font, NULL,
		create_vect(pos.x - 200, pos.y - 250));
		txt_stats[1] = create_stat_txt(stats->exp, font, NULL,
		create_vect(pos.x - 200, pos.y - 170));
		txt_stats[2] = create_stat_txt(stats->att, font, NULL,
		create_vect(pos.x - 200, pos.y - 40));
		txt_stats[3] = create_stat_txt(stats->def, font, NULL,
		create_vect(pos.x - 200, pos.y + 40));
		txt_stats[4] = create_stat_txt(stats->spd, font, NULL,
		create_vect(pos.x - 200, pos.y + 120));
		txt_stats[5] = create_stat_txt(-1, font, life,
		create_vect(pos.x - 200, pos.y + 200));
	}
	return (txt_stats);
}

void disp_stats(sfText **txt, sfRenderWindow *window)
{
	for (int i = 0; i < NBR_STATS; i++) {
		sfRenderWindow_drawText(window, txt[i], NULL);
	}
}

void free_txt_stats(sfText **txt)
{
	for (int i = 0; i < NBR_STATS; i++) {
		sfText_destroy(txt[i]);
	}
}
