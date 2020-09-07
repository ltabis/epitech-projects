/*
** EPITECH PROJECT, 2019
** cpp_d02a
** File description:
** ex01
*/

#ifndef SIMPLE_BTREE_H_
#define SIMPLE_BTREE_H_

typedef enum bool_e
{
    FALSE,
    TRUE
} bool_t;

typedef struct node
{
    double value;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t *tree_t;

bool_t btree_is_empty(tree_t tree);
unsigned int btree_get_size(tree_t tree);
unsigned int btree_get_depth(tree_t tree);
bool_t btree_create_node(tree_t *root_ptr, double value);
bool_t btree_delete(tree_t *root_ptr);
double btree_get_max_value(tree_t tree);
double btree_get_min_value(tree_t tree);

#endif /* !SIMPLE_BTREE_H_ */
