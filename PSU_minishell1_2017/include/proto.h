/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/
#include <stdarg.h>
#ifndef PROTO_H_
#define PROTO_H_

#define STOP_SHELL 4
#define DISP_PATH  3

typedef struct env_s {
	char *env_name;
	char *env_value;
	struct env_s *next;
	struct env_s *prev;
} env_t;

void redirect_all_std(void);
char *get_next_line(int);
char *my_strcat(char *, char *);
char *my_strcat_2(char *, char *);
char *my_strcat_3(char *);
char *my_strcat_4(char *);
char *allocate_memory_at_initialisation(char *, int, int *);
char *pass_to_next_buffer(char *, int, char *, int *);
char *adv_buff(char *);
void my_printf(char *, ...);
int my_strcmp(char *, char *);
int my_strcmp_env(char *, char *);
char *my_strcpy(char *);
char *my_strcpy_special(char *);
void d_i(va_list);
void d_s(va_list);
void d_c(va_list);
void d_ex_down(va_list);
void d_ex_up(va_list);
void d_u(va_list);
void d_o(va_list);
void d_S(va_list);
void d_none(va_list);
void d_adr(va_list);
void d_b(va_list);
void d_4(va_list);
void d_6(va_list);
void d_8(va_list);
void d_ascii(va_list);
int find_flag(char *, int);
void my_put_nbr(int);
void my_putstr(char const *);
char *my_revstr(char *);
int my_strlen(char const *);
void my_putchar(char);
void main_loop(char **, env_t *);
int display_processus(env_t *, char **);
int check_processus_killed_or_env(char *);
void handle_signal(int);
char **cpy_env_variable(char **);
env_t *env_to_list(char **);
void load_variable_in_list(env_t **, char *);
void free_env_variable(env_t **);
void allocate_memory_env_name(env_t **, int);
void allocate_memory_env_value(env_t **, int);
void display_env_variables(env_t *);
char **free_path_variable(char **);
void search_exec(char *, char **, env_t *);
char **create_path_board(env_t *);
char **copy_paths_in_board(char *, char **, unsigned int);
char **build_args(char *);
char **copy_args(char *, char **, unsigned int);
char *copy_string_args(char *, char *, unsigned int *);
char *copy_string_in_board(char *, char *, unsigned int *);
char *transform_str(char *);
void start_forking(char **, env_t *);
char **convert_list_into_board(env_t *);
char **list_to_board(env_t *, char **, unsigned int);
void add_or_remove_env_variable(env_t **, char *);
void my_perror_command(char *);
void add_name_to_list(env_t **, char *);
void replace_name(env_t **, char *);
int change_name_in_env(env_t **, char *);
int change_name_and_variable_in_env(env_t **, char *);
void add_name_and_value_to_list(env_t **, char *, char *);
void replace_name_and_value(env_t **, char *, char *);
void add_variable(env_t **, char *);
void remove_variable(env_t **, char *);
void delete_env_variables(env_t **, char *);
void delete_variable(env_t **, char *);
void found_variable_to_delete(env_t **);
void variable_in_middle_of_list(env_t **);
int check_alphanumeric_variable(char *);
void launch_cd(char *, env_t **);
int check_path(char *, env_t **);
char *organize_str(char *, int);
void get_back_to_home(env_t **);
void get_back_to_previous_location(env_t **);
void initialise_old_pwd_variable(env_t **);
void add_old_pwd(env_t **);
int check_file_stat(char *);

#endif /* !PROTO_H_ */
