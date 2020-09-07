/*
** EPITECH PROJECT, 2018
** display_maze.c
** File description:
** displaying the maze
*/

#include <string.h>
#include <unistd.h>

void display_maze(char *maze)
{
	write(1, maze, strlen(maze));
}
