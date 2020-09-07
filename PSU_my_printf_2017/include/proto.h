/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for the project
*/
#include <stdarg.h>
#ifndef PROTO_H_
#define PROTO_H_

int main(void);
int my_printf(char *, ...);
void d_i(char *, va_list);
void d_s(char *, va_list);
void d_c(char *, va_list);
void d_ex_down(char *, va_list);
void d_ex_up(char *, va_list);
void d_u(char *, va_list);
void d_o(char *, va_list);
void d_S(char *, va_list);
void d_none(char *, va_list);
void d_adr(char *, va_list);
void d_b(char *, va_list);
void d_4(char *, va_list);
void d_6(char *, va_list);
void d_8(char *, va_list);
void d_ascii(char *, va_list);
int find_flag(char *, int);
void (*chooseFlag[16])(char *, va_list);

#endif /* !PROTO_H_ */
