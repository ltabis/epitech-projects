/*
** EPITECH PROJECT, 2019
** lists_functions_1.c
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "generic_list.h"

bool_t list_is_empty(list_t list)
{
    if (!list)
        return (TRUE);
    return (FALSE);
}

unsigned int list_get_size(list_t list)
{
    unsigned int len = 0;

    if (list_is_empty(list) == TRUE)
        return (0);
    for (; list->next; len++, list = list->next);
    return (len + 1);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    if (list_is_empty(list) == TRUE)
        return;
    for (; list->next; list = list->next)
        val_disp(list->value);
    val_disp(list->value);
}

bool_t list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new_ptr = malloc(sizeof(node_t));

    if (!new_ptr)
        return (FALSE);
    new_ptr->value = elem;
    new_ptr->next = *front_ptr;
    if (list_is_empty(*front_ptr) == TRUE) {
        *front_ptr = new_ptr;
        new_ptr->next = NULL;
        return (TRUE);
    }
    *front_ptr = new_ptr;
    return (TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new_ptr = malloc(sizeof(node_t));
    list_t tmp = *front_ptr;

    if (!new_ptr)
        return (FALSE);
    new_ptr->value = elem;
    new_ptr->next = NULL;
    if (list_is_empty(*front_ptr) == TRUE) {
        *front_ptr = new_ptr;
        return (TRUE);
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = new_ptr;
    return (TRUE);
}
