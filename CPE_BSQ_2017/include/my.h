/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** task02 Day09
*/
#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swape(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_in_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(char *, ...);
void d_i(char *, va_list);
void d_s(char *, va_list);
void d_c(char *, va_list);
void d_ex(char *, va_list);
void d_ex_up(char *, va_list);
void d_u(char *, va_list);
void d_o(char *, va_list);
void d_ss(char *, va_list);
void d_none(char *, va_list);
void d_adr(char *, va_list);
void d_b(char *, va_list);
void d_4(char *, va_list);
void d_6(char *, va_list);
void d_8(char *, va_list);
void d_ascii(char *, va_list);
int find_flag(char *, int);
void (*chooseFlag[16])(char *, va_list);

#endif /* !MY_H_ */
