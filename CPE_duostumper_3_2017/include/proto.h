/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** prototypes for stumper
*/

#ifndef PROTO_H_
#define PROTO_H_

#define READ_SIZE 1024

typedef struct options_s {
	char *c_arg;
	char *f_arg;
	char d_arg;
} options_t;

void compute_fields(options_t *, char *);
void search_fieds_to_display(options_t *, char *, unsigned int, char *);
char *advance_buffer(char *);
int my_getnbr(const char *, int);
char *advance_buffer(char *);
char *get_input(void);
char *my_strcat(const char *, const char *);
char *my_strncat(const char *, const char *, unsigned int);
char *my_strndup(const char *, unsigned int);
char *my_strdup(const char *);
void get_parameters(options_t *options, int ret);
int check_invalid_string_argument(int);
int check_invalid_characters(int);
unsigned int my_strlen(const char *);
options_t *create_options_struct(void);
options_t *execute_parsing(int, char * const *);
int check_params(int);

#endif /* !PROTO_H_ */
