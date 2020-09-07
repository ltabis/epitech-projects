/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for the BSQ's bootstrap
*/
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"
#include "include/proto.h"

int main(void)
{
	int fd = fs_open_file("Maps/map1.txt");
	char buffer[30];

	if (fd == -1)
		my_putstr("FAILURE\n");
	else
		my_putstr("SUCCES\n");
	fs_understand_return_of_read(fd, buffer, sizeof(buffer));
	return (0);
}

int fs_open_file(char const *filepath)
{
	int fileD = 0;

	fileD = open(filepath, O_RDONLY);
	return (fileD);
}

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
	int result = read(fd, buffer, size);

	if (result == -1)
		my_putstr("read failed\n");
	else if (result == 0)
		my_putstr("read has nothing more to read\n");
	else if (result < size)
		my_putstr("read didn’t complete the entire buffer\n");
	else if (result == size)
		my_putstr("read completed the entire buffer\n");
}
