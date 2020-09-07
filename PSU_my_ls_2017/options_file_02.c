/*
** EPITECH PROJECT, 2017
** options_file_02.c
** File description:
** options file nbr 2
*/
#include <pwd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "include/my.h"
#include "include/proto.h"

void display_dash_l(char *stream, char *name)
{
	struct stat file;
	struct passwd *pws;
	struct group *pws2;
	int ver = 0;
	char *concat = malloc(512);

	concat = concat_params(stream, name);
	ver = lstat(concat, &file);
	pws = getpwuid(file.st_uid);
	if (ver == -1 || pws == NULL) {
		perror("error :");
		exit(84);
	}
	execute_ternaries(file);
	my_printf(" %d %s ", file.st_nlink, pws->pw_name);
	pws2 = getgrgid(file.st_gid);
	my_printf("%s %d", pws2->gr_name, file.st_size);
	display_time(file);
	my_printf("%s\n", name);
}

void execute_ternaries(struct stat file)
{
	my_printf((S_ISDIR(file.st_mode)) ? "d" : "-");
	my_printf((file.st_mode & S_IRUSR) ? "r" : "-");
	my_printf((file.st_mode & S_IWUSR) ? "w" : "-");
	my_printf((file.st_mode & S_IXUSR) ? "x" : "-");
	my_printf((file.st_mode & S_IRGRP) ? "r" : "-");
	my_printf((file.st_mode & S_IWGRP) ? "w" : "-");
	my_printf((file.st_mode & S_IXGRP) ? "x" : "-");
	my_printf((file.st_mode & S_IROTH) ? "r" : "-");
	my_printf((file.st_mode & S_IWOTH) ? "w" : "-");
	my_printf((file.st_mode & S_ISVTX) ? "T" :
		(file.st_mode & S_IXOTH) ? "x" : "-");
}

void display_time(struct stat file)
{
	char *time;
	const time_t timep;

	time = ctime(&file.st_mtime);
	if (!time)
		exit(84);
	for (int i = 3, st = 0; st != 2; i++) {
		if (time[i] == ':')
			st++;
		if (st != 2)
			my_putchar(time[i]);
	}
	my_putchar(' ');
}

unsigned int verify_dash_l(unsigned int i, char **av, stock_t *stk)
{
	struct stat file;
	char *concat = concat_params("./", av[i]);

	lstat(concat, &file);
	if (av[i][0] == '-')
		i++;
	if (av[i][0] != '-' && S_ISDIR(file.st_mode)) {
		my_printf("%s:\n", av[i]);
		disp_files_advanced(av[i], stk);
		i++;
	}
	else if (av[i][0] != '-' && S_ISREG(file.st_mode)) {
		if (stk->options[0] == 48)
			my_printf("%s ", av[i]);
		else
			display_dash_l(concat, av[i]);
		i++;
	}
	return (i);
}
