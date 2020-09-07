/*
** EPITECH PROJECT, 2018
** unit_test_gnl_2.c
** File description:
** unit_testing part 2
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
void  open_file(void);
void  close_file(void);
int fd;

Test(get_next_line_2, check_initilialisation, .init = open_file,
.fini = close_file)
{
	char *buff = NULL;
	int rd = 0;

	buff = allocate_memory_at_initialisation(buff, fd, &rd);
	free(buff);
	cr_assert_neq(rd, 0);
}

Test(get_next_line_2, advance_the_buffer, .init = open_file,
.fini = close_file)
{
	char *buff = "I'm a test!";

	buff = adv_buff(buff);
	cr_assert_neq(buff[0], 0);
}

Test(get_next_line_2, error_handling)
{
	char *s;
	int file_descriptor = -1;

	s = get_next_line(file_descriptor);
	cr_assert_eq(s, NULL);
}

Test(get_next_line_2, read_entire_file, .init = open_file, .fini = close_file)
{
	char *s = get_next_line(fd);

	while (s) {
		cr_assert_neq(s, NULL);
		free(s);
		s = get_next_line(fd);
	}
	cr_assert_eq(s, NULL);
}
