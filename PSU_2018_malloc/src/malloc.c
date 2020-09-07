/*
** EPITECH PROJECT, 2019
** malloc.hpp
** File description:
** malloc class
*/

#include <memory.h>
#include "my.h"

data_t data = {NULL, NULL, PTHREAD_MUTEX_INITIALIZER};

header_t *construct_head(size_t size, void *ptr)
{
    header_t *new_index = ptr;

    new_index->size = size;
    new_index->free = -1;
    return (new_index);
}

void *check_free_block(size_t size)
{
    for (header_t *header = data.head;
    header != data.brk;
    header = (header_t *)((void *)header + header->size + sizeof(header_t))) {
        if (header->size >= size && header->free == 1) {
            header->free = 0;
            return ((void *)header + sizeof(header_t));
        }
    }
    return (NULL);
}

void *malloc(size_t size)
{
    header_t *new_allocation = NULL;

    if (size <= 0)
        return (NULL);
    pthread_mutex_lock(&data.m_lock);
    size = size % ROUND == 0 ? size : size + ROUND - (size % ROUND);
    if (!data.head) {
        data.head = construct_head(size, sbrk(sizeof(header_t) + size));
        data.brk = (void *)data.head + data.head->size + sizeof(header_t);
        pthread_mutex_unlock(&data.m_lock);
        return ((void *)data.head + sizeof(header_t));
    } else if (!(new_allocation = check_free_block(size))) {
        new_allocation = (header_t *)sbrk(sizeof(header_t) + size);
        new_allocation->free = -1;
        new_allocation->size = size;
        data.brk = (void *)new_allocation + sizeof(header_t) + size;
        pthread_mutex_unlock(&data.m_lock);
        return ((void *)new_allocation + sizeof(header_t));
    }
    pthread_mutex_unlock(&data.m_lock);
    return (new_allocation);
}

void free(void *ptr)
{
    header_t *header = NULL;

    if (!ptr || !data.head)
        return;
    pthread_mutex_lock(&data.m_lock);
    header = (header_t *)(ptr - sizeof(header_t));
    header->free = 1;
    for (; header != data.brk;
    header = (header_t *)((void *)header + header->size + sizeof(header_t))) {
        if (header->free != 1) {
            pthread_mutex_unlock(&data.m_lock);
            return;
        }
    }
    if (brk(ptr - sizeof(header_t)) == -1) {
        pthread_mutex_unlock(&data.m_lock);
        return;
    }
    data.brk = ptr - sizeof(header_t);
    pthread_mutex_unlock(&data.m_lock);
}

void *realloc(void *ptr, size_t size)
{
    header_t *header = NULL;
    void *new_allocation = NULL;

    if (!ptr || size == 0) {
        return (malloc(size));
    }
    header = ptr - sizeof(header_t);
    if (header->size >= size) {
        return (ptr);
    }
    if ((new_allocation = malloc(size))) {
        header->free = 1;
        memcpy(new_allocation, header, size);
        return (new_allocation);
    }
    return (NULL);
}
