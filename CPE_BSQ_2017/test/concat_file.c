/*
** EPITECH PROJECT, 2017
** concat_file.c
** File description:
** file that concatenate a file into a matrix
*/
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../include/my.h"
#include "../include/proto.h"

bsq_t *load_2d_arr_from_file(char *filepath, bsq_t *sq)
{
	char buff[1];
	int dir = open(filepath, O_RDONLY);
	int i = 0;

	read(dir, buff, 1);
	while (buff[0] != '\n')
		read(dir, buff, 1);
	read(dir, buff, 1);
	sq = add_custom_malloc_file_row(sq);
	for (i = 0; i < sq->y; i++) {
		sq = add_custom_malloc_file_col(sq, i);
		for (int j = 0; j < sq->x; j++) {
			sq->x_file[i][j] = buff[0];
			read(dir, buff, 1);
		}
		read(dir, buff, 1);
	}
	close(dir);
	return (sq);
}

void verify_file_stat(char *av)
{
	struct stat file;
	char *concat = concat_params("./", av);

	stat(concat, &file);
	if (!S_ISREG(file.st_mode))
		exit(84);
	verify_file_content(concat);
}

void verify_file_content(char *filepath)
{
	char buff[1];
	int dir = open(filepath, O_RDONLY);
	int result = read(dir, buff, 1);

	while (buff[0] != '\n') {
		if (buff[0] < '0' || buff[0] > '9')
			exit(84);
		result = read(dir, buff, 1);
	}
	while (result != 0) {
		if (buff[0] != '.' && buff[0] != 'o' && buff[0] != '\n')
			exit(84);
		result = read(dir, buff, 1);
	}
	free(filepath);
	close(dir);
}

bsq_t *find_widht_and_height(bsq_t *sq, char *filepath)
{
	char buff[1];
	int dir = open(filepath, O_RDONLY);
	int result = read(dir, buff, 1);
	int nb = 0;

	while (buff[0] != '\n') {
		nb = nb * 10 + (buff[0] - 48);
		result = read(dir, buff, 1);
	}
	result = read(dir, buff, 1);
	for (; buff[0] != '\n'; sq->x++, result = read(dir, buff, 1));
	while (result != 0) {
		if (buff[0] == '\n')
			sq->y++;
		result = read(dir, buff, 1);
	}
	if (nb != sq->y)
		exit(84);
	close(dir);
	return (sq);
}
