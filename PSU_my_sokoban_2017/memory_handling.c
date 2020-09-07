/*
** EPITECH PROJECT, 2017
** memory_handling.c
** File description:
** memory verifications
*/
#include <stdlib.h>
#include "include/my.h"
#include "include/proto.h"

void display_how_to_use(void)
{
	my_putstr("USAGE\n");
	my_putstr("      ./my sokoban map\n") ;
	my_putstr("DESCRIPTION\n");
	my_putstr("           map  file representing the warehouse map,");
	my_putstr(" containing `#' for walls,\n");
	my_putstr("          `P' for the player, `X' for boxes and");
	my_putstr("`O' for storage locations.\n");
	exit(0);
}
