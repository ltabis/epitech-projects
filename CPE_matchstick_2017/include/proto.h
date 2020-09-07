/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/

#ifndef PROTO_H_
#define PROTO_H_

#define  READ_SIZE 10

typedef struct matches_s {
	int line;
	int matches;
} matches_t;

void redirect_all_std(void);
char *get_next_line(int);
char *my_strcat(char *, char *);
char *allocate_memory_at_initialisation(char *, int, int *);
char *pass_to_next_buffer(int, char *, int *);
char *adv_buff(char *);
unsigned char *create_game_board(unsigned int);
unsigned char *fill_board(unsigned int, unsigned int, unsigned char *);
int check_params(char *, char *);
int main_loop(unsigned char *, unsigned int, unsigned int);
int create_game_environnement(char *, char *);
void display_board(unsigned char *, unsigned int);
int display_prompt(unsigned int, unsigned int, unsigned char **);
void display_info(unsigned int, unsigned int);
void display_matches(unsigned char *, unsigned int);
int check_prompt_content(unsigned int, char *, int, unsigned int);
int process_gameplay(unsigned char **, int, int, unsigned int);
int process_ia_turn(unsigned char **, unsigned int, unsigned int);
int check_if_win_or_lose(unsigned char *, unsigned int, int);
matches_t compute_algorithme(unsigned char **, unsigned int, 
	unsigned int, matches_t);
matches_t trap_player(unsigned char **, unsigned int, unsigned int);
int count_matchs_remaining(unsigned char **, unsigned int);
matches_t retreive_one_match(unsigned char **, unsigned int);
void my_put_nbr(int);
int my_getnbr(char *);
int my_strlen(char *);
void my_putchar(int);
char *my_revstr(char *);
unsigned char *my_strcpy(unsigned char *, unsigned int);

#endif /* !PROTO_H_ */
