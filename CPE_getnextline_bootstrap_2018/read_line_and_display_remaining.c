/*
** EPITECH PROJECT, 2018
** read_line_and_display_remaining.c
** File description:
** function that return the first line and display the remaing bytes
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *read_line_and_display_remaining(int fd, int n)
{
	char *arr;
	char buffer[n];
	int read_val = read(fd, buffer, sizeof(buffer));
	int size = 0;
	int i = 0;

	for (; buffer[i] != '\n' && i != n; i++);
	arr = malloc(sizeof(char) * i + 1);
	for (i = 0; buffer[i] != '\n' && i != n; i++)
		arr[i] = buffer[i];
	arr[i] = '\0';
	for (; buffer[i] != '\0'; i++)
		printf("%c", buffer[i]);
	putchar('\n');
	close(fd);
	return (arr);
}
