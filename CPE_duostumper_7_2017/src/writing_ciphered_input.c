/*
** EPITECH PROJECT, 2018
** writing_ciphered_input.c
** File description:
** wrinting in a file or stdout the user input ciphered
*/

#include "proto.h"

int write_ciphered_string_into_file(char *string, int key)
{
	int fd = open("crypt", O_WRONLY | O_CREAT,
	S_IRUSR | S_IRGRP | S_IROTH);

	if (fd == -1) {
		perror("file descriptor");
		return (-1);
	}
	apply_cesar_cipher(string, key, fd);
	free(string);
	close(fd);
	return (0);
}
