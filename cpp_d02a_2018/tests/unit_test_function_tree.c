/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include  <criterion/criterion.h>
#include "simple_btree.h"

Test(tree, empty_tree)
{
    tree_t tree = NULL;

    cr_assert_eq(btree_is_empty(tree), TRUE);
    btree_create_node(&tree, 2);
    cr_assert_eq(btree_is_empty(tree), FALSE);
}

Test(tree, create_nodes_and_size)
{
    tree_t tree = NULL;

    cr_assert_eq(btree_create_node(&tree, 2), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left), 2), TRUE);
    cr_assert_eq(btree_create_node(&(tree->right), 3), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->right), 134), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->left), 53), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->right->left), 43), TRUE);
    cr_assert_eq(btree_get_size(tree), 6);

}

Test(tree, create_nodes_and_depth)
{
    tree_t tree = NULL;

    cr_assert_eq(btree_create_node(&tree, 2), TRUE);
    cr_assert_eq(btree_create_node(&(tree->right), 2), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left), 3), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->right), 134), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->right->right), 53), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->right->left), 43), TRUE);
    cr_assert_eq(btree_get_depth(tree), 4);
    cr_assert_eq(btree_delete(&tree), TRUE);
    cr_assert_neq(tree, NULL);
    cr_assert_neq(tree->right, NULL);
    cr_assert_neq(tree->left, NULL);
}

Test(tree, create_nodes_min_max)
{
    tree_t tree = NULL;

    cr_assert_eq(btree_create_node(&tree, 2), TRUE);
    cr_assert_eq(btree_create_node(&(tree->right), 2), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left), 3), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->right), 134), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->right->right), 53), TRUE);
    cr_assert_eq(btree_create_node(&(tree->left->right->left), 43), TRUE);
    cr_assert_eq(btree_get_max_value(tree), 134);
    cr_assert_eq(btree_get_min_value(tree), 2);
}
