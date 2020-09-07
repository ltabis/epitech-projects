/*
** EPITECH PROJECT, 2018
** read_next_n_bytes.c
** File description:
** function that returns n numbers of chars
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *read_next_n_bytes(int fd, int n)
{
	char *arr = malloc(sizeof(char) * n + 1);
	char buffer[1];
	int read_val = read(fd, buffer, sizeof(buffer));

	if (!arr)
		return (NULL);
	for (int i = 0; read_val != 0 && i < n; i++) {
		arr[i] = buffer[0];
		read_val = read(fd, buffer, sizeof(buffer));
	}
	arr[n] = '\0';
	close(fd);
	return (arr);
}
