/*
** EPITECH PROJECT, 2018
** menu.h
** File description:
** headers for all menus
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef MENU_H_
#define MENU_H_

#define NBR_BUT_CHOOSE_PLAYER 3
#define IMG_MINIATURE "ressources/pictures/menu/miniatures.png"
#define IMG_PLAYER "ressources/pictures/menu/perso.png"
#define IMG_ARROW_LEFT "ressources/pictures/menu/left.png"
#define IMG_ARROW_RIGHT "ressources/pictures/menu/right.png"
#define IMG_BG "ressources/pictures/menu/choose_player_bg.png"
#define IMG_START "ressources/pictures/menu/play.png"

typedef struct button_s {
	int exist;
	sfVector2f pos;
	sfVector2f size;
	sfVector2f real_pos;
	sfIntRect rect;
	sfSprite *sprite;
}button_t;

typedef struct choose_player_s {
	sfEvent event;
	sfSprite *miniature;
	sfSprite *bg;
	sfIntRect rect_mini;
	sfVector2f pos_mini;
	button_t **buttons;
}choose_player_t;

int check_pos(button_t *, sfVector2i);
choose_player_t *init_menu_choose_player(void);
button_t *create_but(sfVector2f pos, sfVector2f size, sfSprite *, sfIntRect);

#endif /* _MENU_H_ */
