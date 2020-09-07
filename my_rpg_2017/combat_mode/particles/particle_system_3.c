/*
** EPITECH PROJECT, 2018
** particle_system_3.c
** File description:
** displaying particule system on a certain point
*/

#include "../../include/particles.h"
#include "../../include/combat.h"

void draw_circle(particle_act_t *sys, particle_t opt)
{
	sfVector2i ctr = {opt.pos.x / 2, opt.pos.y / 2};
	int x = 0;
	int y = opt.lenght / 10;
	int m = 5 - 4 * opt.lenght / 10;

	for (; x <= y; x++, m = m + 8 * x + 4) {
		my_put_pixel(sys->buffer, x + ctr.x, y + ctr.y, opt.color);
		my_put_pixel(sys->buffer, y + ctr.x, x + ctr.y, opt.color);
		my_put_pixel(sys->buffer, -x + ctr.x, y + ctr.y, opt.color);
		my_put_pixel(sys->buffer, -y + ctr.x, x + ctr.y, opt.color);
		my_put_pixel(sys->buffer, x + ctr.x, -y + ctr.y, opt.color);
		my_put_pixel(sys->buffer, y + ctr.x, -x + ctr.y, opt.color);
		my_put_pixel(sys->buffer, -x + ctr.x, -y + ctr.y, opt.color);
		my_put_pixel(sys->buffer, -y + ctr.x, -x + ctr.y, opt.color);
		if (m > 0) {
			y--;
			m = m - 8 * y;
		}
	}
}

void draw_square(particle_act_t *system, particle_t opt)
{
	unsigned int rand_x = rand() % opt.lenght + opt.lenght / 2;
	unsigned int rand_y = rand() % opt.lenght + opt.lenght / 2;

	clear_buffer(system->buffer, opt.lenght, opt.lenght);
	for (unsigned int y = rand_y, i = 0;
	i < opt.lenght; i++, y++)
		for (unsigned int x = rand_x, j = 0;
		j < opt.lenght; j++, x++)
			my_put_pixel(system->buffer, x, y, opt.color);
}

void draw_points(particle_act_t *system, particle_t opt)
{
	for (unsigned int i = 0; i < opt.nbr_particules; i++) {
		my_put_pixel(system->buffer, rand() % opt.lenght,
		rand() % opt.lenght, opt.color);
	}
}