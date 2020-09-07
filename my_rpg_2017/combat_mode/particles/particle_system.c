/*
** EPITECH PROJECT, 2018
** particle_system.c
** File description:
** displaying particule system on a certain point
*/

#include "../../include/particles.h"
#include "../../include/combat.h"

int generate_particles(particle_t opt, char mod,
	int id, sfRenderWindow *window)
{
	static particle_act_t *system = NULL;

	system = !system ? create_particle_system(system, opt, id) : system;
	if (!system) {
		write(2, "global particle system could not be loaded\n", 43);
		return (-1);
	}
	if (mod == 'a')
		search_or_create_particul_system(system, opt, id, window);
	return (0);
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

	if (!framebuffer)
		return (NULL);
	framebuffer->width = width;
	framebuffer->height = height;
	framebuffer->pixels = malloc(sizeof(sfUint8) * 4 * width * height);
	if (!framebuffer->pixels)
		return (NULL);
	for (unsigned int i = 0; i < width * height * 4; i += 4) {
		framebuffer->pixels[i] = 0;
		framebuffer->pixels[i + 1] = 0;
		framebuffer->pixels[i + 2] = 0;
		framebuffer->pixels[i + 3] = 0;
	}
	return (framebuffer);
}

void my_put_pixel(framebuffer_t *buffer, unsigned int x,
	unsigned int y, sfColor color)
{
	if ((y * buffer->width + x) * 4 < buffer->width * buffer->height * 4) {
		buffer->pixels[(y * buffer->width + x) * 4] = color.r;
		buffer->pixels[(y * buffer->width + x) * 4 + 1] = color.g;
		buffer->pixels[(y * buffer->width + x) * 4 + 2] = color.b;
		buffer->pixels[(y * buffer->width + x) * 4 + 3] = color.a;
	}
}

void clear_buffer(framebuffer_t *buffer, unsigned int x, unsigned int y)
{
	for (unsigned int i = 0; i < x * y * 4; i++) {
		buffer->pixels[i] = 0;
		buffer->pixels[i + 1] = 0;
		buffer->pixels[i + 2] = 0;
		buffer->pixels[i + 3] = 0;
	}
}

void set_particules_position(sfSprite *sprite, particle_t opt)
{
	sfVector2f vect_2d = {0, 0};
	float angle_x = 35 * (PI / 180);
	float angle_y = 25 * (PI / 180);

	sfSprite_setOrigin(sprite,
	(sfVector2f){opt.lenght / 2, opt.lenght / 2});
	vect_2d.x = cos(angle_x) * opt.pos.x - cos(angle_x) * opt.pos.y;
	vect_2d.y = sin(angle_y) * opt.pos.y + sin(angle_y) * opt.pos.x;
	sfSprite_setPosition(sprite, (sfVector2f)
	{vect_2d.x, vect_2d.y});
}