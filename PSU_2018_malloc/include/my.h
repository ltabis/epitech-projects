/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** malloc header
*/

#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

#define ROUND 4

typedef struct s_header {
    size_t size;
    char free;
} header_t;

typedef struct s_data {
    header_t *head;
    void *brk;
    pthread_mutex_t m_lock;
} data_t;

void *malloc(size_t);
void free(void *);
void *realloc(void *, size_t);
void *calloc(size_t, size_t);
void show_alloc_mem(data_t data);
void put_ptr(uintptr_t ptr);
void my_putstr(char const *str);
void my_putchar(char c);