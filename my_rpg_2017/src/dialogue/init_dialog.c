/*
** EPITECH PROJECT, 2018
** init_dialog.c
** File description:
** initialisation for dialogue.c
*/

#include <stdlib.h>
#include "dialogue.h"
#include "proto.h"

void prepare_dialogue_save(npc_t *npc_tmp, text_t *txt_tmp, int tile_nb)
{
	for (; npc_tmp != NULL && tile_nb != npc_tmp->id;
	npc_tmp = npc_tmp->next);
	for (; txt_tmp != NULL && npc_tmp->txt_id != txt_tmp->id;
	txt_tmp = txt_tmp->next);
}

void init_dialogue(dialog_t *dialog, text_t *text)
{
	dialog->text_scale = create_vect(4, 3);
	dialog->text_bg = create_sprite(TEXT_BG);
	dialog->text = sfText_create();
	dialog->font = sfFont_createFromFile(FONT);
	sfSprite_setScale(dialog->text_bg, dialog->text_scale);
	sfSprite_setPosition(dialog->text_bg, create_vect(220, 850));
	sfText_setFont(dialog->text, dialog->font);
	sfText_setString(dialog->text, text->dialog->line);
	sfText_setCharacterSize(dialog->text, 26);
	sfText_setColor(dialog->text, sfWhite);
	sfText_setPosition(dialog->text, create_vect(300, 930));
}
