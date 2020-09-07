/*
** EPITECH PROJECT, 2019
** my_string.c
** File description:
** string object
*/

#include <string.h>
#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (!this || !s)
        return;
    this->str = strdup(s);
    if (!this->str)
        return;
    this->string_init = &string_init;
    this->string_destroy = &string_destroy;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    string_init_next(this);
}

void string_init_next(string_t *this)
{
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_s = &insert_s;
    this->insert_c = &insert_c;
    this->to_int = &to_int;
    this->split_s = &split_s;
    this->split_c = &split_c;
}

void string_destroy(string_t *this)
{
    if (!this || !this->str)
        return;
    free(this->str);
}
