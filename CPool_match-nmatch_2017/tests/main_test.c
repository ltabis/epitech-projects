/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for testing
*/
#include "../include/my.h" 

void main(void)
{
	char string[] = "find my string";
	char find[] = "*******f****d***my str**g";

	match_test(string, find);
}
