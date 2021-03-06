/*
** EPITECH PROJECT, 2019
** lists_functions_3.c
** File description:
** ex00
*/

#include <stdlib.h>
#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    if (list_is_empty(list) == TRUE)
        return (FALSE);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    if (list_is_empty(list) == TRUE)
        return (FALSE);
    for (; list->next; list = list->next);
    return (list->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int size = list_get_size(list);

    if (list_is_empty(list) == TRUE || size < position)
        return (0);
    if (position == 0)
        return (list->value);
    for (unsigned int i; i < position; i++, list = list->next);
    return (list->value);
}

void list_clear(list_t *front)
{
    list_t prev = *front;

    for (; (*front)->next; *front = (*front)->next) {
        free(prev);
        prev = *front;
    }
    *front = NULL;
}

node_t *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    if (list_is_empty(list) == TRUE)
        return (NULL);
    for (; list->next; list = list->next)
        if (val_comp(list->value, value) == 0)
            return (list);
    if (val_comp(list->value, value) == 0)
        return (list);
    return (NULL);
}
