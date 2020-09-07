/*
** EPITECH PROJECT, 2018
** count_words.c
** File description:
** program that count the occurence of words in a strng
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/proto.h"

int main(int ac, char **av)
{
	int error_handling = 0;

	if (ac == 1) {
		write(1, "\n", 1);
		return (0);
	} else if (ac != 2)
		return (84);
	error_handling = scan_line(av[1]);
	if (error_handling == 84)
		return (84);
	return (0);
}

int scan_line(char *line)
{
	int nbr_words = number_of_words(line);
	char **arr_words = malloc(sizeof(char *) * nbr_words);
	int *matchs = malloc(sizeof(int) * nbr_words);

	for (int i = 0; i < nbr_words; i++)
		matchs[i] = 1;
	if (!arr_words)
		return (84);
	for (int i = 0; i < nbr_words; i++) {
		arr_words[i] = add_word_to_array(line);
		if (arr_words[i] == NULL)
			matchs[i]++;
	}
	for (int i = 0; i < nbr_words; i++) {
		if (arr_words[i] != NULL) {
			printf("%s:", arr_words[i]);
			printf(" %d\n", matchs[i]);
		}
	}
	return (0);
}

int number_of_words(char *av)
{
	int count = 1;

	for (int i = 0; av[i] != '\0'; i++)
		if (av[i] == ' ')
			count++;
	return (count);
}

char *add_word_to_array(char *line)
{
	static int decal = 0;
	int i = decal;
	int j = 0;
	int size = 0;
	char *word;

	if (line[decal] == ' ') {
		decal++;
		i++;
	}
	for (; line[decal] != '\0' && line[decal] != ' '; decal++);
	size = (decal - i) + 1;
	word = malloc(sizeof(char) * size);
	for (; i < decal; i++, j++)
		word[j] = line[i];
	word[j] = '\0';
	j = check_occurences(word, line, size - 1, decal);
	if (j == 0)
		return (word);
	return (NULL);
}

int check_occurences(char *word, char *line, int len_word, int decal)
{
	int match = 0;

	for (; line[decal] != '\0' && match < len_word; decal++) {
		if (line[decal] == word[match])
			match++;
		else if (line[decal] == ' ')
			match = 0;
	}
	if (len_word == match)
		return (1);
	return (0);
}
