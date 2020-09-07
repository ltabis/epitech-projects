/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** parsing file
*/

#include "proto.h"

int parse_file(char *filepath, int key)
{
	FILE *stream = fopen(filepath, "r");
	char *line = NULL;
	size_t len = 0;
	struct stat buff;
	char *stat_file = my_strcat("./", filepath);
	int fd = open("crypt",
	O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);

	if (!stream || fd == 1)
		return (-1);
	if (stat(stat_file, &buff) == -1) {
		perror("ERROR");
		return (-1);
	} else if (buff.st_size == 0)
		return (0);
	while (getline(&line, &len, stream) != -1)
		apply_cesar_cipher(line, key, fd);
	free_utils(line, filepath, stat_file, stream);
	close(fd);
	return (0);
}

char *my_strcat(const char *str1, const char *str2)
{
	int len1 = 0;
	int len2 = 0;
	unsigned int i = 0;
	char *new_str = NULL;

	if (!str1 || !str2)
		return (NULL);
	len1 = strlen(str1);
	len2 = strlen(str2);
	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (NULL);
	for (unsigned int j = 0; str1[j] != 0; j++, i++)
		new_str[i] = str1[j];
	for (unsigned int j = 0; str2[j] != 0; j++, i++)
		new_str[i] = str2[j];
	new_str[len1 + len2] = 0;
	return (new_str);
}

void free_utils(char *line, char *filepath,
	char *stat_file, FILE *stream)
{
	free(line);
	free(filepath);
	free(stat_file);
	fclose(stream);
}
