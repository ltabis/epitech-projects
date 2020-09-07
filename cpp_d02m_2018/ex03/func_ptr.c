/*
** EPITECH PROJECT, 2019
** func_ptr.c
** File description:
** ex03
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--)
        write(1, &str[i], 1);
    write(1, "\n", 1);
}

void print_upper(const char *str)
{
    for (unsigned int i = 0; str[i]; i++) {
        char tmp = str[i] >= 'a' && str[i] <= 'z' ? str[i] - 32 : str[i];
        write(1, &tmp, 1);
    }
    write(1, "\n", 1);
}

void print_42(__attribute__((unused)) const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    unsigned int i = 0;
    void (*choose_function[4])(const char *) = {print_normal,
    print_reverse, print_upper, print_42};
    action_t actions[4] = {PRINT_NORMAL, PRINT_REVERSE,
    PRINT_UPPER, PRINT_42};

    for (; actions[i] != action; i++);
    (*choose_function[i])(str);
}
