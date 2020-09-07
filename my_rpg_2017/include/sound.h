/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef SOUND_H_
#define SOUND_H_

typedef struct sound_s {
	sfMusic *msc_ship;
	sfMusic *msc_norm;
	sfMusic *msc_comb;
	sfSound *snd_steps;
} sound_t;

sound_t *set_sounds(void);
sfMusic *create_menu_music(void);
void destroy_all_musics(sound_t *);

#endif /* !SOUND_H_ */
