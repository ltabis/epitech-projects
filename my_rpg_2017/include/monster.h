/*
** EPITECH PROJECT, 2017
** monster.h
** File description:
** prototypes for a particular program
*/

#ifndef MONSTER_H_
#define MONSTER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>

typedef struct monster_s {
	float current_hp;
	float current_sp;
	float current_st;
	float max_hp;
	float max_sp;
	float max_st;
	int att;
	int def;
	int spd;
	sfSprite *spr;
	sfTexture *txt;
	struct monster_s *next;
} monster_t;

monster_t *compare_stats(char *, char *, monster_t *);
void change_current_hp(char *, monster_t *);
void change_current_sp(char *, monster_t *);
void change_current_st(char *, monster_t *);
void change_max_hp(char *, monster_t *);
void change_max_sp(char *, monster_t *);
void change_max_st(char *, monster_t *);
void change_att(char *, monster_t *);
void change_def(char *, monster_t *);
void change_spd(char *, monster_t *);
monster_t *create_new_monster(monster_t *);
sfTexture *clean_texture(char *);
void fill_stat(monster_t *, char *);
char *clear_and_copy(char *);
char *separate_stats(char *);
monster_t *parse_monsters(void);
monster_t *fill_monster_stats(char *, monster_t *);
int check_brace(char *, int);
monster_t *add_stats_to_monster(char *, FILE *, monster_t *);

#endif /* !MONSTER_H_ */