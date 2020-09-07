/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** prototypes for a particular program
*/

#ifndef PROTO_H_
#define PROTO_H_

float **calcul_deter(float **, int);
void error_handling(int, char **);
int do_encryption(char *, char *);
int do_decipherment(char *, char *);
int **create_key_matrix(char *, unsigned int);
int **create_message_matrix(char *, unsigned int, unsigned int);
int **encrypt_msg(int **,int **, unsigned int, unsigned int);
int do_decipherment(char *, char *);
float **inv_matrix(float **, float);
float determinant_3(float **);
float **transposee(float **);
float **fill_matrix(float **);
float **co_matrix(float **);
void print_matrix(float **);
float determinant_2(float, float, float, float);

#endif /* !PROTO_H_ */
