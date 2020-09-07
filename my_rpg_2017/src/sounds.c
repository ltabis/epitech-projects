/*
** EPITECH PROJECT, 2018
** sounds.c
** File description:
** music and sounds initialisation
*/

#include "proto.h"
#include "sound.h"

sound_t *set_sounds(void)
{
	sound_t *audio = malloc(sizeof(sound_t));

	if (!audio)
		return (NULL);
	audio->msc_ship = sfMusic_createFromFile("music/ship.ogg");
	audio->msc_norm = sfMusic_createFromFile("music/sanctuary.ogg");
	audio->msc_comb = sfMusic_createFromFile("music/combat.ogg");
	if (!audio->msc_ship ||
	!audio->msc_norm || !audio->msc_comb)
		return (NULL);
	sfMusic_setLoop(audio->msc_ship, sfTrue);
	sfMusic_setLoop(audio->msc_norm, sfTrue);
	sfMusic_setLoop(audio->msc_comb, sfTrue);
	return (audio);
}

sfMusic *create_menu_music(void)
{
	sfMusic *music = sfMusic_createFromFile("music/menu.ogg");

	if (!music)
		return (NULL);
	sfMusic_setLoop(music, sfTrue);
	sfMusic_play(music);
	return (music);
}

void destroy_all_musics(sound_t *audio)
{
	sfMusic_destroy(audio->msc_ship);
	sfMusic_destroy(audio->msc_norm);
	sfMusic_destroy(audio->msc_comb);
}
