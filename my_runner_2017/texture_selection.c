/*
** EPITECH PROJECT, 2018
** texture_selection.c
** File description:
** file that will take care of the texture selection
*/
#include <stdlib.h>
#include "include/proto.h"

char *inst_block(void)
{
	int i = rand() % 3;
	char *block_sprites[] = {BLOCK1, BLOCK2, BLOCK3};

	return (block_sprites[i]);
}

char *inst_spike(void)
{
	int i = rand() % 3;
	char *block_sprites[] = {SPIKE1, SPIKE2, SPIKE3};

	return (block_sprites[i]);
}

char *inst_floor(void)
{
	int i = rand() % 3;
	char *block_sprites[] = {FLOOR1, FLOOR2, FLOOR3};

	return (block_sprites[i]);
}

char *inst_finish(void)
{
	return (FINISH);
}

char *inst_ennemie(void)
{
	int i = rand() % 3;
	char *block_sprites[] = {ENN1, ENN2, ENN3};

	return (block_sprites[i]);
}
