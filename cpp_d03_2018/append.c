/*
** EPITECH PROJECT, 2019
** append.c
** File description:
** append
*/

#include <string.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (!this || !ap || !ap->str)
        return;
    if (this->str) {
        this->str = realloc(this->str,
        sizeof(char) * (strlen(this->str) + strlen(ap->str) + 1));
        this->str = strcat(this->str, ap->str);
        return;
    }
    this->str = strdup(ap->str);
}

void append_c(string_t *this, const char *ap)
{
    if (!this || !ap)
        return;
    if (this->str) {
        this->str = realloc(this->str,
        sizeof(char) * (strlen(this->str) + strlen(ap) + 1));
        this->str = strcat(this->str, ap);
        return;
    }
    this->str = strdup(ap);
}
