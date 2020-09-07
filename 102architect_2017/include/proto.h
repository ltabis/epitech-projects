/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for the 102architect project
*/
#ifndef PROTO_H_
#define PROTO_H_

int main(int, char **);
int my_getnbr(char *);
void how_to_use(void);
float **do_translation(int, int);
float **do_homothety(int, int);
float **do_rotation(int);
float **do_symmetry(int);
float **multiply_matrix(int **, int **);
float calculate_vector_x(int, int, float **);
float calculate_vector_y(int, int, float **);
float **calculate_result(float **, float **);

#endif /* !PROTO_H_ */
