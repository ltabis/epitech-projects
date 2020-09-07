/*
** EPITECH PROJECT, 2019
** functions 1 test
** File description:
** tests
*/

#include  <criterion/criterion.h>
#include "simple_list.h"

Test(lists, empty_list)
{
    list_t list = NULL;

    cr_assert_eq(list_is_empty(list), TRUE);
    list_add_elem_at_front(&list, 2);
    cr_assert_eq(list_is_empty(list), FALSE);
}

Test(lists, adding_elem)
{
    list_t list = NULL;
    double responses[6] = {1, 432, 1, 324, 42.09, 42.09};

    cr_assert_eq(list_add_elem_at_front(&list, 432), TRUE);
    cr_assert_eq(list_add_elem_at_front(&list, 1), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 1), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 324), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 42.09), TRUE);
    cr_assert_eq(list_add_elem_at_position(&list, 42.09, 5), TRUE);
    cr_assert_eq(list_add_elem_at_position(&list, 42.09, 10), FALSE);
    for (unsigned int i = 0; list->next; list = list->next, i++)
        cr_assert_eq(list->value, responses[i]);
}

Test(lists, delete_elem)
{
    list_t list = NULL;

    cr_assert_eq(list_add_elem_at_front(&list, 432), TRUE);
    cr_assert_eq(list_add_elem_at_front(&list, 1), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 1), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 324), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 42.09), TRUE);
    cr_assert_eq(list_add_elem_at_position(&list, 42.09, 5), TRUE);
    cr_assert_eq(list_add_elem_at_position(&list, 42.09, 10), FALSE);
    cr_assert_eq(list_del_elem_at_position(&list, 4242), FALSE);
    cr_assert_eq(list_del_elem_at_position(&list, -1), FALSE);
    cr_assert_eq(list_del_elem_at_front(&list), TRUE);
    cr_assert_eq(list_del_elem_at_front(&list), TRUE);
    cr_assert_eq(list_del_elem_at_back(&list), TRUE);
    cr_assert_eq(list_del_elem_at_back(&list), TRUE);
    cr_assert_eq(list_del_elem_at_back(&list), TRUE);
    cr_assert_eq(list_del_elem_at_back(&list), TRUE);
    cr_assert_eq(list_del_elem_at_back(&list), FALSE);
    cr_assert_eq(list, NULL);
}

Test(lists, size_list)
{
    list_t list = NULL;

    cr_assert_eq(list_add_elem_at_front(&list, 432), TRUE);
    cr_assert_eq(list_add_elem_at_front(&list, 1), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 1), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 324), TRUE);
    cr_assert_eq(list_add_elem_at_back(&list, 42.09), TRUE);
    cr_assert_eq(list_add_elem_at_position(&list, 42.09, 5), TRUE);
    cr_assert_eq(list_add_elem_at_position(&list, 42.09, 10), FALSE);
    cr_assert_eq(list_get_size(list), 6);
}
