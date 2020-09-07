/*
** EPITECH PROJECT, 2019
** lists_functions_2.c
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

bool_t list_add_elem_at_position(list_t *front_ptr, double elem, unsigned int
position)
{
    unsigned int size = list_get_size(*front_ptr);
    list_t new_node = NULL;
    list_t tmp = *front_ptr;

    if (list_is_empty(*front_ptr) == TRUE || position == 1) {
        if (list_add_elem_at_front(front_ptr, elem) == FALSE)
            return (FALSE);
    } else if (size == position) {
        if (list_add_elem_at_back(front_ptr, elem) == FALSE)
            return (FALSE);
    } else {
        new_node = malloc(sizeof(node_t));
        if (!new_node || size < position)
            return (FALSE);
        for (unsigned int i = 1; i < position - 1; i++, tmp = tmp->next);
        new_node->value = elem;
        new_node->next = tmp->next;
        tmp->next = new_node;
    }
    return (TRUE);
}

bool_t list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = NULL;

    if (!front_ptr || list_is_empty(*front_ptr) == TRUE)
        return (FALSE);
    tmp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return (TRUE);
}

bool_t list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = NULL;

    if (!front_ptr || !(*front_ptr) || list_is_empty(*front_ptr) == TRUE)
        return (FALSE);
    tmp = *front_ptr;
    for (; tmp->next && tmp->next->next; tmp = tmp->next);
    if (!tmp->next) {
        free(*front_ptr);
        *front_ptr = NULL;
        return (TRUE);
    }
    free(tmp->next);
    tmp->next = NULL;
    return (TRUE);
}

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    unsigned int size = list_get_size(*front_ptr);
    list_t tmp = *front_ptr;
    list_t tmp2 = NULL;

    if (list_is_empty(*front_ptr) == TRUE || position == 1 || size == 1) {
        if (list_del_elem_at_front(front_ptr) == FALSE)
            return (FALSE);
    } else if (size == position) {
        if (list_del_elem_at_back(front_ptr) == FALSE)
            return (FALSE);
    } else {
        if (size < position || position == 0)
            return (FALSE);
        for (unsigned int i = 1; i < position - 1; i++, tmp = tmp->next);
        tmp2 = tmp->next->next;
        free(tmp->next);
        tmp->next = tmp2;
    }
    return (TRUE);
}
