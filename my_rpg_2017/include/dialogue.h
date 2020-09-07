/*
** EPITECH PROJECT, 2018
** dialogue.h
** File description:
** headers for dialogue scenes
*/

#ifndef DIALOGUE_H_
#define DIALOGUE_H_

#include "proto.h"

#define TEXT_BG "ressources/pictures/dialogue/txt_bg.png"
#define DIALOGUE_BG "ressources/pictures/dialogue/dialog_bg.png"

typedef struct dialog_s {
	sfSprite *text_bg;
	sfText *text;
	sfFont *font;
	sfVector2f text_scale;
} dialog_t;

void init_dialogue(dialog_t *, text_t *);
void prepare_dialogue_save(npc_t *, text_t *, int);
void launch_dialogue(npc_t *, sfRenderWindow *, int, text_t *);

#endif /* !DIALOGUE_H_ */
