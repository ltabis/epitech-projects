/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** map header
*/

#ifndef  MAP_H
#define MAP_H

#include "combat.h"

#define INV_SIZE 24

typedef struct player_s {
	int sens;
	int decal_x;
	int decal_y;
	int case_x;
	int case_y;
	int tempo_x;
	int tempo_y;
	int *inventory;
	sfSprite *sprite;
	sfTexture *texture;
	sfIntRect rect;
	sfVector2f position;
} player_t;

typedef struct map_s {
	char status;
	char middle;
	int option;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f position;
} map_t;

typedef struct tab_map_s {
	int size_x;
	int size_y;
	int pos_x;
	int pos_y;
	int decal_x;
	int decal_y;
	char first;
	char ***tab;
} tab_map_t;

typedef struct move_s {
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f position;
	sfTexture *texture;
	sfClock *clock;
	int move;
} move_t;

char *get_next(char *);
char *get_next_line(int);
char *until_space(char const *);
char ***fill_tab(char ***, int, int, int);
char ***init_tab(int *, int *, char *);
int get_next_nd(char *);
int get_option(char *);
int get_pos_x(tab_map_t *, int, int);
int get_pos_y(tab_map_t *, int, int);
int is_first(char *);
void disp_tab(char ***);
void init_sprite(map_t ***, int, int, tab_map_t *);
void init_starter(tab_map_t *, int, int);
map_t ***init_map(tab_map_t *);
player_t *init_player(tab_map_t *, int);
tab_map_t *init_tab_map(char *);

#endif
