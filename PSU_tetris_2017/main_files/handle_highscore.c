/*
** EPITECH PROJECT, 2018
** handle highscore
** File description:
** handle highscore
*/

#include "tetris.h"

int is_digit(char c)
{
	if (c < '0' && c > '9')
		return (1);
	return (0);
}

score_t *read_score_file(void)
{
	FILE *s;
	char *b = NULL;
	size_t len = 0;
	int j = 0;
	ssize_t nread;
	score_t *scoreboard = malloc(sizeof(score_t) * 6);

	s = fopen("score/score_tab.score", "r");
	if (!scoreboard || s == NULL)
		exit(84);
	for (int i = 0; i < 5 && ((nread = getline(&b, &len, s)) != -1); i++) {
		scoreboard[i] = init_new_score(b);
		for (; b[j] && b[j] != ' ' && b[j + 1] != '='; j++);
		scoreboard[i].name = my_strncpy(scoreboard[i].name, b, j);
		for (; b[j] && (is_digit(b[j]) == 1); j++);
		b += j;
		scoreboard[i].score = my_getnbr(b);
	}
	fclose(s);
	return (scoreboard);
}

score_t *compare_scoreboard(score_t *scoreboard, score_t s)
{
	int i = 0;

	for (; scoreboard[i].name != NULL && i < 5; i++);
	if (i < 5) {
		scoreboard[i] = init_full_score(s.name,
		s.scoreboard, s.score);
	}
	else {
		if (scoreboard[i - 1].score < s.score)
			my_swap_score(&scoreboard[i - 1], &s);
	}
	scoreboard = sort_scoreboard(scoreboard);
	return (scoreboard);
}

void write_in_file(score_t *s, score_t sc)
{
	int fd = 0;

	(void)sc;
	if ((fd = open("score/score_tab.score", O_WRONLY)) == -1)
		exit(84);
	for (int i = 0; s[i].name != NULL && i < 5; i++) {
		write(fd, s[i].scoreboard, my_strlen(s[i].scoreboard));
		if (s[i].scoreboard[my_strlen(s[i].scoreboard) - 1] != '\n')
			write(fd, "\n", 1);
	}
	close(fd);
}

void handle_highscore(int score, window_t *w, struct termios old)
{
	size_t len = 0;
	score_t s;
	score_t *scoreboard  = NULL;
	char *buffer = NULL;

	tcsetattr(0, TCSANOW, &old);
	erase_window(w);
	scoreboard = read_score_file();
	mvprintw(LINES / 2, COLS / 2, "Please enter your name\n");
	mvprintw(LINES / 2 + 1, COLS / 2, ">");
	refresh();
	getline(&buffer, &len, stdin);
	buffer[my_strlen(buffer) - 1] = 0;
	s = init_score(buffer);
	s.score = score;
	s.scoreboard = my_strcpy(s.scoreboard, buffer);
	s.scoreboard = my_strcat(s.scoreboard, " = ");
	s.scoreboard = my_strcat(s.scoreboard, my_put_score(score));
	scoreboard = compare_scoreboard(scoreboard, s);
	write_in_file(scoreboard, s);
}
