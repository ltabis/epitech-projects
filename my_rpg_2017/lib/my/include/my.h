/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header for utilities of libmy
*/

#define ERROR 84
#define UNUSED __attribute__((unused))

int my_getnbr(char const *str);
int my_ischar(char c);
int my_isdigit(char c);
int my_put_err(char *msg);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_memset(char *str, char cst , int size);
char *my_strcat(char *dest, char const *src);
char *my_strcpy (char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strncat(char *dest, char const *src, int n);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_tab(char *str);
void my_putchar(char c);
