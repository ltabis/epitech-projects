/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** decrypt
*/

#include "proto.h"

void apply_cesar_cipher(char *line, int key, int fd)
{
	for (unsigned int i = 0; line[i] && line[i] != '\n'; i++)
		if ((line[i] >= 'A' && line[i] <= 'Z') ||
		(line[i] >= 'a' && line[i] <= 'z'))
			change_line(&line[i], key);
	write(fd, line, strlen(line));
}

void change_line(char *line, int key)
{
	if (line[0] >= 'A' && line[0] <= 'Z')
		change_upper_case(line, key);
	else if (line[0] >= 'a' && line[0] <= 'z')
		change_lower_case(line, key);
}

void change_upper_case(char *line, int key)
{
	int alpha_len = key < 0 ? 26 : -26;

	for (int new_key = key, trig = 0, i = 0; trig != 1; i++) {
		if (line[0] + new_key >= 'A' &&
		line[0] + new_key <= 'Z' && i == 0) {
			trig = 1;
			line[0] += new_key;
		} else if (line[0] >= 'A' && line[0] <= 'Z' && i != 0)
			trig = 1;
		line[0] = trig != 1 ?
		(new_key + line[0]) + alpha_len : line[0];
	}
}

void change_lower_case(char *line, int key)
{
	int alpha_len = key < 0 ? 26 : -26;

	for (int new_key = key, trig = 0, i = 0; trig != 1; i++) {
		if (line[0] + new_key >= 'a' &&
		line[0] + new_key <= 'z' && i == 0) {
			trig = 1;
			line[0] += new_key;
		} else if (line[0] >= 'a' && line[0] <= 'z' && i != 0)
			trig = 1;
		line[0] = trig != 1 ?
		(new_key + line[0]) + alpha_len : line[0];
	}
}
