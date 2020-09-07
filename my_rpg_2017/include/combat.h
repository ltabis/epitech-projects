/*
** EPITECH PROJECT, 2017
** combat.h
** File description:
** prototypes for a particular program
*/

#ifndef COMBAT_H_
#define COMBAT_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdlib.h>
#include "monster.h"

#define PI 3.14159265359

#define MAP_SIZE 20
#define MAP_ZOOM 64
#define BAR_SIZE_X 584
#define BAR_SIZE_Y 18

#define PLAYER_TURN 1
#define ENEMY_TURN -1

#define NBR_STATS 6
#define ESC_ONE "ressources/pictures/menu/main_menu/rep.png"
#define ESC_TWO "ressources/pictures/menu/main_menu/fuir.png"
#define ESC_TRE "ressources/pictures/menu/main_menu/quit_2.png"

enum particle_shape_e {POINTS, CIRCLE, SQUARE};

typedef enum particle_shape_e e_shape;

typedef struct particle_s {
	e_shape shape;
	sfColor color;
	sfVector2i pos;
	unsigned int lenght;
	unsigned int nbr_particules;
	unsigned int speed;
} particle_t;

typedef struct framebuffer_s {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

typedef struct background_s {
	sfTexture *txt;
	sfSprite *spr;
	framebuffer_t *buffer;
} background_t;

typedef struct particle_act_s {
	framebuffer_t *buffer;
	particle_t opt;
	int id;
	sfSprite *spr;
	sfTexture *txt;
	struct particle_act_s *next;
} particle_act_t;

enum tile_type_e {GROUND1, GROUND2, GROUND3,
	GROUND4, GROUND5, FOLLIAGE, TREE};

typedef enum tile_type_e e_tile_type;

typedef struct stats_s {
	float current_hp;
	float current_sp;
	float current_st;
	float max_hp;
	float max_sp;
	float max_st;
	int att;
	int def;
	int spd;
	int lvl;
	int exp;
} stats_t;

typedef struct tiles_s {
	e_tile_type type;
	monster_t *ptr;
	char cursor;
	char entity;
} tiles_t;

typedef struct player_stat_s {
	sfSprite *perso;
	sfTexture *tilemap;
	sfIntRect rect;
	sfVector2f pl_pos;
	stats_t *stats;
	sfRectangleShape *hp_bar;
	sfRectangleShape *sp_bar;
	sfRectangleShape *st_bar;
	int invert;
} player_stat_t;

typedef struct tilemap_s {
	sfTexture *plain_tilemap;
	sfTexture *desert_tilemap;
	sfTexture *scorched_tilemap;
	sfTexture *moon_tilemap;
	sfTexture *corrupted_tilemap;
} tilemap_t;

typedef struct hud_s {
	sfTexture *hud_txt;
	sfSprite *hud;
	sfTexture *clock_txt;
	sfSprite *clock;
	sfTexture *arrow_txt;
	sfSprite *arrow;
	sfText *hp;
	sfText *sh;
	sfText *st;
} hud_t;

typedef struct map_cb_s {
	sfSprite *perso;
	hud_t *hud;
	sfVector2f **map_2d;
	tiles_t **tiles;
	sfVector2f map_pos;
	sfTexture *ter_txt;
	sfSprite *ter_spr;
	float map_zoom;
	int turn;
	sfText *play;
	char initialisation;
	sfRenderStates state;
} map_cb_t;

void change_player_stat(player_stat_t *, map_cb_t *);
void check_valid_action(map_cb_t *, sfVector2i,
	sfVector2i, player_stat_t *);
void set_escape_but_pos(sfSprite **);
sfSprite **create_escape_buttons(void);
char display_escape_menu(sfRenderWindow *, map_cb_t *);
sfRectangleShape *launch_escape_anim(sfRenderWindow *, map_cb_t *);
sfSprite **create_end_buttons(void);
void set_up_end_texts_win(sfText *, sfText *);
void set_up_end_texts_lose(sfText *, sfText *);
void create_white_background(background_t *, sfRenderWindow *, map_cb_t *);
int launch_end_win_scene(map_cb_t *,
	sfRenderWindow *, background_t *);
int launch_end_lose_scene(map_cb_t *,
	sfRenderWindow *, background_t *);
char end_combat(player_stat_t *, map_cb_t *,
	background_t *, sfRenderWindow *);
void display_background(background_t *, int,
	sfRenderWindow *, player_stat_t *);
void change_background_color_1(background_t *, unsigned int,
	int, player_stat_t *);
void change_background_color_2(background_t *, unsigned int,
	int, player_stat_t *);
void check_valid_coordinates(sfVector2i *);
unsigned int attack_player(map_cb_t *, sfVector2i *,
	sfVector2i *, player_stat_t *);
void teleport_to_player(map_cb_t *, player_stat_t *,
	sfVector2i *);
void search_for_prey_or_move(sfVector2i *, map_cb_t *, player_stat_t *);
void change_color(map_cb_t *, sfVector2i *);
void display_entity(map_cb_t *, sfVector2i *, sfRenderWindow *, sfVector2f *);
void move_monster(sfVector2i *, map_cb_t *);
void execute_monster_actions(sfVector2i *, map_cb_t *, player_stat_t *);
void compute_enemy_turn(map_cb_t *, player_stat_t *);
void choose_tile_type(tiles_t *);
int choose_special_tile(tiles_t *, int);
monster_t *create_new_monster_entity(monster_t *);
void end_inventory_anim(sfRectangleShape *, sfRenderWindow *);
sfRectangleShape *launch_inventory_anim(sfRenderWindow *);
void open_inventory(sfRenderWindow *);
void change_text_string(int, int, hud_t *);
void change_text_string_hp(int, int, hud_t *);
void draw_texts(map_cb_t *, sfRenderWindow *);
void set_text_characteristics(hud_t *);
hud_t *create_texts(hud_t *, player_stat_t *);
char *convert_nbr_to_str(int);
void change_player_pos(map_cb_t *, player_stat_t *);
void check_controls(map_cb_t *, sfVector2i, player_stat_t *, sfRenderWindow *);
void change_cursor(map_cb_t *, sfVector2i);
void check_if_quad_got_clicked(map_cb_t *, sfRenderWindow *,
	sfVector2i, player_stat_t *);
void compute_player_turn(player_stat_t *, map_cb_t *, sfRenderWindow *);
void compute_turns(player_stat_t *, map_cb_t *, sfRenderWindow *);
void choose_monsters(tiles_t *, monster_t *, unsigned int);
unsigned int count_monsters(monster_t *);
void draw_hud_status(player_stat_t *, sfRenderWindow *, map_cb_t *);
stats_t *create_player_stats(void);
player_stat_t *create_player(void);
void change_hud_colors(player_stat_t *);
hud_t *create_hud(player_stat_t *);
void set_spr_pos(hud_t *);
map_cb_t init_elements(monster_t *, player_stat_t *, tilemap_t *);
void set_trees(map_cb_t, sfVector2i, sfRenderWindow *);
void augment_or_decrease_size(sfEvent, map_cb_t *);
void update_2d_map(map_cb_t *);
char compute_controls(sfEvent, map_cb_t *, sfRenderWindow *);
void check_camera_movement(map_cb_t *, sfRenderWindow *);
void call_combat_system(sfRenderWindow *, tilemap_t, player_stat_t *);
sfRenderWindow *set_up_window(void);
tiles_t **create_random_tiles(monster_t *);
void draw_tile_lines(sfVector2f **, sfVector2i, sfVector2i, sfRenderWindow *);
sfRenderStates set_state(sfTexture *);
sfVector2f **create_2d_map(void);
void draw_2d_map(sfRenderWindow *, map_cb_t, sfVector2i, sfRenderStates);
sfVector2f project_iso_point(int, int, int);
sfVertexArray *create_tiles(map_cb_t *, sfVector2i);
sfVertexArray *create_lines(sfVector2f *, sfVector2f *);
void check_display_on_y_axes(sfVector2i, sfVector2i,
	map_cb_t, sfRenderWindow *);
void check_display_on_x_axes(sfVector2i, sfVector2i,
	map_cb_t, sfRenderWindow *);
void check_display_on_both_axes(sfVector2i, map_cb_t,
	sfRenderWindow *, sfRenderStates);
sfVector2i get_player_pos(map_cb_t *);
sfSprite **create_end_buttons_lose(void);
sfSprite *create_end_button_win(void);
int check_buttons_actions(sfSprite *, sfRenderWindow *, int);
char check_buttons_actions_escape(sfSprite *, sfRenderWindow *,
	int, sfEvent);
char check_buttons_ret_value(sfSprite **, sfRenderWindow *,
	sfEvent);

#endif /* !COMBAT_H_ */
