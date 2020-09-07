/*
** EPITECH PROJECT, 2017
** structs.h
** File description:
** file that contains main structures
*/
#include <SFML/Graphics.h>
#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct object_s {
	char type;
	sfSprite *spr;
	sfTexture *txt;
	sfVector2f vect;
	sfIntRect rect;
	int speed;
	int initialisation;
	int end;
	float lim;
	float jump;
} object_t;

typedef struct map_s {
	object_t obj;
	struct map_s *next;
	struct map_s *prev;
} map_t;

#endif /* !STRUCTS_H_ */
