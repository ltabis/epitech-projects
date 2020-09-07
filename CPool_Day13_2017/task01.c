/*
** EPITECH PROJECT, 2017
** task01.c
** File description:
** task01 day13
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "include/mylist.h"

void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{

}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *list;
	
	list->width = 800;
	list->height = 600;
}

int main(void)
{
	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow* window;
	sfText* text;
	sfFont* font;
	sfEvent event;
        
	window = sfRenderWindow_create(mode, "trou de balle", sfResize | sfClose, NULL);
	if (!window)
		return (0);
        font = sfFont_createFromFile("arial_narrow_7.ttf");
	if (!font)
		return (0);
	text = sfText_create();
	sfText_setString(text, "HAY YU BRU");
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 100);
        while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event))
		{
		        if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
	        sfRenderWindow_drawText(window, text, NULL);
		sfRenderWindow_display(window);
	}
	sfText_destroy(text);
	sfFont_destroy(font);
	sfRenderWindow_destroy(window);
}
