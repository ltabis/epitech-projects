/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** functions for initialisation
*/

#include "proto.h"
#include "menu.h"

button_t **init_menu_choose_player_buttons(void)
{
	button_t **result = malloc(sizeof(button_t *) * NBR_BUT_CHOOSE_PLAYER);

	if (result == NULL)
		return (NULL);
	result[0] = create_but(create_vect(1100, 500), create_vect(128, 128),
		create_sprite(IMG_ARROW_LEFT), create_rect(0, 0, 128, 128));
	result[1] = create_but(create_vect(1484, 500), create_vect(128, 128),
		create_sprite(IMG_ARROW_RIGHT), create_rect(0, 0, 128, 128));
	result[2] = create_but(create_vect(1650, 780), create_vect(128, 128),
		create_sprite(IMG_START), create_rect(0, 0, 128, 128));
	for (int i = 0; i < NBR_BUT_CHOOSE_PLAYER; i++)
		if (result[i] == NULL)
			return (NULL);
	return (result);
}

choose_player_t *init_menu_choose_player(void)
{
	choose_player_t *var = malloc(sizeof(choose_player_t));
	sfVector2f mini_scale = {5, 5};
	sfVector2f bg_scale = {3, 2.6};

	if (var == NULL)
		return (NULL);
	var->stop = 0;
	var->bg = create_sprite(IMG_BG);
	sfSprite_scale(var->bg, bg_scale);
	var->rect_mini = create_rect(0, 0, 80, 80);
	var->pos_mini = create_vect(350, 340);
	var->miniature = create_sprite(IMG_MINIATURE);
	sfSprite_scale(var->miniature, mini_scale);
	sfSprite_setPosition(var->miniature, var->pos_mini);
	sfSprite_setTextureRect(var->miniature, var->rect_mini);
	var->buttons = init_menu_choose_player_buttons();
	return (var);
}

void free_choose_menu(choose_player_t *var)
{
	sfSprite_destroy(var->miniature);
	sfSprite_destroy(var->bg);
	for (int i = 0; i < NBR_BUT_CHOOSE_PLAYER; i++) {
		sfSprite_destroy(var->buttons[i]->sprite);
	}
}

void prepare_player(player_t *tmp)
{
	tmp->rect = create_rect(0, 0, 35, 35);
	tmp->position = create_vect(1320, 530);
	sfSprite_setPosition(tmp->sprite, tmp->position);
	sfSprite_setTextureRect(tmp->sprite, tmp->rect);
}

