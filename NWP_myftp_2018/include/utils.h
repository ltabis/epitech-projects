/*
** EPITECH PROJECT, 2019
** utils.h
** File description:
** utils functions header
*/

#ifndef UTILS_H_
#define UTILS_H_

/* macros */
#define EXIT_FAIL 84
#define EXIT_SUCCESS 0
#define USAGE 1

#define LOGGED 1
#define PASS 2
#define QUIT 3

#define CONNEXIONS 1024
#define MAX_PORT 65535

/* utils.c */
int puterr(const char *);
int check_arguments(int, const char * const *);
int print_usage(void);
int is_string_number(const char *);
void cut_command(char **, size_t);
char *my_itoa(int);
char *my_concat(char const *, char const *);

/* string_cleaning.c */
void my_clean_str(char *);

#endif /* !UTILS_H_ */
