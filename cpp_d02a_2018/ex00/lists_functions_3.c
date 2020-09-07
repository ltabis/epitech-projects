/*
** EPITECH PROJECT, 2019
** lists_functions_3.c
** File description:
** ex00
*/

#include <stdlib.h>
#include "simple_list.h"

double list_get_elem_at_front(list_t list)
{
    if (list_is_empty(list) == TRUE)
        return (FALSE);
    return (list->value);
}

double list_get_elem_at_back(list_t list)
{
    if (list_is_empty(list) == TRUE)
        return (FALSE);
    for (; list->next; list = list->next);
    return (list->value);
}

double list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int size = list_get_size(list);

    if (list_is_empty(list) == TRUE || size < position)
        return (0);
    if (position == 0)
        return (list->value);
    for (unsigned int i; i < position; i++, list = list->next);
    return (list->value);
}

node_t *list_get_first_node_with_value(list_t list, double value)
{
    if (list_is_empty(list) == TRUE)
        return (NULL);
    for (; list->next; list = list->next)
        if (list->value == value)
            return (list);
    if (list->value == value)
        return (list);
    return (NULL);
}
