/*
** EPITECH PROJECT, 2017
** particles.h
** File description:
** prototypes for a particular program
*/

#ifndef PARTICLES_H_
#define PARTICLES_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "combat.h"

void compute_background(sfRenderWindow *,
	background_t *, sfClock *, player_stat_t *);
background_t *init_background(sfRenderWindow *);
particle_act_t *create_particle_system(particle_act_t *, particle_t, int);
int generate_particles(particle_t, char, int, sfRenderWindow *);
void clear_buffer(framebuffer_t *, unsigned int, unsigned int);
framebuffer_t *framebuffer_create(unsigned int, unsigned int);
void my_put_pixel(framebuffer_t *, unsigned int, unsigned int, sfColor);
void set_particules_position(sfSprite *, particle_t);
void draw_circle(particle_act_t *, particle_t);
void draw_square(particle_act_t *, particle_t);
void draw_points(particle_act_t *, particle_t);
particle_act_t *create_new_particle_system(particle_act_t *, particle_t, int);
void search_or_create_particul_system(particle_act_t *,
	particle_t, int, sfRenderWindow *);

#endif /* !PARTICLES_H_ */
