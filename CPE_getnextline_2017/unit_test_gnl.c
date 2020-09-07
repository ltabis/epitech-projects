/*
** EPITECH PROJECT, 2018
** unit_test_gnl.c
** File description:
** unit testing for the gnl project
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int);
char *my_strcat(char *, char *);
char *allocate_memory_at_initialisation(char *, int, int *);
char *pass_to_next_buffer(char *, int, char *, int *);
char *adv_buff(char *);
int fd =  -1;

void open_file(void)
{
	fd = open("test", O_RDONLY);
	cr_redirect_stdout();
}

void close_file(void)
{
	if (fd != -1)
		close(fd);
}

Test(get_next_line, read_line, .init = open_file, .fini = close_file)
{
	char *expected = "Je suis un test";
	char *got = get_next_line(fd);

	cr_assert_str_eq(got, expected);
}

Test(get_next_line, read_few_lines, .init = open_file , .fini = close_file)
{
	char *expected1 = "Je suis un test";
	char *expected2 = "Lis moi stp je suis si seul au monde ;_;";
	char *expected3 = "gros espaces";
	char *got1 = get_next_line(fd);
	char *got2 = get_next_line(fd);
	char *got3 = get_next_line(fd);

	cr_assert_str_eq(got1, expected1);
	cr_assert_str_eq(got2, expected2);
	cr_assert_str_eq(got3, expected3);
	free(got1);
	free(got2);
	free(got3);
}

Test(get_next_line, concat_params_function)
{
	char *s3 = my_strcat("je suis ", "un test !");
	char *s4 = "je suis un test !";

	cr_assert_str_eq(s3, s4);
}
