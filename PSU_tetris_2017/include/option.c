/*
** EPITECH PROJECT, 2018
** option.c
** File description:
** options
*/
#include <getopt.h>

const struct option op_tab[] =
	{
		{"map-size=", 1, NULL, 'n'},
		{"key-left=", 1, NULL, 'l'},
		{"key-right=", 1, NULL, 'r'},
		{"key-turn=", 1, NULL, 't'},
		{"key-drop=", 1, NULL, 'd'},
		{"key-quit=", 1, NULL, 'q'},
		{"key-pause=", 1, NULL, 'p'},
		{"level=", 1, NULL, 'L'},
		{"debug", 0, NULL, 'D'},
		{"without-next", 0, NULL, 'w'},
		{"help", 0, NULL, 1},
		{0, 0, 0, 0}
	};