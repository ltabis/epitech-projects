/*
** EPITECH PROJECT, 2019
** tree_function_2.c
** File description:
** ok
*/

#include "simple_btree.h"

double btree_get_max_value(tree_t tree)
{
    double max_value = tree->value;
    double new_value = 0;

    if (btree_is_empty(tree) == TRUE)
        return (0);
    if (tree->right) {
        new_value = btree_get_max_value(tree->right);
        if (new_value > max_value)
            return (new_value);
    }
    if (tree->left) {
        new_value = btree_get_max_value(tree->left);
        if (new_value > max_value)
            return (new_value);
    }
    return (max_value);
}

double btree_get_min_value(tree_t tree)
{
    double min_value = tree->value;
    double new_value = 0;

    if (btree_is_empty(tree) == TRUE)
        return (0);
    if (tree->right) {
        new_value = btree_get_min_value(tree->right);
        if (new_value < min_value)
            min_value = new_value;
    }
    if (tree->left) {
        new_value = btree_get_min_value(tree->left);
        if (new_value < min_value)
            min_value = new_value;
    }
    return (min_value);
}
