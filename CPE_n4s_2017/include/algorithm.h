/*
** EPITECH PROJECT, 2018
** algorithm.h
** File description:
** algorithm prototypes
*/

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "../include/proto.h"

char *get_last_info(void);
int check_end_of_race(char *, int);
int check_message_from_vrep(char *);
int execute_main_algoritm(void);
int parse_error(int);
int car_speed(float);
int select_way_to_go(value_t *);

#endif /* !ALGORITHM_H_ */
