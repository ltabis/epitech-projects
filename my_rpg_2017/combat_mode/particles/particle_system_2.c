/*
** EPITECH PROJECT, 2018
** particle_system_2.c
** File description:
** displaying particule system on a certain point
*/

#include "../../include/particles.h"
#include "../../include/combat.h"

particle_act_t *create_particle_system(particle_act_t *system,
	particle_t opt, int id)
{
	system = malloc(sizeof(particle_act_t));
	if (!system)
		return (NULL);
	system->buffer =
	framebuffer_create(opt.lenght, opt.lenght);
	if (!system->buffer || !system->buffer->pixels)
		return (NULL);
	system->opt = (particle_t){opt.shape, opt.color, opt.pos,
	opt.lenght, opt.nbr_particules, opt.speed};
	system->id = id;
	system->spr = sfSprite_create();
	system->txt = sfTexture_create(opt.lenght, opt.lenght);
	sfSprite_setTexture(system->spr, system->txt, sfTrue);
	system->next = NULL;
	return (!system->spr || !system->txt ? NULL : system);
}

void search_or_create_particul_system(particle_act_t *sys, particle_t opt,
	int id, sfRenderWindow *window)
{
	char trigger = 0;
	void (*selectParicule[3])(particle_act_t *, particle_t) =
	{draw_points, draw_circle, draw_square};

	while (trigger == 0) {
		if (id == sys->id) {
			trigger = 1;
			(*selectParicule[sys->opt.shape])(sys, opt);
			sfTexture_updateFromPixels(sys->txt,
			sys->buffer->pixels,
			sys->buffer->width, sys->buffer->height, 0, 0);
			sfSprite_setPosition(sys->spr,
			(sfVector2f){opt.pos.x, opt.pos.y});
			sfRenderWindow_drawSprite(window, sys->spr, NULL);
		}
		sys = sys->next && trigger != 1 ? sys->next : sys;
		trigger = !sys->next && trigger != 1 ? 2 : trigger;
	}
	sys = trigger == 2 ? create_new_particle_system(sys, opt, id) : sys;
}

particle_act_t *create_new_particle_system(particle_act_t *system,
	particle_t opt, int id)
{
	particle_act_t *new_system = malloc(sizeof(particle_act_t));

	if (!new_system)
		return (NULL);
	new_system->buffer = framebuffer_create(opt.lenght, opt.lenght);
	if (!new_system->buffer || !new_system->buffer->pixels)
		return (NULL);
	new_system->opt = (particle_t){opt.shape, opt.color, opt.pos,
	opt.lenght, opt.nbr_particules, opt.speed};
	new_system->id = id;
	new_system->spr = sfSprite_create();
	new_system->txt = sfTexture_create(opt.lenght, opt.lenght);
	sfSprite_setTexture(new_system->spr, new_system->txt, sfTrue);
	new_system->next = NULL;
	system->next = new_system;
	system = new_system;
	return (!new_system->txt || !new_system->spr ? NULL : system);
}