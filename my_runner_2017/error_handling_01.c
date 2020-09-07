/*
** EPITECH PROJECT, 2017
** error_handling_01.c
** File description:
** file for error handling
*/
#include <fcntl.h>
#include <unistd.h>
#include "include/proto.h"

int verify_file_stat(char *filepath, int error)
{
	int fd = open(filepath, O_RDONLY);

	if (fd < 0) {
		close(fd);
		write(2, "The map given doesn't exists\n", 29);
		return (84);
	}
	error = read_file_content(fd);
	if (error == 84)
		return (84);
	return (0);
}

int read_file_content(int fd)
{
	char buff[1];
	int rd = read(fd, buff, 1);
	int error = 0;

	while (rd != 0) {
		if (rd < 0)
			return(84);
		error = check_file_content_level_1(buff);
		if (error == 84)
			return (84);
		rd = read(fd, buff, 1);
	}
	close(fd);
	return (0);
}

int check_file_content_level_1(char *buff)
{
	if (buff[0] == ' ' || buff[0] == 'T' || buff[0] == '|' ||
	buff[0] == '#' || buff[0] == 'E')
		return (0);
	else if (buff[0] == '^' || buff[0] == '=' || buff[0] == '\n')
		return (0);
	write(2, "The map loaded is invalid, please see ", 38);
	write(2, "the legend map to create your own\n", 34);
	return (84);
}
