/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/

#ifndef PROTO_H_
#define PROTO_H_

#define EXIT_SUCCESS 0
#define EXIT_FAIL 1
#define STOP 2
#define CONTINUE 0
#define NBR_DIRECT_VALUE 32
#define MAX_FORWARD 3010
#define CST ':'

typedef struct value_s {
	float left;
	float right;
	float left_max;
	float right_max;
	float middle;
} value_t;

int reset_directions(void);
int stop_car(void);
float get_time_value(char *);
void start_backtracking(void);
void get_time(void);
float search_turn_angle_exeption(value_t *, float);
char *my_strncpy(char *, char const *, int);
char **my_str_to_word_array(char *);
int is_closer(float, float, float);
void my_put_err(const char *);
int my_strlen(char const *);
int set_point(char *);
void fill_values(char **, value_t *);
void line_parser(char *, value_t *);

#endif /* !PROTO_H_ */
