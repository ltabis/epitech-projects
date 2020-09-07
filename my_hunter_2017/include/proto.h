/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** testing my_hunter with structures
*/
#include <SFML/Graphics.h>
#include "ressources.h"
#ifndef PROTO_TEST_H_
#define PROTO_TEST_H_

int my_put_nbr(int);
int my_putchar(char );
int my_putstr(char const *);
void display_how_to_use(void);
void game_over(ressources_t *);
void game_loop(ressources_t *);
void draw_sprites(ressources_t *);
void move_rect(sfIntRect *, int, int);
ressources_t *load_sprites(ressources_t *);
ressources_t *load_textures(ressources_t *);
ressources_t *initiate_clock(ressources_t *);
ressources_t *malloc_integers(ressources_t *);
ressources_t *construct_window(ressources_t *);
ressources_t *initiate_structs(ressources_t *);
ressources_t *compute_gameplay(ressources_t *);
ressources_t *malloc_ressources(ressources_t *);
ressources_t *load_texture_alt1(ressources_t *);
ressources_t *load_texture_alt2(ressources_t *);
ressources_t *initiate_ressources(ressources_t *);
ressources_t *destroy_ressources(ressources_t *);
ressources_t *move_sprite_to_beginning(ressources_t *);
ressources_t * analyse_events(sfEvent, ressources_t *);

#endif /* !PROTO_TEST_H_ */
