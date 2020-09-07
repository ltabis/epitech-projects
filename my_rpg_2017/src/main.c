/*
** EPITECH PROJECT, 2018
** main_test.c
** File description:
** main de test
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "proto.h"
#include "menu.h"
#include "my.h"
#include "sound.h"

void interpret_user_choice(int game, sfRenderWindow *w, sfMusic *music)
{
	if (game == 0) {
		sfMusic_stop(music);
		launch_2d_map("picture/spaceship_tile.png",
		"map_loader/map/ship", w);
		sfMusic_play(music);
	}
	if (game == 1)
		launch_lore(w);
	if (game == 2)
		launch_tutorial(w);
}

int main(UNUSED int ac, UNUSED char **av, char **env)
{
	sfRenderWindow *window = create_window();
	sfSprite **buttons = NULL;
	sfSprite *corewar = NULL;
	background_t *back = NULL;
	sfClock *clock = sfClock_create();
	sfMusic *menu_msc = create_menu_music();

	if (check_env_variable(env) == -1 || !clock)
		return (84);
	back = init_background(window);
	buttons = create_menu_buttons();
	if (!back || !buttons || !(corewar = create_corewar_sprite()))
		return (84);
	for (int game = -1; sfRenderWindow_isOpen(window) && game != 3;) {
		compute_background_menu(window, back, clock, corewar);
		game = main_menu(window, buttons, corewar);
		interpret_user_choice(game, window, menu_msc);
	}
	sfMusic_destroy(menu_msc);
	return (0);
}

void display_background_menu(background_t *back, int color)
{
	for (unsigned int i = 0, demi = 0;
	i < back->buffer->width * back->buffer->height * 4; i += 4) {
		if (demi % 2 == 0 && back->buffer->pixels[i] == 255) {
			back->buffer->pixels[i + 3] = 255 - color;
			demi++;
		} else if (demi % 2 != 0 && back->buffer->pixels[i] == 255) {
			back->buffer->pixels[i + 3] = color;
			demi++;
		}
	}
	sfTexture_updateFromPixels(back->txt, back->buffer->pixels,
	back->buffer->width, back->buffer->height, 0, 0);
}

void compute_background_menu(sfRenderWindow *window,
	background_t *back, sfClock *clock, sfSprite *corewar)
{
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 100000.0;
	static int color = 0;
	static char mul = '+';

	sfRenderWindow_clear(window, sfBlack);
	if (seconds > 0.01) {
		color += color != 255 && mul == '+' ? 5 : 0;
		color -= color != 0 && mul == '-' ? 5 : 0;
		mul = color == 255 && mul == '+' ? '-' : mul;
		mul = color == 0 && mul == '-' ? '+' : mul;
		display_background_menu(back, color);
		sfSprite_rotate(corewar, 1.5);
		sfClock_restart(clock);
	}
	sfRenderWindow_drawSprite(window, back->spr, NULL);
}

int check_all_buttons(int ret, sfSprite **buttons,
	sfRenderWindow *w, sfEvent event)
{
	sfRenderWindow_clear(w, sfBlack);
	for (unsigned int j = 0; j < 3 && ret == -1; j++)
		ret = check_buttons_actions_tuto(
		buttons[j], w, j, event);
	return (ret);
}
