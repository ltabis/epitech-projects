/*
** EPITECH PROJECT, 2019
** tree_functions_1.c
** File description:
** tree
*/

#include <stdlib.h>
#include "simple_btree.h"

bool_t btree_is_empty(tree_t tree)
{
    if (!tree)
        return (TRUE);
    return (FALSE);
}

unsigned int btree_get_size(tree_t tree)
{
    unsigned int nodes = 1;

    if (btree_is_empty(tree) == TRUE)
        return (0);
    if (tree->right)
        nodes += btree_get_size(tree->right);
    if (tree->left)
        nodes += btree_get_size(tree->left);
    if (!tree->right && !tree->left)
        return (1);
    return (nodes);
}

unsigned int btree_get_depth(tree_t tree)
{
    unsigned int depth_left = 0;
    unsigned int depth_right = 0;

    if (btree_is_empty(tree) == TRUE)
        return (0);
    if (tree->right)
        depth_right = btree_get_depth(tree->right) + 1;
    if (tree->left)
        depth_left = btree_get_depth(tree->left) + 1;
    if (!tree->right && !tree->left)
        return (1);
    return (depth_left > depth_right ? depth_left : depth_right);
}

bool_t btree_create_node(tree_t *node_ptr, double value)
{
    tree_t new_node = malloc(sizeof(node_t));

    if (!new_node)
        return (FALSE);
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = value;
    *node_ptr = new_node;
    return (TRUE);
}

bool_t btree_delete(tree_t *root_ptr)
{
    if (btree_is_empty(*root_ptr) == TRUE)
        return (FALSE);
    if ((*root_ptr)->right)
        if (btree_delete(&(*root_ptr)->right) == FALSE)
            return (FALSE);
    if ((*root_ptr)->left)
        if (btree_delete(&(*root_ptr)->left) == FALSE)
            return (FALSE);
    free(*root_ptr);
    return (TRUE);
}
