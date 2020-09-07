/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for the my_ls's bootstrap
*/
#include "include/my.h"
#include "include/proto.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		exit(84);
	display_file(argv[1]);
	return (0);
}

void display_file(char *av)
{
	struct stat file;
	int ver = 0;
	
	ver = stat(av, &file);
	if (ver == -1)
		exit(84);
	my_printf("Name : %s\n", av);
	if (S_ISREG(file.st_mode))
		printf("Type : f\n");
        else if (S_ISDIR(file.st_mode))
		printf("Type : d\n");
	if (S_ISCHR(file.st_mode))
		printf("Type : c\n");
        my_printf("inode : %u\nHard link : %d\n", file.st_ino, file.st_nlink);
	my_printf("size : %d\nAllocated space : %d\n", file.st_size);
	my_printf("Minor : %d\nMajor : %d\n");
	my_printf("UID : %d\nGID : %d\n", file.st_uid, file.st_gid);
}
