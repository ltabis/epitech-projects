/*
** EPITECH PROJECT, 2018
** load_tetriminos.c
** File description:
** loading tetriminos in structures
*/

#include "tetris.h"
#include "args.h"
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>

char **load_tetriminos(char *filepath, tetrimino_t *tetriminos)
{
	char **piece = malloc(sizeof(char *) * (tetriminos->info.size.y + 1));
	FILE *stream  = fopen(filepath, "r");
	unsigned int i = 0;
	char *line = NULL;
	size_t len = 0;

	if (!piece || !stream)
		return (NULL);
	for (int j = 0, rd = 0; (rd = getline(&line, &len, stream)) != -1; j++)
		if (j != 0) {
			piece[i] = alloc_tetriminos_line(line, rd);
			i++;
		}
	if ((int)i == tetriminos->info.size.y)
		piece[i] = NULL;
	else
		tetriminos->info.state = -1;
	free(line);
	fclose(stream);
	return (piece);
}

tetrimino_t *create_tetriminos(tetrimino_t *tetriminos, char **names)
{
	char *filepath = NULL;
	char *file = "tetriminos/";

	for (unsigned int i = 0; names[i]; i++) {
		tetriminos[i].name = my_strcpy(tetriminos[i].name, names[i]);
		if (tetriminos[i].info.state != -1) {
			filepath = my_strcat(file, names[i]);
			tetriminos[i].piece = load_tetriminos(
			filepath, &tetriminos[i]);
			check_tetriminos_lenght_and_width(&tetriminos[i]);
			free(filepath);
		} else
			tetriminos[i].piece = NULL;
		free(names[i]);
	}
	free(names);
	return (tetriminos);
}