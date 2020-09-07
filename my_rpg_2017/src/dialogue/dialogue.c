/*
** EPITECH PROJECT, 2018
** dialogue.c
** File description:
** functions for dialogues
*/

#include "combat.h"
#include "dialogue.h"
#include "my.h"
#include "proto.h"

void display_dialogue(sfRenderWindow *window, dialog_t *dialog)
{
	sfRenderWindow_drawSprite(window, dialog->text_bg, NULL);
	sfRenderWindow_drawText(window, dialog->text, NULL);
	sfRenderWindow_display(window);
}

void manage_dialogue_event(sfRenderWindow *window, sfEvent event, text_t *text)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event.type == sfEvtKeyReleased) {
		if ((event.key.code == sfKeyReturn ||
		event.key.code == sfKeySpace) && text->dialog->next)
			text->dialog = text->dialog->next;
	}
}

void free_dialogue(dialog_t *dialog)
{
	sfSprite_destroy(dialog->text_bg);
	sfFont_destroy(dialog->font);
	sfText_destroy(dialog->text);
	free(dialog);
}

int check_text(text_t *txt_tmp, dialog_t *dialog, sfEvent event)
{
	if (txt_tmp->dialog && txt_tmp->dialog->next == NULL &&
	event.key.code == sfKeySpace)
		return (0);
	else {
		sfText_setString(dialog->text, txt_tmp->dialog->line);
		return (1);
	}
}

void launch_dialogue(UNUSED npc_t *npc, sfRenderWindow *window,
	UNUSED int tile_nb, text_t *text)
{
	sfEvent event;
	dialog_t *dialog = malloc(sizeof(dialog_t));
	text_t *txt_tmp = text;

	if (dialog == NULL)
		my_put_err("Error during memory allocation (dialog struct)\n");
	init_dialogue(dialog, txt_tmp);
	sfSprite_setPosition(dialog->text_bg, create_vect(220, 850));
	for (int active = 1; sfRenderWindow_isOpen(window) && active == 1;) {
		display_dialogue(window, dialog);
		while (sfRenderWindow_pollEvent(window, &event)) {
			active = check_text(txt_tmp, dialog, event);
			manage_dialogue_event(window, event, txt_tmp);
		}
	}
	free_dialogue(dialog);
}
