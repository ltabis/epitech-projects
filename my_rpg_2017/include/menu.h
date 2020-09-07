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

#include "combat.h"
#include "particles.h"

#define NBR_BUT_CHOOSE_PLAYER 3
#define NBR_BUT_MAIN_MENU 4

#define BUTTON_NBR 9
#define SPRITE_NBR 5

#define IMG_MINIATURE "ressources/pictures/menu/choose_player/miniatures.png"
#define IMG_PLAYER "ressources/pictures/perso/perso.png"
#define IMG_ARROW_LEFT "ressources/pictures/menu/choose_player/left.png"
#define IMG_ARROW_RIGHT "ressources/pictures/menu/choose_player/right.png"
#define IMG_BG "ressources/pictures/menu/choose_player/choose_player_bg.png"
#define IMG_START "ressources/pictures/menu/choose_player/play.png"
#define IMG_LORE "ressources/pictures/menu/main_menu/lore.png"
#define SETTINGS "picture/menu.png"
#define TXT_ONE "ressources/pictures/menu/main_menu/play.png"
#define TXT_TWO "ressources/pictures/menu/main_menu/history.png"
#define TXT_TRE "ressources/pictures/menu/main_menu/tuto.png"
#define TXT_FOR "ressources/pictures/menu/main_menu/quit.png"
#define TUTB_ONE "ressources/pictures/menu/main_menu/prec.png"
#define TUTB_TWO "ressources/pictures/menu/main_menu/quit_2.png"
#define TUTB_TRE "ressources/pictures/menu/main_menu/next.png"
#define TUT_ONE "ressources/pictures/menu/main_menu/tutorial_1.png"
#define TUT_TWO "ressources/pictures/menu/main_menu/tutorial_2.png"
#define TUT_TRE "ressources/pictures/menu/main_menu/tutorial_3.png"
#define TUT_FOR "ressources/pictures/menu/main_menu/tutorial_4.png"
#define TUT_FIV "ressources/pictures/menu/main_menu/tutorial_5.png"
#define AUDIO "picture/audio_setup.png"
#define AUDIO_BUTTON "picture/audio_button.png"
#define VIDEO "picture/video_menu.png"
#define VIDEO_BUTTON "picture/video_setup.png"
#define CONTROL "picture/control_menu.png"
#define CONTROL_BUTTON "picture/controls_button.png"
#define BACK_BUTTON "ressources/pictures/menu/back.png"
#define STATS "ressources/pictures/menu/ivt_bg.png"
#define VSYNC "picture/VSYNC.png"
#define INVERT_MOUSE "picture/invert_mouse_button.png"
#define PLUS "picture/plus.png"
#define MINUS "picture/minus.png"

typedef struct button_s {
	int exist;
	sfVector2f pos;
	sfVector2f size;
	sfVector2f real_pos;
	sfIntRect rect;
	sfSprite *sprite;
} button_t;

typedef struct choose_player_s {
	int stop;
	sfEvent event;
	sfSprite *miniature;
	sfSprite *bg;
	sfIntRect rect_mini;
	sfVector2f pos_mini;
	button_t **buttons;
} choose_player_t;

typedef struct sprite_structure {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfVector2f size;
	int exist;
} sprite_s;

typedef struct text_structure {
	sfText *text;
	sfFont *font;
	int exist;
} text_s;

typedef struct line_s {
	char *line;
	struct line_s *next;
}line_t;

typedef struct text_s {
	line_t *dialog;
	int id;
	struct text_s *next;
}text_t;

int check_all_buttons(int, sfSprite **, sfRenderWindow *, sfEvent);
int check_buttons_actions_but(sfSprite *, sfRenderWindow *, int);
int check_buttons_actions_tuto(sfSprite *, sfRenderWindow *, int, sfEvent);
int check_pos(button_t *, sfVector2i);
int main_menu(sfRenderWindow *, sfSprite **, sfSprite *);
void compute_background_menu(sfRenderWindow *, background_t *,
	sfClock *, sfSprite *);
void display_background_menu(background_t *, int);
void free_choose_menu(choose_player_t *);
void launch_tutorial(sfRenderWindow *);
void launch_lore(sfRenderWindow *);
void move_rect_miniature_left(choose_player_t *);
void move_rect_miniature_right(choose_player_t *);
void set_menu_button_pos(sfSprite **);
void set_tutorial_but_pos(sfSprite **);
choose_player_t *init_menu_choose_player(void);
sfSprite *create_corewar_sprite(void);
sfSprite **create_menu_buttons(void);
sfSprite **create_tutorial_buttons(void);
sfSprite **create_tutorial_sprites(sfVector2f);

#endif /* !MENU_H_ */
