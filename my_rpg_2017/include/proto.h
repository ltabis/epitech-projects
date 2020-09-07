/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef PROTO_H_
#define PROTO_H_

#include "menu.h"
#include "map.h"
#include "my.h"
#include "sound.h"

#define TITLE "my_rpz"
#define FONT "ressources/fonts/pixelmix.ttf"
#define PATH_ITEM "ressources/obj.txt"

typedef enum type_npc {NONE, MERCHAND, QUESTER} type_e;

typedef struct npc_s {
	int id;
	int txt_id;
	int quest;
	type_e type;
	struct npc_s *next;
} npc_t;

typedef struct obj_stat_s {
	int att;
	int def;
	int spd;
} obj_stat_t;

typedef struct obj_s {
	int id;
	char *name;
	sfSprite *sprite;
	obj_stat_t *stats;
	struct obj_s *next;
} obj_t;

typedef struct game_structure {
	sprite_s **sprite;
	button_t **button;
	sfText **txt_stats;
	obj_t *obj;
	int fps;
	int volume;
	sfText *sound;
	sfText *framerate;
	int v_sync;
} game_s;

typedef struct map_all_s {
	int rect;
	npc_t *npc;
	text_t *txt;
	tab_map_t *tab_map;
	map_t ***map;
	move_t *move;
	sfView *view_map;
	sfView *view_mini_map;
	sfTexture *texture_map;
	player_t *player;
	game_s *game;
	player_stat_t *pl_stats;
	tilemap_t *tilemap;
	sound_t *audio;
	sfSprite *spr_obj;
	sfTexture *txt_obj;
	sfSprite **spr_npcs;
	sfTexture *txt_npcs;
} map_all_t;

int check_button(button_t *, sfVector2f);
int check_env_variable(char **);
int check_settings_exist(game_s *, int);
int choose_player(player_t *, sfRenderWindow *, sfView *);
int init_struct(game_s *);
int *init_inventory(void);
void analyse_event(sfEvent, map_all_t *, sfRenderWindow *);
void anim_player(map_all_t *, int);
void audio_setup(map_all_t *, sfRenderWindow *);
void back_fct(map_all_t *, sfRenderWindow *);
void button_activate_fct_pointer(map_all_t *, sfVector2f, sfRenderWindow *);
void button_click_fct_pointer(game_s *, sfVector2f);
void button_hover_fct_pointer(game_s *, sfVector2f);
void check_sprite_path(char *);
void control_setup(map_all_t *, sfRenderWindow *);
void display_fct(map_all_t *, sfRenderWindow *, sfView *);
void disp_inventory(sfRenderWindow *, sfView *, obj_t *, int *);
void disp_map(map_all_t *, sfRenderWindow*, int);
void disp_stats(sfText **, sfRenderWindow *);
void fct_tab(map_all_t *, int, sfRenderWindow *, sfVector2i);
void key_fct_array(sfEvent, map_all_t *);
void launch_2d_map(char *, char *, sfRenderWindow *);
void load_map(map_all_t *);
void manage_cursor_move(sfMouseMoveEvent, sfVector2f *);
void manage_mouse_click(sfMouseButtonEvent, sfVector2f *);
void menu(map_all_t *, sfRenderWindow *, int);
void mouse_event(sfEvent, map_all_t *, sfRenderWindow *);
void move_rect_player_left(player_t *);
void move_rect_player_right(player_t *);
void option_screen(map_all_t *);
void prepare_player(player_t *);
void print_text(char *, sfRenderWindow *);
void set_x_y(int *, int *, map_all_t *);
void start_combat_mod(map_all_t *, sfRenderWindow *, int);
void stats_window(map_all_t *);
void swap(map_all_t *, sfRenderWindow *, int);
void swap_a(map_all_t *, sfRenderWindow *, UNUSED int);
void swap_map(map_all_t *, sfRenderWindow *, int);
void set_sync(map_all_t *, sfRenderWindow *);
void turn(map_all_t *, sfRenderWindow *, sfClock *);
void video_setup(map_all_t *, sfRenderWindow *);
sfIntRect create_rect(int, int, int, int);
sfSprite *create_sprite(char *);
sfRenderWindow *create_window(void);
sfText **update_stats(sfView *, stats_t *);
sfTexture *create_texture(char *);
sfVector2f create_vect(int, int);
sfView *down(sfView *, int, map_all_t *, sfRenderWindow *);
sfView *left(sfView *, int, map_all_t *, sfRenderWindow *);
sfView *right(sfView *, map_all_t *, sfRenderWindow *);
sfView *up(sfView *, int, map_all_t *, sfRenderWindow *);
button_t *create_but(sfVector2f, sfVector2f, sfSprite *, sfIntRect);
game_s *game_initialisation(game_s *, sfView *);
map_all_t *init_struct_map(char *, char *);
npc_t *npc_parser(char *);
obj_t *obj_parser(char *);
sprite_s *sprite_init(sprite_s *, sfVector2f, sfVector2f, char *);
text_t *text_parser(char *);
void ship_to_map_1(map_all_t *, sfRenderWindow *, UNUSED int);
void map_1_to_map_2(map_all_t *, sfRenderWindow *, UNUSED int);
void map_2_to_map_1(map_all_t *, sfRenderWindow *, UNUSED int);
void map_1_to_map_3(map_all_t *, sfRenderWindow *, UNUSED int);
void map_3_to_map_1(map_all_t *, sfRenderWindow *, UNUSED int);
void map_2_to_map_3(map_all_t *, sfRenderWindow *, UNUSED int);
void map_3_to_map_2(map_all_t *, sfRenderWindow *, UNUSED int);
void map_1_to_donjon_1(map_all_t *, sfRenderWindow *, UNUSED int);
void donjon_1_to_map_1(map_all_t *, sfRenderWindow *, UNUSED int);
void map_2_to_donjon_2(map_all_t *, sfRenderWindow *, UNUSED int);
void donjon_2_to_map_2(map_all_t *, sfRenderWindow *, UNUSED int);
void map_3_to_donjon_3(map_all_t *, sfRenderWindow *, UNUSED int);
void donjon_3_to_map_3(map_all_t *, sfRenderWindow *, UNUSED int);
void map_2_to_boss(map_all_t *, sfRenderWindow *, UNUSED int);
void boss_to_map_2(map_all_t *, sfRenderWindow *, UNUSED int);
void invert_key(map_all_t *map_all, sfRenderWindow *window);
void exit_game(map_all_t *map_all, sfRenderWindow *window);
void framerate_gestion(map_all_t *map_all, sfVector2f click_pos
	, sfRenderWindow *window);
void music_gestion(map_all_t *map_all, sfVector2f click_pos);
sfVector2f set_pos_sprite(sprite_s *sprite, sfView *view);
void set_pos_button(sfVector2f screen_center, button_t *button);
void set_pos_text(sfView *view, game_s *g);
void launch_end(map_all_t *, sfRenderWindow *, UNUSED int);
void init_npcs(map_all_t *);
void display_npc(sfRenderWindow *, sfVector2i, map_all_t *);
float reset_time(sfClock *, float, map_all_t *, sfRenderWindow *);
void init_move(map_all_t *map);
int png_up(map_all_t *mp);
void up_nd(map_all_t *mp);
int png_down(map_all_t *mp);
void down_nd(map_all_t *mp);
int png_left(map_all_t *mp);
void move_png(map_all_t *maps, sfRenderWindow* w);
void turn_off_music(map_all_t *);
void env_actions(map_all_t *, sfRenderWindow *, sfVector2i, int);
void reset_view(map_all_t *, sfRenderWindow *);

#endif /* !PROTO_H_ */
