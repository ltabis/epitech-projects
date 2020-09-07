/*
** EPITECH PROJECT, 2018
** read_next_ten_bytes.c
** File description:
** function that returns the 10 bytes of a file or NULL
*/
#include <stdlib.h>
#include <unistd.h>

char *read_next_ten_bytes(int fd)
{
	char *arr = malloc(sizeof(char) * 11);
	char buffer[1];
	int read_val = read(fd, buffer, sizeof(buffer));

	if (!arr)
		return (NULL);
	for (int i = 0; i < 10; i++) {
		if (read_val == 0)
			return (NULL);
		arr[i] = buffer[0];
		read_val = read(fd, buffer, sizeof(buffer));
	}
	arr[10] = '\0';
	return (arr);
}
