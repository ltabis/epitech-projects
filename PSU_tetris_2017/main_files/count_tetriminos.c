/*
** EPITECH PROJECT, 2018
** count tetriminos
** File description:
** count the nb of file .tetrimino and sort
*/

#include "tetris.h"
#include "base.h"

void do_sorting(char **names)
{
	for (int i = 0; names[i + 1]; i++) {
		if (my_strcmp(names[i], names[i + 1]) > 0)
			my_swap_str(&names[i], &names[i + 1]);
	}
}

void sorting_names(char **names)
{
	int sort = 0;

	while (sort == 0) {
		do_sorting(names);
		sort = check_sort(names);
	}
}

char **do_sort_names(char **names, char *file_name, int *count)
{
	char *tmp = NULL;
	char *tmp2 = NULL;

	tmp = my_strcpy(tmp, file_name);
	tmp2 = tmp;
	if (tmp == NULL)
		return (NULL);
	while (my_strcmp(tmp, ".tetrimino") != 0 && tmp[0])
		tmp += 1;
	if (my_strlen(tmp) == 10 && tmp != NULL) {
		names[*count] = my_strcpy(names[*count], file_name);
		if (names[*count] == NULL)
			return (NULL);
		*count += 1;
	}
	free(tmp2);
	return (names);
}

char **sort_names(int nb_files)
{
	char **names = malloc(sizeof(char *) * (nb_files + 1));
	int count = 0;
	struct dirent *file = NULL;
	DIR *stream = NULL;

	if (names == NULL)
		exit(84);
	names[nb_files] = 0;
	stream = opendir("tetriminos");
	if (!stream || (file = readdir(stream)) == NULL)
		exit(84);
	while (file != NULL) {
		do_read_sort(file, &count, names);
		file = readdir(stream);
	}
	if (names[0] == NULL)
		exit(84);
	sorting_names(names);
	closedir(stream);
	return (names);
}

int count_file(void)
{
	int count = 0;
	DIR *stream = NULL;
	struct dirent *file = NULL;

	stream = opendir("tetriminos");
	if (stream == NULL)
		exit(84);
	if ((file = readdir(stream)) == NULL)
		exit(84);
	while (stream != NULL && file != NULL) {
		if (file->d_type == DT_REG)
			do_count(file, &count);
		file = readdir(stream);
	}
	if (stream)
		closedir(stream);
	return (count);
}
