/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "structs.h"
#ifndef PROTO_H_
#define PROTO_H_

#define BLOCK1 "Sprites/Background/Box1.png"
#define BLOCK2 "Sprites/Background/Box2.png"
#define BLOCK3 "Sprites/Background/Box3.png"

#define SPIKE1 "Sprites/Background/Spike1.png"
#define SPIKE2 "Sprites/Background/Spike2.png"
#define SPIKE3 "Sprites/Background/Spike3.png"

#define FLOOR1 "Sprites/Background/Floor_block1.png"
#define FLOOR2 "Sprites/Background/Floor_block2.png"
#define FLOOR3 "Sprites/Background/Floor_block3.png"

#define ENN1 "Sprites/Background/Ennemie_1.png"
#define ENN2 "Sprites/Background/Ennemie_2.png"
#define ENN3 "Sprites/Background/Ennemie_3.png"

#define FINISH "Sprites/Background/Finish.png"

int my_strcmp(char *, char *);
char *my_revstr(char *);
int launch_menu(object_t *, map_t *, int, char *, sfText *);
int find_y(char *);
int read_file_content(int);
int launch_infinity_mod(void);
int launch_normal_mod(map_t *, int, char *);
int check_file_content_level_1(char *);
int verify_file_stat(char *, int);
int check_usage_and_params(char *, int, char **);
int check_input_when_pause(sfRenderWindow *, float);
int display_lost_game(sfRenderWindow *, sfText *);
int display_won_game(sfRenderWindow *, sfText *);
sfMusic *configure_music(sfMusic *);
object_t check_block_type(object_t, object_t, sfRenderWindow *, int, sfText *);
map_t *load_map_from_file(char *);
map_t *instantiate_and_move_map_objects(map_t *, sfRenderWindow *);
map_t *display_map_objects(map_t *, sfRenderWindow *, sfClock *);
map_t *create_object_list(char, map_t *, int, int);
void display_how_to_use(void);
int play_jump_sound(sfClock *);
object_t move_sprite(object_t);
object_t move_player(object_t);
object_t display_sprites(object_t, sfRenderWindow *, sfClock *);
object_t create_object(char *, sfVector2f, sfIntRect);
object_t create_object_menu(char *, sfVector2f);
object_t create_object_env(char, int, int);
object_t *create_objects_static(sfVector2f, sfIntRect);
object_t *compute_gameplay(object_t *, int, sfRenderWindow *, sfClock *);
object_t display_sprites_menu(object_t, sfRenderWindow *);
object_t *render_menu(object_t *, sfRenderWindow *);
object_t *init_speed(object_t *);
object_t *check_collision(object_t *, map_t *, sfRenderWindow *, int *, sfText *);
sfRenderWindow *construct_window(void);
object_t create_player(char *);
object_t *create_menu_objects(void);
object_t *do_game_loop_infinite(object_t *, sfRenderWindow *);
int do_game_loop_finite(object_t *, map_t *, sfRenderWindow *, sfText *);
int analyse_events(sfEvent, sfRenderWindow *, sfClock *, int);
int analyse_events_menu(sfEvent, sfRenderWindow *);
object_t *compute_jump(int *, object_t *);
void destroy_objects(object_t *, map_t *);
void display_pause(sfRenderWindow *, sfClock *, sfTime, float);
char *select_texture(char);
char *inst_block(void);
char *inst_spike(void);
char *inst_floor(void);
char *inst_finish(void);
char *inst_ennemie(void);
object_t create_rect(object_t);
sfText *create_text(void);
sfText *update_text(sfText *, int, sfRenderWindow *);
char *my_put_char(int);
object_t *create_room(object_t *, sfVector2f, sfIntRect);
object_t *create_forest(object_t *, sfVector2f, sfIntRect);
object_t *create_city(object_t *, sfVector2f, sfIntRect);

#endif /* !PROTO_H_ */
