/*
** EPITECH PROJECT, 2017
** string.h
** File description:
** prototypes
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>

typedef struct s_string {
    char *str;
    void (*string_init)(struct s_string *this, const char *s);
    void (*string_destroy)(struct s_string *this);
    void (*assign_s)(struct s_string *this, const struct s_string *str);
    void (*assign_c)(struct s_string *this, const char *s);
    void (*append_s)(struct s_string *this, const struct s_string *ap);
    void (*append_c)(struct s_string *this, const char *ap);
    char (*at)(const struct s_string *this, size_t pos);
    void (*clear)(struct s_string *this);
    int (*size)(const struct s_string *this);
    int (*compare_s)(const struct s_string *this, const struct s_string *str);
    int (*compare_c)(const struct s_string *this, const char *str);
    size_t (*copy)(const struct s_string *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct s_string *this);
    int (*empty)(const struct s_string *this);
    int (*find_s)(const struct s_string *this,
    const struct s_string *str, size_t pos);
    int (*find_c)(const struct s_string *this, const char *str, size_t pos);
    void (*insert_c)(struct s_string *this, size_t pos, const char *str);
    void (*insert_s)(struct s_string *this, size_t pos, struct s_string *str);
    int (*to_int)(const struct s_string *this);
    struct s_string **(*split_s)(const struct s_string *this, char separator);
    char **(*split_c)(const struct s_string *this, char separator);
} string_t;

void string_init(string_t *this, const char *s);
void string_init_next(string_t *this);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, string_t *str);
int to_int(const string_t *this);
string_t **split_s(const string_t *this, char separator);
char **split_c(const string_t *this, char separator);
unsigned int count_word(char *tmp, char separator);
char allocate_space(string_t **elem, char **tmp, char separator);
char allocate_space_char(char **elem, char **tmp, char separator);

#endif /* !STRING_H_ */
