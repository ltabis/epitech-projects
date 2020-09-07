/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** structur for the eval_expr project
*/
#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_stockage {
        int decal;
} stockage_t;

int do_summands(char *str);
int do_factors(char *str);
int do_product(char *str);
int evaluate_number(char *str);

#endif /* STRUCT_H_ */
