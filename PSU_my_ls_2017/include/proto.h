/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/
#include <sys/stat.h>
#include <sys/types.h>
#include "mystruct.h"

#ifndef PROTO_H_
#define PROTO_H_

int main(int, char **);
char *concat_params(char *, char *);
void disp_files(char *, stock_t *);
void display_time(struct stat);
void conditions_option_d(char *, stock_t *);
void execute_ternaries(struct stat);
void display_dash_l(char *, char *);
void display_spaces_files(stock_t *);
void display_total(char *);
void disp_files_advanced(char *, stock_t *);
void check_option_d(char **, int, stock_t *);
void conditions_option_R(char **, stock_t *);
stock_t *free_ressources(stock_t *);
stock_t *choose_options(char *, stock_t *);
stock_t *search_options(char **, stock_t *);
stock_t *check_option_R(char **, stock_t *);
stock_t *put_options(char, stock_t *, char *, unsigned int);
stock_t *parse_my_ls(char **, stock_t *);
unsigned int verify_dash_l(unsigned int, char **, stock_t *);
unsigned int verify_dash_l_one_folder(unsigned int, char **, stock_t *);

#endif /* !PROTO_H_ */
